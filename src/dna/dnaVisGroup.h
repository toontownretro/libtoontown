#pragma once

#include "dnabase.h"

#include "dnaGroup.h"
#include "dnaBattleCell.h"
#include "dnaSuitEdge.h"

#include <luse.h>
#include <typedReferenceCount.h>
#include <nodePath.h>
#include <pvector.h>

class DNAStorage;

/**
 * A group of dna nodes with special visibility info
 * tagged in a vis property. The vis property should list
 * all the other DNAVisGroups (including itself) that
 * should be rendered when the avatar is standing in this group
 */
class EXPCL_TOONTOWN DNAVisGroup : public DNAGroup {
	PUBLISHED:
		DNAVisGroup(std::string initial_name);
		~DNAVisGroup();

		void add_battle_cell(PT(DNABattleCell) cell);
		void add_suit_edge(PT(DNASuitEdge) edge);
		void add_visible(std::string &vis_group_name);
		void remove_battle_cell(PT(DNABattleCell) cell);
		void remove_suit_edge(PT(DNASuitEdge) edge);
		void remove_visible(std::string &vis_group_name);

		PT(DNABattleCell) get_battle_cell(unsigned int i);

		PT(DNASuitEdge) get_suit_edge(unsigned int i);

		std::string get_visible_name(unsigned int i);

		size_t get_num_battle_cells();
		size_t get_num_suit_edges();
		size_t get_num_visibles();

	public:
		virtual void write(std::ostream &out, DNAStorage *store, int indent_level = 0);

		virtual NodePath traverse(NodePath &parent, DNAStorage *store, int editing = 0);

	private:
		pvector<PT(DNABattleCell)> battle_cells;
		pvector<PT(DNASuitEdge)> suit_edges;
		pvector<std::string> visibles;

	TYPE_HANDLE(DNAVisGroup, DNAGroup);
};