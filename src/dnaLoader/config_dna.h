#pragma once

#ifdef NDEBUG
#undef NDEBUG
#endif

#include <pandabase.h>
#include <notifyCategoryProxy.h>
#include <config_linmath.h>

#pragma warning (disable : 4273)
#pragma warning (disable : 4275)

#ifdef BUILDING_DNA 
    #define EXPCL_TOONTOWN EXPORT_CLASS 
    #define EXPTP_TOONTOWN EXPORT_TEMPL 
#else 
   #define EXPCL_TOONTOWN IMPORT_CLASS 
   #define EXPTP_TOONTOWN IMPORT_TEMPL 
#endif 

NotifyCategoryDecl(dna, EXPCL_TOONTOWN, EXPTP_TOONTOWN);
extern void init_libdnaLoader();