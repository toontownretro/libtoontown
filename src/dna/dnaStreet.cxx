#include "dnaStreet.h"

#include "dnaStorage.h"

TypeHandle DNAStreet::_type_handle;

/**
 *
 */
DNAStreet::DNAStreet(std::string initial_name) : DNANode(initial_name) {
    curb_color = LVecBase4f(1.0, 1.0, 1.0, 1.0);
    sidewalk_color = LVecBase4f(1.0, 1.0, 1.0, 1.0);
    street_color = LVecBase4f(1.0, 1.0, 1.0, 1.0);
}

/**
 *
 */
DNAStreet::DNAStreet(const DNAStreet &street) : DNANode(street) {
    code = street.code;
    curb_texture = street.curb_texture;
    sidewalk_texture = street.sidewalk_texture;
    street_texture = street.street_texture;
    curb_color = street.curb_color;
    sidewalk_color = street.sidewalk_color;
    street_color = street.street_color;
}

/**
 *
 */
DNAStreet::~DNAStreet() {

}

/**
 *
 */
std::string DNAStreet::get_code() {
    return code;
}

/**
 *
 */
LVecBase4f DNAStreet::get_curb_color() {
    return curb_color;
}

/**
 *
 */
std::string DNAStreet::get_curb_texture() {
    return curb_texture;
}

/**
 *
 */
LVecBase4f DNAStreet::get_sidewalk_color() {
    return sidewalk_color;
}

/**
 *
 */
std::string DNAStreet::get_sidewalk_texture() {
    return sidewalk_texture;
}

/**
 *
 */
LVecBase4f DNAStreet::get_street_color() {
    return street_color;
}

/**
 *
 */
std::string DNAStreet::get_street_texture() {
    return street_texture;
}

/**
 *
 */
void DNAStreet::set_code(std::string &code) {
    this->code = code;
}

/**
 *
 */
void DNAStreet::set_curb_color(LVecBase4f &color) {
    this->curb_color = color;
}

/**
 *
 */
void DNAStreet::set_curb_texture(std::string &curb_texture) {
    this->curb_texture = curb_texture;
}

/**
 *
 */
void DNAStreet::set_sidewalk_color(LVecBase4f &color) {
    this->sidewalk_color = color;
}

/**
 *
 */
void DNAStreet::set_sidewalk_texture(std::string &sidewalk_texture) {
    this->sidewalk_texture = sidewalk_texture;
}

/**
 *
 */
void DNAStreet::set_street_color(LVecBase4f &color) {
    this->street_color = color;
}

/**
 *
 */
void DNAStreet::set_street_texture(std::string &street_texture) {
    this->street_texture = street_texture;
}

/**
 *
 */
NodePath DNAStreet::traverse(NodePath &parent, DNAStorage *store, int editing) {
    NodePath node = store->find_node(code);
    node = node.copy_to(parent);
    node.set_name(name);

    NodePath street_node = node.find("**/*_street");
    NodePath sidewalk_node = node.find("**/*_sidewalk");
    NodePath curb_node = node.find("**/*_curb");
    if (!street_node.is_empty()) {
        street_node.set_texture(store->find_texture(street_texture), 1);
        street_node.set_color_scale(street_color);
    }
    if (!sidewalk_node.is_empty()) {
        sidewalk_node.set_texture(store->find_texture(sidewalk_texture), 1);
        sidewalk_node.set_color_scale(sidewalk_color);
    }
    if (!curb_node.is_empty()) {
        curb_node.set_texture(store->find_texture(curb_texture), 1);
        curb_node.set_color_scale(curb_color);
    }
    node.set_pos_hpr_scale(pos, hpr, scale);

    if (editing) {
        PT(DNAGroup) PT_this = (DNAGroup*)this;
        PT(PandaNode) store_node = node.node();
        store->store_DNAGroup(store_node, PT_this);
    }

    return node;
}

/**
 *
 */
void DNAStreet::write(std::ostream& out, DNAStorage* store, int indent_level) {
    indent(out, indent_level);
    out << "street \"" << name << "\" [" << std::endl;
    indent(out, indent_level + 1);
    out << "code [ \"" << code << "\" ]" << std::endl;
    indent(out, indent_level + 1);
    out << "pos [ " << pos[0] << " " << pos[1] << " " << pos[2] << " ]" << std::endl;
    indent(out, indent_level + 1);
    if (temp_hpr_fix) {
        out << "nhpr [ ";
    } else {
        out << "hpr [ ";
    }
    out << hpr[0] << " " << hpr[1] << " " << hpr[2] << " ]" << std::endl;
    if (street_color != LVecBase4f(1.0, 1.0, 1.0, 1.0)) {
        indent(out, indent_level + 1);
        out << "color [ " << street_color[0] << " " << street_color[1] << " " << street_color[2] << " " << street_color[3] << " ]" << std::endl;
    }
    if (sidewalk_color != LVecBase4f(1.0, 1.0, 1.0, 1.0)) {
        indent(out, indent_level + 1);
        out << "color [ " << sidewalk_color[0] << " " << sidewalk_color[1] << " " << sidewalk_color[2] << " " << sidewalk_color[3] << " ]" << std::endl;
    }
    if (curb_color != LVecBase4f(1.0, 1.0, 1.0, 1.0)) {
        indent(out, indent_level + 1);
        out << "color [ " << curb_color[0] << " " << curb_color[1] << " " << curb_color[2] << " " << curb_color[3] << " ]" << std::endl;
    }
    indent(out, indent_level + 1);
    out << "texture [ \"" << street_texture << "\" ]" << std::endl;
    out << "texture [ \"" << sidewalk_texture << "\" ]" << std::endl;
    out << "texture [ \"" << curb_texture << "\" ]" << std::endl;
    for (pvector<PT(DNAGroup)>::iterator it = children.begin(); it != children.end(); ++it) {
        (*it)->write(out, store, indent_level + 1);
    }
    indent(out, indent_level);
    out << "]" << std::endl;
}