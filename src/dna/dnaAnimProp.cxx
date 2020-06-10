#include "dnaAnimProp.h"
#include "dnaStorage.h"

TypeHandle DNAAnimProp::_type_handle;

DNAAnimProp::DNAAnimProp(std::string initial_name) : DNAProp(initial_name) {

}

DNAAnimProp::DNAAnimProp(const DNAAnimProp &anim_prop) : DNAProp(anim_prop) {
    anim = anim_prop.anim;
}

DNAAnimProp::~DNAAnimProp() {

}

std::string DNAAnimProp::get_anim() {
    return anim;
}

void DNAAnimProp::set_anim(std::string &anim) {
    this->anim = anim;
}

NodePath DNAAnimProp::traverse(NodePath &parent, DNAStorage *store, int editing) {
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
    _np.set_tag("DNAAnim", anim);
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

void DNAAnimProp::write(std::ostream &out, DNAStorage *store, int indent_level) {
    indent(out, indent_level);
    out << "anim_prop \"" << name << "\" [" << std::endl;
    indent(out, indent_level + 1);
    out << "code [ \"" << code << "\" ]" << std::endl;
    indent(out, indent_level + 1);
    out << "anim [ \"" << anim << "\" ]" << std::endl;

    // Animated Props always have a position.
    indent(out, indent_level + 1);
    out << "pos [ " << pos[0] << " " << pos[1] << " " << pos[2] << " ]" << std::endl;

    // Animated Props always have a hpr.
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