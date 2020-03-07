#pragma once

#include "dnabase.h"

#include "DNAGroup.h"

#include <luse.h>
#include <typedReferenceCount.h>
#include <pandaNode.h>
#include <pmap.h>

class EXPCL_DNA DNAStorage {
    PUBLISHED:
        DNAStorage();
        ~DNAStorage();
        NodePath find_node(std::string dna_string);
        void store_DNAGroup(PT(PandaNode) node, PT(DNAGroup) group);

    private:
        pmap<std::string, NodePath> Code2NodeMap;
        pmap<std::string, NodePath> Code2HoodNodeMap;
        pmap<std::string, NodePath> Code2PlaceNodeMap;
        pmap<PT(PandaNode), PT(DNAGroup)> Node2GroupMap;
};