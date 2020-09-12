// Filename: config_dna.h
// Created by:  shochet (26Jun00)
//
////////////////////////////////////////////////////////////////////

#pragma once

#ifdef NDEBUG
#undef NDEBUG
#endif

#include <pandabase.h>
#include <notifyCategoryProxy.h>
#include <config_linmath.h>
#include <configVariableList.h>
#include <configVariableSearchPath.h>
#include <coordinateSystem.h>
#include <pandaNode.h>
#include <pointerTo.h>

class DSearchPath;

#pragma warning (disable : 4273)
#pragma warning (disable : 4275)

#ifdef BUILDING_DNA 
    #define EXPCL_TOONTOWN EXPORT_CLASS 
    #define EXPTP_TOONTOWN EXPORT_TEMPL 
#else 
   #define EXPCL_TOONTOWN IMPORT_CLASS 
   #define EXPTP_TOONTOWN IMPORT_TEMPL 
#endif 

extern ConfigVariableList dna_preload;
extern ConfigVariableSearchPath dna_path;

NotifyCategoryDecl(dna, EXPCL_TOONTOWN, EXPTP_TOONTOWN);
extern void init_libdnaLoader();

BEGIN_PUBLISH
const ConfigVariableSearchPath &get_dna_path();
END_PUBLISH