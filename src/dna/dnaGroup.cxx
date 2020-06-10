/*
 * @file dnaGroup.cxx
 * @author theclashingfritz
 * @date 6-10-20
 */

#include "dnaGroup.h"
#include "dnaStorage.h"

TypeHandle DNAGroup::_type_handle;

/**
 *
 */
DNAGroup::DNAGroup(std::string initial_name) {
    name = initial_name;
}

/**
 *
 */
DNAGroup::DNAGroup(const DNAGroup &group) {
    name = group.name;
    children = group.children;
}

/**
 *
 */
DNAGroup::~DNAGroup() {

}

/**
 *
 */
INLINE void DNAGroup::clear_parent() {
    parent = nullptr;
}

/**
 * Return the current group
 */
INLINE PT(DNAGroup) DNAGroup::current() {
    return children.back();
}

/**
 * How many groups do we have under us?
 */
INLINE size_t DNAGroup::get_num_children() {
    return children.size();
}

/**
 *  Return the parent group
 */
INLINE PT(DNAGroup) DNAGroup::get_parent() {
    return parent;
}

 
/**
 * Return the nth group in the vector
 */
INLINE PT(DNAGroup) DNAGroup::at(size_t index) {
    return children.at(index);
}

/**
 * Remove a group from this vector. Note, this is
 * not really meant for heavy use, since we are using
 * an STL vector which erases in linear time.
 * Should be ok, since removal will be rare.
 */
INLINE void DNAGroup::remove(PT(DNAGroup) group) {
    for (pvector<PT(DNAGroup)>::iterator it = children.begin(); it != children.end(); ++it) {
        if (*it == group) {
            children.erase(it);
            return;
        }
    }
    dna_cat.warning() << "DNAGroup: group not found in map" << std::endl;
}

/**
 * Add a DNAGroup to this vector of nodes
 */
INLINE void DNAGroup::add(PT(DNAGroup) group) {
    children.push_back(group);
}

/**
 * Writes the group and all children to cout (for debugging)
 */
INLINE void DNAGroup::ls() {
    write(std::cout, 0, 0);
}

/**
 * 
 */
INLINE void DNAGroup::set_parent(PT(DNAGroup) parent) {
    this->parent = parent;
}

/**
 * Writes the group and all children to output
 */
void DNAGroup::write(std::ostream &out, DNAStorage *store, int indent_level) {
    indent(out, indent_level);
    out << "group \"" << name << "\" [" << std::endl;
    for (pvector<PT(DNAGroup)>::iterator it = children.begin(); it != children.end(); ++it) {
        (*it)->write(out, store, indent_level + 1);
    }
    indent(out, indent_level);
    out << "]" << std::endl;
}

/**
 * The top level traverse does some special things
 */
NodePath DNAGroup::top_level_traverse(NodePath &parent, DNAStorage *store, int editing) {
    NodePath _np = parent.attach_new_node(name);
    for (pvector<PT(DNAGroup)>::iterator it = children.begin(); it != children.end(); ++it) {
        (*it)->traverse(_np, store, editing);
    }

    if (editing) {
        PT(DNAGroup) PT_this = this;
        PT(PandaNode) store_node = _np.node();
        store->store_DNAGroup(store_node, PT_this);
    }
    return _np;
}

/**
 *
 */
NodePath DNAGroup::traverse(NodePath &parent, DNAStorage *store, int editing) {
    NodePath _np = parent.attach_new_node(name);
    for (pvector<PT(DNAGroup)>::iterator it = children.begin(); it != children.end(); ++it) {
        (*it)->traverse(_np, store, editing);
    }

    if (editing) {
        PT(DNAGroup) PT_this = this;
        PT(PandaNode) store_node = _np.node();
        store->store_DNAGroup(store_node, PT_this);
    }
    return _np;
}