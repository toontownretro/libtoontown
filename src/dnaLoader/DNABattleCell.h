#pragma once

#include "dnabase.h"

#include <luse.h>
#include <typedReferenceCount.h>
#include <nodePath.h>

class DNAStorage;

class EXPCL_TOONTOWN DNABattleCell : public TypedReferenceCount {
    PUBLISHED:
        DNABattleCell(float width, float height, LPoint3f pos);
        ~DNABattleCell();
        
        double get_height();
        LPoint3f get_pos();
        double get_width();
        
        void set_pos(LPoint3f pos);
        void set_width_height(float width, float height);
        
        void output(std::ostream &out);
        virtual NodePath traverse(NodePath &parent, DNAStorage *store, int editing = 0);
        virtual void write(std::ostream &out, DNAStorage *store, int indent_level = 0);

    private:
        double width;
        double height;
        LPoint3f pos;
        
    TYPE_HANDLE(DNABattleCell, TypedReferenceCount);
};