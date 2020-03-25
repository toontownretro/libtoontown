#include "DNAFlatDoor.h"
#include "DNAStorage.h"

TypeHandle DNAFlatDoor::_type_handle;

DNAFlatDoor::DNAFlatDoor(std::string initial_name) : DNADoor(initial_name) {

}

DNAFlatDoor::DNAFlatDoor(const DNAFlatDoor &door) : DNADoor(door) {

}

DNAFlatDoor::~DNAFlatDoor() {

}

NodePath DNAFlatDoor::traverse(NodePath &parent, DNAStorage *store, int editing) {
    NodePath node = store->find_node(code);
    node = node.copy_to(parent);

    node.set_scale(LVecBase3f(1.0, 1.0, 1.0));
    node.set_pos_hpr(LVecBase3f(0.5, 0.0, 0.0), LVecBase3f(0.0, 0.0, 0.0));

    if (editing) {
        parent.set_effect(DecalEffect::make());
        PT(DNAGroup) PT_this = (DNAGroup*)this;
        PT(PandaNode) store_node = node.node();
        store->store_DNAGroup(store_node, PT_this);
    }
    return node;
}

void DNAFlatDoor::write(std::ostream &out, DNAStorage *store, int indent_level) {
    indent(out, indent_level);
    out << "flat_door [" << std::endl;
    indent(out, indent_level + 1);
    out << "code [ \"" << code << "\" ]" << std::endl;
    indent(out, indent_level + 1);
    out << "color [ " << color[0] << " " << color[1] << " " << color[2] << " " << color[3] << " ]" << std::endl;
    indent(out, indent_level);
    out << "]" << std::endl;
}