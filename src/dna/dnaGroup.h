#pragma once

#include "dnabase.h"

#include <luse.h>
#include <typedReferenceCount.h>
#include <nodePath.h>
#include <pvector.h>

class DNAStorage;

/**
 * A group of dna nodes
 */
class EXPCL_TOONTOWN DNAGroup : public TypedReferenceCount {
    PUBLISHED:
        DNAGroup(std::string initial_name);
        DNAGroup(const DNAGroup &group);
        ~DNAGroup();

        void add(PT(DNAGroup) group);
        void remove(PT(DNAGroup) group);
        void set_parent(PT(DNAGroup) parent);
        void clear_parent();
        void ls();
        virtual void write(std::ostream &out, DNAStorage *store, int indent_level = 0);

        PT(DNAGroup) get_parent();
        PT(DNAGroup) at(size_t index);
        PT(DNAGroup) current();

        NodePath top_level_traverse(NodePath &parent, DNAStorage *store, int editing = 0);
        virtual NodePath traverse(NodePath &parent, DNAStorage *store, int editing = 0);

        size_t get_num_children();

    protected:
        std::string name;
        pvector<PT(DNAGroup)> children;

    private:
        PT(DNAGroup) parent;

    TYPE_HANDLE(DNAGroup, TypedReferenceCount);
};