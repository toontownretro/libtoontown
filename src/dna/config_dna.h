// Filename: config_dna.h
// Created by:  shochet (26Jun00)
//
////////////////////////////////////////////////////////////////////

#pragma once

#include "toontownbase.h"

#include <pandabase.h>
#include <notifyCategoryProxy.h>
#include <config_linmath.h>
#include <configVariableList.h>
#include <configVariableSearchPath.h>
#include <coordinateSystem.h>
#include <pandaNode.h>
#include <pointerTo.h>

class DSearchPath;

extern ConfigVariableList dna_preload;
extern ConfigVariableSearchPath dna_path;

NotifyCategoryDecl(dna, EXPCL_TOONTOWN, EXPTP_TOONTOWN);
extern void init_libdnaLoader();

BEGIN_PUBLISH
const ConfigVariableSearchPath &get_dna_path();
END_PUBLISH