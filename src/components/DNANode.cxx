#include "DNANode.h"
#include "DNAStorage.h"

TypeHandle DNANode::_type_handle;

DNANode::DNANode(std::string initial_name) : DNAGroup(initial_name) {
    pos = LVecBase3f(0.0, 0.0, 0.0);
    hpr = LVecBase3f(0.0, 0.0, 0.0);
    scale = LVecBase3f(1.0, 1.0, 1.0);
}

DNANode::DNANode(const DNANode &node) : DNAGroup(node) {
    pos = node.pos;
    hpr = node.hpr;
    scale = node.scale;
}

DNANode::~DNANode() {

}

LVecBase3f DNANode::get_hpr() {
    return hpr;
}

LVecBase3f DNANode::get_pos() {
    return pos;
}

LVecBase3f DNANode::get_scale() {
    return scale;
}

void DNANode::set_hpr(const LVecBase3f& hpr) {
    this->hpr = hpr;
}

void DNANode::set_pos(const LVecBase3f& pos) {
    this->pos = pos;
}

void DNANode::set_scale(const LVecBase3f& scale) {
    this->scale = scale;
}

NodePath DNANode::traverse(NodePath &parent, DNAStorage *store, int editing) {
    NodePath _np = parent.attach_new_node(name);
    _np.set_pos_hpr_scale(pos, hpr, scale);
    for (pvector<PT(DNAGroup)>::iterator it = children.begin(); it != children.end(); ++it) {
        (*it)->traverse(_np, store, editing);
    }

    if (editing) {
        PT(DNAGroup) PT_this = (DNAGroup*)this;
        PT(PandaNode) store_node = _np.node();
        store->store_DNAGroup(store_node, PT_this);
    }
    return _np;
}

void DNANode::write(std::ostream &out, DNAStorage *store, int indent_level) {
    indent(out, indent_level);
    out << "node \"" << name << "\" [" << std::endl;
    if (pos != LVecBase3f(0.0, 0.0, 0.0)) {
        indent(out, indent_level + 1);
        out << "pos [ " << pos[0] << " " << pos[1] << " " << pos[2] << " ]" << std::endl;
    }
    if (hpr != LVecBase3f(0.0, 0.0, 0.0)) {
        indent(out, indent_level + 1);
        if (temp_hpr_fix) {
            out << "nhpr [ ";
        } else {
            out << "hpr [ ";
        }
        out << hpr[0] << " " << hpr[1] << " " << hpr[2] << " ]" << std::endl;
    }
    if (scale != LVecBase3f(1.0, 1.0, 1.0)) {
        indent(out, indent_level + 1);
        out << "scale [ " << scale[0] << " " << scale[1] << " " << scale[2] << " ]" << std::endl;
    }
    for (pvector<PT(DNAGroup)>::iterator it = children.begin(); it != children.end(); ++it) {
        (*it)->write(out, store, indent_level + 1);
    }
    indent(out, indent_level);
    out << "]" << std::endl;
}