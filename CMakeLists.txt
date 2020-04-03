cmake_minimum_required(VERSION 2.8.8 FATAL_ERROR)
project(libtoontown)

SET(BUILD_STATIC_LIB OFF CACHE BOOL "If true, will build a static lib")

set(Python_USE_STATIC_LIBS ${BUILD_STATIC_LIB})

set(PYTHON_VERSION "" CACHE STRING "Optional user-selected Python version")
if(PYTHON_VERSION)
  find_package(Python ${PYTHON_VERSION} EXACT COMPONENTS Interpreter Development REQUIRED)
else()
  find_package(Python COMPONENTS Interpreter Development REQUIRED)
endif()

if(NOT Python_FOUND)
    message(FATAL_ERROR "Python not found.")
endif()

find_package(PythonInterp)
if(NOT PYTHONINTERP_FOUND)
    message(FATAL_ERROR "Python interpreter not found.")
endif()

if(PYTHON_VERSION_MAJOR EQUAL 2)
    set(PYTHON2_EXECUTABLE "${PYTHON_EXECUTABLE}")
else()
    set(PYTHON2_EXECUTABLE python2)
endif()

### Panda3D dir ###
if(APPLE)
    SET(PANDA_DIR "/Developer/Panda3D" CACHE STRING "Panda3D directory.")
endif()
if(WIN32)
    SET(PANDA_DIR "C:/Panda3D-1.11.0-x64-astron" CACHE STRING "Panda3D directory.")
endif()
execute_process(COMMAND ${PYTHON2_EXECUTABLE} "${CMAKE_SOURCE_DIR}/src/run_interrogate.py" "${PANDA_DIR}")

### Define core components ###
set(DNALOADER_FILES
    src/dnaLoader/dnabase.h
    src/dnaLoader/config_dna.cxx
    src/dnaLoader/config_dna.h
    src/dnaLoader/LoaderFileTypeDNA.cxx
    src/dnaLoader/LoaderFileTypeDNA.h
    src/dnaLoader/DNAAnimProp.cxx
    src/dnaLoader/DNAAnimProp.h
    src/dnaLoader/DNABattleCell.cxx
    src/dnaLoader/DNABattleCell.h
    src/dnaLoader/DNADoor.cxx
    src/dnaLoader/DNADoor.h
    src/dnaLoader/DNAFlatDoor.cxx
    src/dnaLoader/DNAFlatDoor.h
    src/dnaLoader/DNAGroup.cxx
    src/dnaLoader/DNAGroup.h
    src/dnaLoader/DNAInteractiveProp.cxx
    src/dnaLoader/DNAInteractiveProp.h
    src/dnaLoader/DNALandmarkBuilding.cxx
    src/dnaLoader/DNALandmarkBuilding.h
    src/dnaLoader/DNANode.cxx
    src/dnaLoader/DNANode.h
    src/dnaLoader/DNAProp.cxx
    src/dnaLoader/DNAProp.h
    src/dnaLoader/DNAStorage.cxx
    src/dnaLoader/DNAStorage.h
    src/dnaLoader/DNAStreet.cxx
    src/dnaLoader/DNAStreet.h
    src/dnaLoader/DNASuitEdge.cxx
    src/dnaLoader/DNASuitEdge.h
    src/dnaLoader/DNASuitPath.cxx
    src/dnaLoader/DNASuitPath.h
    src/dnaLoader/DNASuitPoint.cxx
    src/dnaLoader/DNASuitPoint.h
    src/dnaLoader/DNAVisGroup.cxx
    src/dnaLoader/DNAVisGroup.h
)

set(SUIT_FILES
    src/suit/SuitLeg.cxx
    src/suit/SuitLeg.h
)

set(IGATE_FILES
    src/dnaLoader_igate.cxx
    src/suit_igate.cxx
    src/libtoontown_module.cxx
)

include_directories(src/base)
include_directories(src/dnaLoader)
include_directories(src/suit)
include_directories(${PANDA_DIR}/include)
include_directories(${Python_INCLUDE_DIRS})
include_directories(/usr/include/eigen3)
link_directories(${PANDA_DIR}/lib)

set(LIBPFX "")
if(MSVC)
    set(LIBPFX "lib")
    add_definitions(/wd4275)
    add_definitions(/DYY_NO_UNISTD_H)
endif()

