#include "config_dna.h"

#include "DNABattleCell.h"
#include "DNASuitEdge.h"
#include "DNASuitPath.h"
#include "DNASuitPoint.h"

#include <pandabase.h>
#include <dconfig.h>

Configure(config_dna);
NotifyCategoryDef(dna, "");

ConfigureFn(config_dna) {
    init_libtoontown();
}

void init_libtoontown() {
    static bool initialized = false;
    if (initialized)
        return;

    initialized = true;
    
    DNABattleCell::init_type();
    DNASuitEdge::init_type();
    DNASuitPath::init_type();
    DNASuitPoint::init_type();
}