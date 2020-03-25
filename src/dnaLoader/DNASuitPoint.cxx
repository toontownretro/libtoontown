#include "DNASuitPoint.h"

TypeHandle DNASuitPoint::_type_handle;

DNASuitPoint::DNASuitPoint(int index, DNASuitPointType type, LPoint3f pos, int lb_index) {
    this->index = index;
    this->type = type;
    this->pos = pos;
    this->lb_index = lb_index;
}

DNASuitPoint::~DNASuitPoint() {

}

int DNASuitPoint::get_graph_id() {
    return graph_id;
}

int DNASuitPoint::get_index() {
    return index;
}

int DNASuitPoint::get_landmark_building_index() {
    return lb_index;
}

DNASuitPoint::DNASuitPointType DNASuitPoint::get_point_type() {
    return type;
}

LPoint3f DNASuitPoint::get_pos() {
    return pos;
}

bool DNASuitPoint::is_terminal() {
    return type - 1 <= 1;
}

void DNASuitPoint::output(std::ostream &out) {
    out << "<" << index << ", ";
    switch (type) {
        case DNASuitPointType::STREET_POINT:
          out << "STREET_POINT";
          break;
        case DNASuitPointType::FRONT_DOOR_POINT:
          out << "FRONT_DOOR_POINT";
          break;
        case DNASuitPointType::SIDE_DOOR_POINT:
          out << "SIDE_DOOR_POINT";
          break;
        case DNASuitPointType::COGHQ_IN_POINT:
          out << "COGHQ_IN_POINT";
          break;
        case DNASuitPointType::COGHQ_OUT_POINT:
          out << "COGHQ_OUT_POINT";
          break;
        default:
          out << "**invalid**";
          break;
    }
    out << ", " << pos[0] << " " << pos[1] << " " << pos[2];
    if (lb_index >= 0) {
        out << ", " << lb_index;
    }
    out << ">";
}

void DNASuitPoint::set_graph_id(int graph_id) {
    this->graph_id = graph_id;
}

void DNASuitPoint::set_index(int index) {
    this->index = index;
}

void DNASuitPoint::set_landmark_building_index(int lb_index) {
    this->lb_index = lb_index;
}

void DNASuitPoint::set_point_type(DNASuitPointType type) {
    this->type = type;
}

void DNASuitPoint::set_pos(const LPoint3f &pos) {
    this->pos = pos;
}

void DNASuitPoint::write(std::ostream &out, int indent_level) {
    indent(out, indent_level);
    out << "store_suit_point [ " << index << ", ";
    switch (type) {
        case DNASuitPointType::STREET_POINT:
          out << "STREET_POINT";
          break;
        case DNASuitPointType::FRONT_DOOR_POINT:
          out << "FRONT_DOOR_POINT";
          break;
        case DNASuitPointType::SIDE_DOOR_POINT:
          out << "SIDE_DOOR_POINT";
          break;
        case DNASuitPointType::COGHQ_IN_POINT:
          out << "COGHQ_IN_POINT";
          break;
        case DNASuitPointType::COGHQ_OUT_POINT:
          out << "COGHQ_OUT_POINT";
          break;
        default:
          out << "**invalid**";
          break;
    }
    out << ", " << pos[0] << " " << pos[1] << " " << pos[2];
    if (lb_index >= 0) {
        out << ", " << lb_index;
    }
    out << " ]" << std::endl;
}