if(CMAKE_CXX_COMPILER_ID MATCHES "GNU")
    execute_process(COMMAND "${CMAKE_C_COMPILER}" -dumpversion OUTPUT_VARIABLE GCC_VERSION)
    message(STATUS "GCC Version: ${GCC_VERSION}")
    if(GCC_VERSION VERSION_GREATER 4.7 OR GCC_VERSION VERSION_EQUAL 4.7)
        add_definitions(-std=c++11) # Enable the new C++ standard
    else()
        add_definitions(-std=c++0x) # Enable the new C++ standard
    endif()

    add_definitions(-Wno-ignored-attributes -Wno-deprecated-declarations -Wno-misleading-indentation)
elseif(CMAKE_CXX_COMPILER_ID MATCHES "Clang")
    execute_process(COMMAND "${CMAKE_C_COMPILER}" -dumpversion OUTPUT_VARIABLE CLANG_VERSION)
    message(STATUS "Clang Version: ${CLANG_VERSION}")
    add_definitions(-std=c++11) # Enable the new C++ standard
    add_definitions(-Wno-ignored-attributes -Wno-deprecated-declarations)
endif()

add_definitions(-DBUILDING_DNA)

if(NOT BUILD_STATIC_LIB)
    set(PANDA_LIBS
        ${LIBPFX}p3framework
        ${LIBPFX}panda
        ${LIBPFX}pandafx
        ${LIBPFX}pandaexpress
        ${LIBPFX}p3dtool
        ${LIBPFX}p3dtoolconfig
        ${LIBPFX}p3direct
    )

    # Add p3interrogatedb, if it exists
    find_library(HAVE_P3INTERROGATEDB
                 ${LIBPFX}p3interrogatedb
                 HINTS ${PANDA_DIR}/lib)

    if(HAVE_P3INTERROGATEDB)
        message(STATUS "libp3interrogatedb found")
        LIST(APPEND PANDA_LIBS ${LIBPFX}p3interrogatedb)
    else()
        message(STATUS "libp3interrogatedb not found")
    endif()

    # Add p3pandatoolbase, if it exists
    find_library(HAVE_P3PANDATOOLBASE
                 ${LIBPFX}p3pandatoolbase
                 HINTS ${PANDA_DIR}/lib)

    if(HAVE_P3PANDATOOLBASE)
        message(STATUS "libp3pandatoolbase found")
        LIST(APPEND PANDA_LIBS ${LIBPFX}p3pandatoolbase)
    else()
        message(STATUS "libp3pandatoolbase not found")
    endif()

    if(WIN32)
        add_library(libtoontown SHARED
            ${DNALOADER_FILES}
            ${SUIT_FILES}
            ${IGATE_FILES}
        )
        SET_TARGET_PROPERTIES(libtoontown PROPERTIES SUFFIX ".pyd")
        target_link_libraries(libtoontown ${PANDA_LIBS} ${Python_LIBRARIES})
        add_custom_command(TARGET libtoontown
                           PRE_BUILD
                           COMMAND ${PYTHON2_EXECUTABLE} "${CMAKE_SOURCE_DIR}/src/run_interrogate.py" "${PANDA_DIR}"
                           COMMENT "Interrogate")

    else()
        add_library(toontown MODULE
            ${DNALOADER_FILES}
            ${SUIT_FILES}
            ${IGATE_FILES}
        )
        target_link_libraries(toontown ${PANDA_LIBS} ${Python_LIBRARIES})
        add_custom_command(TARGET toontown
                           PRE_BUILD
                           COMMAND ${PYTHON2_EXECUTABLE} "${CMAKE_SOURCE_DIR}/src/run_interrogate.py" "${PANDA_DIR}"
                           COMMENT "Interrogate")
    endif()

else()

    if(WIN32)
        add_library(libtoontown STATIC
            ${DNALOADER_FILES}
            ${SUIT_FILES}
            ${IGATE_FILES}
        )
        add_custom_command(TARGET libtoontown
                           PRE_BUILD
                           COMMAND ${PYTHON2_EXECUTABLE} "${CMAKE_SOURCE_DIR}/src/run_interrogate.py" "${PANDA_DIR}"
                           COMMENT "Interrogate")

    else()
        add_library(toontown STATIC
            ${DNALOADER_FILES}
            ${SUIT_FILES}
            ${IGATE_FILES}
        )
        add_custom_command(TARGET toontown
                           PRE_BUILD
                           COMMAND ${PYTHON2_EXECUTABLE} "${CMAKE_SOURCE_DIR}/src/run_interrogate.py" "${PANDA_DIR}"
                           COMMENT "Interrogate")
    endif()

endif()

### Setup source groups and defines for configurables ###
source_group("dnaLoader" FILES ${DNALOADER_FILES})
source_group("suit" FILES ${SUIT_FILES})
source_group("interrogate_files" FILES ${IGATE_FILES})