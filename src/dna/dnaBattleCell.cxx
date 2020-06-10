#include "dnaBattleCell.h"

TypeHandle DNABattleCell::_type_handle;

DNABattleCell::DNABattleCell(float width, float height, LPoint3f pos) {
    this->width = width;
    this->height = height;
    this->pos = pos;
}

DNABattleCell::~DNABattleCell() {

}

double DNABattleCell::get_height() {
    return height;
}

LPoint3f DNABattleCell::get_pos() {
    return pos;
}

double DNABattleCell::get_width() {
    return width;
}

void DNABattleCell::set_pos(LPoint3f pos) {
    this->pos = pos;
}

void DNABattleCell::set_width_height(float width, float height) {
    this->width = width;
    this->height = height;
}

void DNABattleCell::output(std::ostream &out) {
    out << "Width: " << width << " Height: " << height << " Pos: " << pos[0] << " " << pos[1] << " " << pos[2];
}

NodePath DNABattleCell::traverse(NodePath &parent, DNAStorage *store, int editing) {
    return parent;
}

void DNABattleCell::write(std::ostream &out, DNAStorage *store, int indent_level) {
    indent(out, indent_level);
    out << "battle_cell [ " << width << " " << height << " " << pos[0] << " " << pos[1] << " " << pos[2] << " ]" << std::endl;
}