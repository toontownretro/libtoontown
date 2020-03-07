cmake_minimum_required(VERSION 2.8.8 FATAL_ERROR)
project(libtoontown)

find_package(PythonLibs)
if(NOT PYTHONLIBS_FOUND)
    message(FATAL_ERROR "Python libs not found.")
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
    SET(PANDA_DIR "C:/Panda3D-1.11.0" CACHE STRING "Panda3D directory.")
endif()
SET(BUILD_STATIC_LIB OFF CACHE BOOL "If true, will build a static lib")
execute_process(COMMAND ${PYTHON2_EXECUTABLE} "${CMAKE_SOURCE_DIR}/src/run_interrogate.py" "${PANDA_DIR}")

### Define core components ###
set(BASE_FILES
    src/base/dnabase.h
    src/base/config_dna.h
    src/base/config_dna.cxx
)

set(COMPONENTS_FILES
    src/components/DNABattleCell.cxx
    src/components/DNABattleCell.h
    src/components/DNAGroup.cxx
    src/components/DNAGroup.h
    src/components/DNANode.cxx
    src/components/DNANode.h
    src/components/DNAProp.cxx
    src/components/DNAProp.h
    src/components/DNAStorage.cxx
    src/components/DNAStorage.h
    src/components/DNASuitEdge.cxx
    src/components/DNASuitEdge.h
    src/components/DNASuitPath.cxx
    src/components/DNASuitPath.h
    src/components/DNASuitPoint.cxx
    src/components/DNASuitPoint.h
)

set(IGATE_FILES
    src/base_igate.cxx
    src/components_igate.cxx
    src/libtoontown_module.cxx
)

include_directories(src/base)
include_directories(src/components)
include_directories(${PANDA_DIR}/include)
include_directories(${PYTHON_INCLUDE_DIR})
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
            ${BASE_FILES}
            ${COMPONENTS_FILES}
            ${IGATE_FILES}
        )
        SET_TARGET_PROPERTIES(libtoontown PROPERTIES SUFFIX ".pyd")
        target_link_libraries(libtoontown ${PANDA_LIBS} ${PYTHON_LIBRARY})
        add_custom_command(TARGET libtoontown
                           PRE_BUILD
                           COMMAND ${PYTHON2_EXECUTABLE} "${CMAKE_SOURCE_DIR}/src/run_interrogate.py" "${PANDA_DIR}"
                           COMMENT "Interrogate")

    else()
        add_library(toontown MODULE
            ${BASE_FILES}
            ${COMPONENTS_FILES}
            ${IGATE_FILES}
        )
        target_link_libraries(toontown ${PANDA_LIBS} ${PYTHON_LIBRARY})
        add_custom_command(TARGET toontown
                           PRE_BUILD
                           COMMAND ${PYTHON2_EXECUTABLE} "${CMAKE_SOURCE_DIR}/src/run_interrogate.py" "${PANDA_DIR}"
                           COMMENT "Interrogate")
    endif()

else()

    if(WIN32)
        add_library(libtoontown STATIC
            ${BASE_FILES}
            ${COMPONENTS_FILES}
            ${IGATE_FILES}
        )
        add_custom_command(TARGET libtoontown
                           PRE_BUILD
                           COMMAND ${PYTHON2_EXECUTABLE} "${CMAKE_SOURCE_DIR}/src/run_interrogate.py" "${PANDA_DIR}"
                           COMMENT "Interrogate")

    else()
        add_library(toontown STATIC
            ${BASE_FILES}
            ${COMPONENTS_FILES}
            ${IGATE_FILES}
        )
        add_custom_command(TARGET toontown
                           PRE_BUILD
                           COMMAND ${PYTHON2_EXECUTABLE} "${CMAKE_SOURCE_DIR}/src/run_interrogate.py" "${PANDA_DIR}"
                           COMMENT "Interrogate")
    endif()

endif()

### Setup source groups and defines for configurables ###
source_group("base" FILES ${BASE_FILES})
source_group("components" FILES ${COMPONENTS_FILES})
source_group("interrogate_files" FILES ${IGATE_FILES})