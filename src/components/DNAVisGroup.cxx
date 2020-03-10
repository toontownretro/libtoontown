#include "DNAVisGroup.h"
#include "DNAStorage.h"

TypeHandle DNAVisGroup::_type_handle;

DNAVisGroup::DNAVisGroup(std::string initial_name) : DNAGroup(initial_name) {

}

DNAVisGroup::~DNAVisGroup() {

}

void DNAVisGroup::add_battle_cell(PT(DNABattleCell) cell) {
    battle_cells.push_back(cell);
}

void DNAVisGroup::add_suit_edge(PT(DNASuitEdge) edge) {
    if (edge->get_start_point() == edge->get_end_point()) {
        return;
    }
    suit_edges.push_back(edge);
}

void DNAVisGroup::add_visible(std::string &vis_group_name) {
    visibles.push_back(vis_group_name);
}

PT(DNABattleCell) DNAVisGroup::get_battle_cell(unsigned int i) {
    return battle_cells[i];
}

size_t DNAVisGroup::get_num_battle_cells() {
    return battle_cells.size();
}

size_t DNAVisGroup::get_num_suit_edges() {
    return suit_edges.size();
}

size_t DNAVisGroup::get_num_visibles() {
    return visibles.size();
}

PT(DNASuitEdge) DNAVisGroup::get_suit_edge(unsigned int i) {
    return suit_edges[i];
}

std::string DNAVisGroup::get_visible_name(unsigned int i) {
    return visibles[i];
}

void DNAVisGroup::remove_battle_cell(PT(DNABattleCell) cell) {
    for (pvector<PT(DNABattleCell)>::iterator it = battle_cells.begin(); it != battle_cells.end(); ++it) {
        if (*it == cell) {
            battle_cells.erase(it);
            return;
        }
    }
    dna_cat.warning() << "DNABattleCell: cell not found in vector: ";
    cell->output(dna_cat.warning());
    dna_cat.warning() << std::endl;
}

void DNAVisGroup::remove_suit_edge(PT(DNASuitEdge) edge) {
    for (pvector<PT(DNASuitEdge)>::iterator it = suit_edges.begin(); it != suit_edges.end(); ++it) {
        if (*it == edge) {
            suit_edges.erase(it);
            return;
        }
    }
    // In libtoontown, .debug() and .spam() return a null Notify stream for both dna_cat and pets_cat.
    // This means that this notify out has to be either of those options.
    dna_cat.debug() << "DNASuitEdge: edge not found in vector: ";
    edge->output(dna_cat.debug());
    dna_cat.debug() << std::endl;
}

void DNAVisGroup::remove_visible(std::string &vis_group_name) {
    for (pvector<std::string>::iterator it = visibles.begin(); it != visibles.end(); ++it) {
        if (it->compare(vis_group_name) == 0) {
            visibles.erase(it);
            return;
        }
    }
    dna_cat.warning() << "DNAVisGroup: vis group not found in vector: " << vis_group_name << std::endl;
}

NodePath DNAVisGroup::traverse(NodePath &parent, DNAStorage *store, int editing) {
    NodePath _np = parent.attach_new_node(name);
    for (pvector<PT(DNAGroup)>::iterator it = children.begin(); it != children.end(); ++it) {
        (*it)->traverse(_np, store, editing);
    }

    if (editing) {
        PT(DNAGroup) PT_this = (DNAGroup*)this;
        PT(PandaNode) store_node = _np.node();
        store->store_DNAGroup(store_node, PT_this);
    }
    store->store_DNAVisGroup(_np.node(), this);
    return _np;
}

void DNAVisGroup::write(std::ostream &out, DNAStorage *store, int indent_level) {
    indent(out, indent_level);
    out << "visgroup \"" << name << "\" [" << std::endl;
    indent(out, indent_level + 1);
    out << "vis [ ";
    for (pvector<std::string>::iterator it = visibles.begin(); it != visibles.end(); ++it) {
        out << "\"" << *it << "\" ";
    }
    out << "]" << std::endl;
    for (pvector<PT(DNASuitEdge)>::iterator it = suit_edges.begin(); it != suit_edges.end(); ++it) {
        (*it)->write(out, store, indent_level + 1);
    }
    for (pvector<PT(DNABattleCell)>::iterator it = battle_cells.begin(); it != battle_cells.end(); ++it) {
        (*it)->write(out, store, indent_level + 1);
    }
    for (pvector<PT(DNAGroup)>::iterator it = children.begin(); it != children.end(); ++it) {
        (*it)->write(out, store, indent_level + 1);
    }
    indent(out, indent_level);
    out << "]" << std::endl;
}