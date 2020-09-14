// Filename: toontownsymbols.h
// Created by:  drose (18Feb00)
/////////////////////////////////////////////

#pragma once

#ifdef NDEBUG
#undef NDEBUG
#endif

#include <pandabase.h>
#include <pandaVersion.h>
#include <datagramIterator.h>
#include <luse.h>
#include <string.h>
#include <string_utils.h>

#ifndef temp_hpr_fix
static bool temp_hpr_fix = true;
#endif

// These are removed legacy functions in more recent versions of Panda3d. However our DNA system supports old HPR when possible, So we need these.
#ifndef new_to_old_hpr
void compose_matrix_new_hpr(FLOATNAME(LMatrix3) &mat, const FLOATNAME(LVecBase3) &scale, const FLOATNAME(LVecBase3) &shear, const FLOATNAME(LVecBase3) &hpr, CoordinateSystem cs = CS_default);
FLOATNAME(LVecBase3) new_to_old_hpr(const FLOATNAME(LVecBase3) &new_hpr);
#endif

#if PANDA_NUMERIC_VERSION >= 1008000
#define Colorf LColorf
#endif

#pragma warning (disable : 4273)
#pragma warning (disable : 4275)

/* See dtoolsymbols.h for a rant on the purpose of this file.  */

#ifdef BUILDING_TOONTOWN 
    #define EXPCL_TOONTOWN EXPORT_CLASS 
    #define EXPTP_TOONTOWN EXPORT_TEMPL 
#else 
    #define EXPCL_TOONTOWN IMPORT_CLASS 
    #define EXPTP_TOONTOWN IMPORT_TEMPL
#endif 

#define TYPE_HANDLE(NAME, PARENT) public: \
                                    static TypeHandle get_class_type() { return _type_handle; }; \
                                    virtual TypeHandle force_init_type() { init_type(); return get_class_type(); }; \
                                    virtual TypeHandle get_type() const { return get_class_type(); }; \
                                    static void init_type() { PARENT :: init_type(); register_type(_type_handle, #NAME, PARENT :: get_class_type()); }; \
                                  private: static TypeHandle _type_handle;

#define TYPE_HANDLE2(NAME, PARENT, PARENT2) public: \
                                    static TypeHandle get_class_type() { return _type_handle; }; \
                                    virtual TypeHandle force_init_type() { init_type(); return get_class_type(); }; \
                                    virtual TypeHandle get_type() const { return get_class_type(); }; \
                                    static void init_type() { PARENT :: init_type(); PARENT2 :: init_type(); register_type(_type_handle, #NAME, PARENT :: get_class_type(), PARENT2 :: get_class_type()); }; \
                                  private: static TypeHandle _type_handle;