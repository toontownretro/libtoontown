#pragma once

#include "config_dna.h"

#include <pandabase.h>
#include <pandaVersion.h>
#include <datagramIterator.h>
#include <luse.h>
#include <string.h>

#ifndef temp_hpr_fix
#define temp_hpr_fix true
#endif

#if PANDA_NUMERIC_VERSION >= 1008000
#define Colorf LColorf
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