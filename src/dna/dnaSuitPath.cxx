#include "dnaSuitPath.h"

TypeHandle DNASuitPath::_type_handle;

/**
 *
 */
DNASuitPath::DNASuitPath() {

}

/**
 *
 */
DNASuitPath::DNASuitPath(int reserve_length) {
    points.reserve(reserve_length);
}

/**
 *
 */
DNASuitPath::DNASuitPath(const DNASuitPath &path) {
    copy(path);
}

/**
 *
 */
DNASuitPath::~DNASuitPath() {

}

/**
 *
 */
void DNASuitPath::add_point(int point) {
    points.push_back(point);
}

/**
 *
 */
void DNASuitPath::copy(const DNASuitPath &path) {
    points.clear();
    for(pvector<int>::size_type i = 0; i != path.points.size(); i++) {
        points.push_back(path.points[i]);
    }
}

/**
 *
 */
int DNASuitPath::get_num_points() {
    return points.size();
}

/**
 *
 */
int DNASuitPath::get_point_index(int i) {
    return points[i];
}

/**
 *
 */
void DNASuitPath::output(std::ostream &out) {
    out << "Path: [ ";
    for(pvector<int>::size_type i = 0; i != points.size(); i++) {
        out << points[i] << " ";
    }
    out << "]";
}

/**
 *
 */
void DNASuitPath::reverse_path() {
    std::reverse(points.begin(), points.end());
}