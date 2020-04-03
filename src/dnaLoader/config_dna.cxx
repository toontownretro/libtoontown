#include "config_dna.h"

#include <loaderFileTypeRegistry.h>

#include "DNAAnimProp.h"
#include "DNABattleCell.h"
#include "DNADoor.h"
#include "DNAFlatDoor.h"
#include "DNAGroup.h"
#include "DNAInteractiveProp.h"
#include "DNALandmarkBuilding.h"
#include "DNANode.h"
#include "DNAProp.h"
#include "DNASuitEdge.h"
#include "DNASuitPath.h"
#include "DNASuitPoint.h"
#include "DNAVisGroup.h"

#include "LoaderFileTypeDNA.h"

#include <pandabase.h>
#include <dconfig.h>

ConfigVariableSearchPath dna_path("dna-path", ".", "");

Configure(config_dna);
NotifyCategoryDef(dna, "");

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
    DNANode::init_type();
    DNALandmarkBuilding::init_type();
    DNAProp::init_type();
    DNAAnimProp::init_type();
    DNAInteractiveProp::init_type();
    DNADoor::init_type();
    DNAFlatDoor::init_type();
    DNASuitPoint::init_type();
    DNASuitEdge::init_type();
    DNASuitPath::init_type();
    DNABattleCell::init_type();
    LoaderFileTypeDNA::init_type();

    LoaderFileTypeRegistry *reg = LoaderFileTypeRegistry::get_global_ptr();
    reg->register_type(new LoaderFileTypeDNA);
}

PT(PandaNode) load_dna_file(DNAStorage *dna_store, std::string &filename, CoordinateSystem cs, int editing) {
    return nullptr;
}

PT(PandaNode) load_dna_file_AI(DNAStorage *dna_store, std::string &filename, CoordinateSystem cs) {
    return nullptr;
}

ConfigVariableSearchPath &get_dna_path() {
    return dna_path;
}