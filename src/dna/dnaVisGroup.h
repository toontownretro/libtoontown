// Filename: dnaVisGroup.h
// Created by:  shochet (24May00)
//
////////////////////////////////////////////////////////////////////
#pragma once
////////////////////////////////////////////////////////////////////
// Includes
////////////////////////////////////////////////////////////////////
#include "toontownbase.h"

#include "typedObject.h"
#include "namable.h"
#include "nodePath.h"
#include "pvector.h"
#include <string>
#include "pointerTo.h"

#include "dnaGroup.h"
#include "dnaSuitEdge.h"
#include "dnaBattleCell.h"

class DNAStorage;

////////////////////////////////////////////////////////////////////
//       Class : DNAVisGroup
// Description : A group of dna nodes with special visibility info
//               tagged in a vis property. The vis property should list
//               all the other DNAVisGroups (including itself) that
//               should be rendered when the avatar is standing in this group
////////////////////////////////////////////////////////////////////
class EXPCL_TOONTOWN DNAVisGroup : public DNAGroup {
    PUBLISHED:
        DNAVisGroup(const std::string &initial_name = "");
        DNAVisGroup(const DNAVisGroup &group);

        virtual NodePath traverse(NodePath &parent, DNAStorage *store, int editing=0);
        virtual void write(std::ostream &out, DNAStorage *store, int indent_level = 0) const;
        virtual void write(Datagram &datagram, DNAStorage *store) const;
        virtual void make_from_dgi(DatagramIterator &dgi, DNAStorage *store);

        void add_visible(const std::string &vis_group_name);
        int remove_visible(const std::string &vis_group_name);
        int get_num_visibles() const;
        std::string get_visible_name(uint i) const;

        void add_suit_edge(PT(DNASuitEdge) edge);
        int remove_suit_edge(PT(DNASuitEdge) edge);
        int get_num_suit_edges() const;
        PT(DNASuitEdge) get_suit_edge(uint i) const;

        void add_battle_cell(PT(DNABattleCell) cell);
        int remove_battle_cell(PT(DNABattleCell) cell);
        int get_num_battle_cells() const;
        PT(DNABattleCell) get_battle_cell(uint i) const;

    private:
        virtual DNAGroup* make_copy();

    protected:
        pvector< std::string > _vis_vector;
        pvector< PT(DNASuitEdge) > _suit_edge_vector;
        pvector< PT(DNABattleCell) > _battle_cell_vector;

    TYPE_HANDLE("DNAVisGroup", DNAGroup)
};