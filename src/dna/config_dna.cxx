#include "config_dna.h"

#include <loaderFileTypeRegistry.h>

#include "dnaAnimProp.h"
#include "dnaBattleCell.h"
#include "dnaDoor.h"
#include "dnaFlatDoor.h"
#include "dnaGroup.h"
#include "dnaInteractiveProp.h"
#include "dnaLandmarkBuilding.h"
#include "dnaNode.h"
#include "dnaProp.h"
#include "dnaSuitEdge.h"
#include "dnaSuitPath.h"
#include "dnaSuitPoint.h"
#include "dnaVisGroup.h"

#include "loaderFileTypeDNA.h"

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


/**
 * A convenience function; the primary interface to this
 * package.  Loads up the indicated dna file, and
 * returns the root of a scene graph.  Returns NULL if
 * the file cannot be read for some reason.
 */
PT(PandaNode) load_dna_file(DNAStorage *dna_store, std::string &filename, CoordinateSystem cs, int editing) {
    return nullptr;
}

/**
 * Loads up the indicated dna file but does not create
 * any geometry from it. It simply creates the dna
 * structures that can then be accessed via the dnaStorage
 * Returns the DNAData object on success, or NULL if the
 * file cannot be read for some reason.
 */
PT(PandaNode) load_dna_file_AI(DNAStorage *dna_store, std::string &filename, CoordinateSystem cs) {
    return nullptr;
}

ConfigVariableSearchPath &get_dna_path() {
    return dna_path;
}