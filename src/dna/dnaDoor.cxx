#include "dnaDoor.h"
#include "dnaStorage.h"

TypeHandle DNADoor::_type_handle;

DNADoor::DNADoor(std::string initial_name) : DNAGroup(initial_name) {
    color = LVecBase4f(1.0, 1.0, 1.0, 1.0);
}

DNADoor::DNADoor(const DNADoor &door) : DNAGroup(door) {
    code = door.code;
    color = door.color;
}

DNADoor::~DNADoor() {

}

std::string DNADoor::get_code() {
    return code;
}

LVecBase4f DNADoor::get_color() {
    return color;
}

void DNADoor::set_code(std::string &code) {
    this->code = code;
}

void DNADoor::set_color(const LVecBase4f &color) {
    this->color = color;
}

void DNADoor::setup_door(NodePath &node, const NodePath &parent, const NodePath &door_origin, DNAStorage *store, std::string &block, const LVecBase4f &color) {
    node.set_pos_hpr_scale(door_origin, LVecBase3f(0.0, 0.0, 0.0), LVecBase3f(0.0, 0.0, 0.0), LVecBase3f(1.0, 1.0, 1.0));
    node.set_color(color);

    NodePath door_hole_left = node.find("door_*_hole_left");
    door_hole_left.set_name("doorFrameHoleLeft");

    NodePath door_hole_right = node.find("door_*_hole_right");
    door_hole_right.set_name("doorFrameHoleRight");

    NodePath door_right = node.find("door_*_right");
    door_right.set_name("rightDoor");

    NodePath door_left = node.find("door_*_left");
    door_left.set_name("leftDoor");

    NodePath door_flat = node.find("door_*_flat");
    if (!door_flat.is_empty()) {
        door_hole_left.wrt_reparent_to(door_flat);
        door_hole_right.wrt_reparent_to(door_flat);

        door_flat.set_effect(DecalEffect::make());

        door_right.wrt_reparent_to(parent);
        door_left.wrt_reparent_to(parent);

        door_right.hide();
        door_left.hide();
    }

    door_hole_left.hide();
    door_hole_right.hide();

    door_right.set_color(color);
    door_left.set_color(color);
    door_hole_left.set_color(LVecBase4f(0.0, 0.0, 0.0, 1.0));
    door_hole_right.set_color(LVecBase4f(0.0, 0.0, 0.0, 1.0));

    NodePath door_trigger = node.find("door_*_trigger");
    door_trigger.wrt_reparent_to(parent);
    door_trigger.set_name("door_trigger_" + block);
}

NodePath DNADoor::traverse(NodePath &parent, DNAStorage *store, int editing) {
    NodePath _front_path = parent.find("**/*_front");
    if (!_front_path.get_node(0)->is_geom_node()) {
        _front_path = _front_path.find("**/+GeomNode");
    }

    _front_path.set_effect(DecalEffect::make());
    NodePath node = store->find_node(code);
    if (node.is_empty()) {
        dna_cat.error() << "Door not found: " << code << std::endl;
        return parent;
    }
    node = node.copy_to(_front_path);

    NodePath door_origin = parent.find("**/*door_origin");
    std::string block = store->get_block(parent.get_name());

    setup_door(node, parent, door_origin, store, block, color);
    store->store_block_door_pos_hpr(block, door_origin.get_pos(), door_origin.get_hpr());

    if (editing) {
        PT(DNAGroup) PT_this = (DNAGroup*)this;
        PT(PandaNode) store_node = node.node();
        store->store_DNAGroup(store_node, PT_this);
    }

    return node;
}

void DNADoor::write(std::ostream &out, DNAStorage *store, int indent_level) {
    indent(out, indent_level);
    out << "door [" << std::endl;
    indent(out, indent_level + 1);
    out << "code [ \"" << code << "\" ]" << std::endl;
    indent(out, indent_level + 1);
    out << "color [ " << color[0] << " " << color[1] << " " << color[2] << " " << color[3] << " ]" << std::endl;
    indent(out, indent_level);
    out << "]" << std::endl;
}