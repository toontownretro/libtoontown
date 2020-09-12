// Filename: config_dna.cxx
// Created by:  shochet (26Jun00)
//
////////////////////////////////////////////////////////////////////

#include "config_dna.h"

#include <loaderFileTypeRegistry.h>

#include "dnaAnimBuilding.h"
#include "dnaAnimProp.h"
#include "dnaBattleCell.h"
#include "dnaCornice.h"
#include "dnaDoor.h"
#include "dnaGroup.h"
#include "dnaInteractiveProp.h"
#include "dnaBuildings.h"
#include "dnaNode.h"
#include "dnaProp.h"
#include "dnaSign.h"
#include "dnaSignBaseline.h"
#include "dnaSignGraphic.h"
#include "dnaSignText.h"
#include "dnaStreet.h"
#include "dnaSuitEdge.h"
#include "dnaSuitPath.h"
#include "dnaSuitPoint.h"
#include "dnaVisGroup.h"
#include "dnaWindow.h"

#include "loaderFileTypeDNA.h"

#include <pandabase.h>
#include <dconfig.h>

Configure(config_dna);
NotifyCategoryDef(dna, "");

ConfigVariableList dna_preload("dna-preload");
ConfigVariableSearchPath dna_path("dna-path");

ConfigureFn(config_dna) {
    init_libdnaLoader();
}

void init_libdnaLoader() {
    static bool initialized = false;
    if (initialized) {
        return;
    }

    initialized = true;
    
    DNAGroup::init_type();
    DNAVisGroup::init_type();
    //DNAData::init_type();
    DNANode::init_type();
    DNAWindows::init_type();
    DNAStreet::init_type();
    DNAWall::init_type();
    DNAFlatBuilding::init_type();
    DNALandmarkBuilding::init_type();
    DNACornice::init_type();
    DNAProp::init_type();
    DNAAnimProp::init_type();
    DNAInteractiveProp::init_type();
    DNAAnimBuilding::init_type();
    DNADoor::init_type();
    DNAFlatDoor::init_type();
    DNASign::init_type();
    DNASignBaseline::init_type();
    DNASignGraphic::init_type();
    DNASignText::init_type();
    DNASuitPoint::init_type();
    DNASuitEdge::init_type();
    DNASuitPath::init_type();
    DNABattleCell::init_type();
    LoaderFileTypeDNA::init_type();

    LoaderFileTypeRegistry *reg = LoaderFileTypeRegistry::get_global_ptr();
    reg->register_type(new LoaderFileTypeDNA);
}

const ConfigVariableSearchPath &get_dna_path() {
    return dna_path;
}