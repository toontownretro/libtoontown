#include "config_dna.h"

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

#include <pandabase.h>
#include <dconfig.h>

Configure(config_dna);
NotifyCategoryDef(dna, "");

ConfigureFn(config_dna) {
    init_libtoontown();
}

void init_libtoontown() {
    static bool initialized = false;
    if (initialized) {
        return;
    }

    initialized = true;
    
    DNAAnimProp::init_type();
    DNABattleCell::init_type();
    DNADoor::init_type();
    DNAFlatDoor::init_type();
    DNAGroup::init_type();
    DNAInteractiveProp::init_type();
    DNALandmarkBuilding::init_type();
    DNANode::init_type();
    DNAProp::init_type();
    DNASuitEdge::init_type();
    DNASuitPath::init_type();
    DNASuitPoint::init_type();
    DNAVisGroup::init_type();
}