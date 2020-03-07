#pragma once

#include "dnabase.h"

#include "DNAGroup.h"

#include <luse.h>
#include <typedReferenceCount.h>
#include <nodePath.h>
#include <pvector.h>

class DNAStorage;

class EXPCL_DNA DNANode : public DNAGroup {
	PUBLISHED:
        DNANode(std::string initial_name);
        DNANode(const DNANode &node);
        ~DNANode();

        LVecBase3f get_hpr();
        LVecBase3f get_pos();
        LVecBase3f get_scale();

        void set_hpr(const LVecBase3f& hpr);
        void set_pos(const LVecBase3f& pos);
        void set_scale(const LVecBase3f& scale);

    public:
        virtual NodePath traverse(NodePath &parent, DNAStorage *store, int editing = 0);
        virtual void write(std::ostream &out, DNAStorage *store, int indent_level = 0);

    protected:
        LVecBase3f pos;
        LVecBase3f hpr;
        LVecBase3f scale;

    TYPE_HANDLE(DNANode, DNAGroup);
};