#include "DNAGroup.h"
#include "DNAStorage.h"

TypeHandle DNAGroup::_type_handle;

DNAGroup::DNAGroup(std::string initial_name) {
    name = initial_name;
}

DNAGroup::DNAGroup(const DNAGroup& group) {
    name = group.name;
    children = group.children;
}

DNAGroup::~DNAGroup() {

}

void DNAGroup::add(PT(DNAGroup) group) {
    children.push_back(group);
}

PT(DNAGroup) DNAGroup::at(size_t index) {
    return children.at(index);
}

void DNAGroup::clear_parent() {
    parent = nullptr;
}

PT(DNAGroup) DNAGroup::current() {
    return children.back();
}

size_t DNAGroup::get_num_children() {
    return children.size();
}

PT(DNAGroup) DNAGroup::get_parent() {
    return parent;
}

void DNAGroup::ls() {
    write(std::cout, 0, 0);
}

void DNAGroup::remove(PT(DNAGroup) group) {
    for (pvector<PT(DNAGroup)>::iterator it = children.begin(); it != children.end(); ++it) {
        if (*it == group) {
            children.erase(it);
            return;
        }
    }
    dna_cat.warning() << "DNAGroup: group not found in map" << std::endl;
}

void DNAGroup::set_parent(PT(DNAGroup) parent) {
    this->parent = parent;
}

NodePath DNAGroup::top_level_traverse(NodePath& parent, DNAStorage* store, int editing) {
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

NodePath DNAGroup::traverse(NodePath& parent, DNAStorage *store, int editing) {
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

void DNAGroup::write(std::ostream& out, DNAStorage* store, int indent_level) {
    indent(out, indent_level);
    out << "group \"";
    out << name << "\" [" << std::endl;
    for (pvector<PT(DNAGroup)>::iterator it = children.begin(); it != children.end(); ++it) {
        (*it)->write(out, store, indent_level + 1);
    }
    indent(out, indent_level);
    out << "]" << std::endl;
}