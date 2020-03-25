#include "DNASuitEdge.h"

#include "DNAStorage.h"
#include "DNASuitPoint.h"

TypeHandle DNASuitEdge::_type_handle;

DNASuitEdge::DNASuitEdge(PT(DNASuitPoint) start_point, PT(DNASuitPoint) end_point, std::string zone_id) {
    this->start_point = start_point;
    this->end_point = end_point;
    this->zone_id = zone_id;
}

DNASuitEdge::~DNASuitEdge() {

}

PT(DNASuitPoint) DNASuitEdge::get_end_point() {
    return end_point;
}

PT(DNASuitPoint) DNASuitEdge::get_start_point() {
    return start_point;
}

std::string DNASuitEdge::get_zone_id() {
    return zone_id;
}

bool DNASuitEdge::operator==(const DNASuitEdge &other) {
    return start_point == other.start_point && end_point == other.end_point;
}

void DNASuitEdge::output(std::ostream &out) {
    out << "<" << start_point->get_index() << " " << end_point->get_index() << " zone " << zone_id << ">";
}

void DNASuitEdge::set_zone_id(std::string zone_id) {
    this->zone_id = zone_id;
}

void DNASuitEdge::write(std::ostream &out, DNAStorage *store, int indent_level) {
    indent(out, indent_level);
    out << "suit_edge [ " << start_point->get_index() << " " << end_point->get_index() << " ]" << std::endl;
}