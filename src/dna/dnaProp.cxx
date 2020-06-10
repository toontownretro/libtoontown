#include "dnaProp.h"
#include "dnaStorage.h"

#include <modelNode.h>

TypeHandle DNAProp::_type_handle;

DNAProp::DNAProp(std::string initial_name) : DNANode(initial_name) {
    color = LVecBase4f(1.0, 1.0, 1.0, 1.0);
}

DNAProp::DNAProp(const DNAProp &prop) : DNANode(prop) {
    color = prop.color;
}

DNAProp::~DNAProp() {

}

std::string DNAProp::get_code() {
    return code;
}

LVector4f DNAProp::get_color() {
    return color;
}

void DNAProp::set_code(std::string &code) {
    this->code = code;
}

void DNAProp::set_color(const LVecBase4f &color) {
    this->color = color;
}

NodePath DNAProp::traverse(NodePath &parent, DNAStorage *store, int editing) {
    NodePath _np;

    if (code == "DCS") {
        PT(ModelNode) node = new ModelNode(name);
        node->set_preserve_transform(ModelNode::PT_net);
        _np = parent.attach_new_node(node);
    } else {
        NodePath nodepath = store->find_node(code);
        if (nodepath.is_empty()) {
            return NodePath();
        }

        _np = nodepath.copy_to(parent);

        // This is my best guess for as to what it did. 
        // The code is a mess in the decompiler.
        if (nodepath.has_tag("DNARoot")) {
            std::string tag = nodepath.get_tag("DNARoot");
            _np.set_tag("DNARoot", tag);
        }
        if (nodepath.has_tag("DNACode")) {
            std::string tag = nodepath.get_tag("DNACode");
            _np.set_tag("DNACode", tag);
        }
        _np.node()->set_name(name); // Is it this or _np.set_name(name)?
    }
    _np.set_pos_hpr_scale(pos, hpr, scale);
    _np.set_color_scale(color);

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

void DNAProp::write(std::ostream &out, DNAStorage *store, int indent_level) {
    indent(out, indent_level);
    out << "prop \"" << name << "\" [" << std::endl;

    // DNAProps always have a code.
    indent(out, indent_level + 1);
    out << "code [ \"" << code << "\" ]" << std::endl;

    // DNAProps always have a pos.
    indent(out, indent_level + 1);
    out << "pos [ " << pos[0] << " " << pos[1] << " " << pos[2] << " ]" << std::endl;

    // DNAProps always have a hpr.
    indent(out, indent_level + 1);
    if (temp_hpr_fix) {
        out << "nhpr [ ";
    } else {
        out << "hpr [ ";
    }
    out << hpr[0] << " " << hpr[1] << " " << hpr[2] << " ]" << std::endl;

    if (scale != LVecBase3f(1.0, 1.0, 1.0)) {
        indent(out, indent_level + 1);
        out << "scale [ " << scale[0] << " " << scale[1] << " " << scale[2] << " ]" << std::endl;
    }
    if (color != LVecBase4f(1.0, 1.0, 1.0, 1.0)) {
        indent(out, indent_level + 1);
        out << "color [ " << color[0] << " " << color[1] << " " << color[2] << " " << color[3] << " ]" << std::endl;
    }
    for (pvector<PT(DNAGroup)>::iterator it = children.begin(); it != children.end(); ++it) {
        (*it)->write(out, store, indent_level + 1);
    }
    indent(out, indent_level);
    out << "]" << std::endl;
}