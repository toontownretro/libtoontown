// Filename: dnaSuitPoint.cxx
// Created by:  shochet (28Jan01)
//
////////////////////////////////////////////////////////////////////

#include "dnaSuitPoint.h"


////////////////////////////////////////////////////////////////////
// Static variables
////////////////////////////////////////////////////////////////////
TypeHandle DNASuitPoint::_type_handle;

std::ostream &
operator << (std::ostream &out, DNASuitPoint::DNASuitPointType type) {
  switch (type) {
  case DNASuitPoint::STREET_POINT:
    return out << "STREET_POINT";

  case DNASuitPoint::FRONT_DOOR_POINT:
    return out << "FRONT_DOOR_POINT";

  case DNASuitPoint::SIDE_DOOR_POINT:
    return out << "SIDE_DOOR_POINT";

  case DNASuitPoint::COGHQ_IN_POINT:
    return out << "COGHQ_IN_POINT";

  case DNASuitPoint::COGHQ_OUT_POINT:
    return out << "COGHQ_OUT_POINT";
  }

  return out << "**invalid**";
}

////////////////////////////////////////////////////////////////////
//     Function: DNASuitPoint::Constructor
//       Access: Public
//  Description:
////////////////////////////////////////////////////////////////////
DNASuitPoint::DNASuitPoint(int index, DNASuitPointType type, LPoint3f pos, int lb_index) {
  // The index gets set when the point is stored in the dnaStorage
  _index = index;
  _type = type;
  _pos = pos;
  _graph_id = 0;
  _lb_index = lb_index;
}

////////////////////////////////////////////////////////////////////
//     Function: DNASuitPoint::output
//       Access: Public
//  Description: Output all the properties to the stream
////////////////////////////////////////////////////////////////////
void DNASuitPoint::output(std::ostream &out) const {
  out << "<" << _index << ", " << _type << ", " << _pos;
  if (_lb_index >= 0) {
    out << ", " << _lb_index;
  }
  out << ">";
}

////////////////////////////////////////////////////////////////////
//     Function: DNASuitPoint::write
//       Access: Public
//  Description: write the suit point back out to the dna
////////////////////////////////////////////////////////////////////
void DNASuitPoint::write(std::ostream &out, int indent_level) const {
  if (_lb_index >= 0) {
    indent(out, indent_level) << "store_suit_point [ "
                              << _index << ", "
                              << _type << ", "
                              << _pos << ", "
                              << _lb_index
                              << " ]\n";
  } else {
    indent(out, indent_level) << "store_suit_point [ "
                              << _index << ", "
                              << _type << ", "
                              << _pos << " ]\n";
  }
}

////////////////////////////////////////////////////////////////////
//     Function: DNASuitPoint::write
//       Access: Public
//  Description: write the suit point back out to the dna
////////////////////////////////////////////////////////////////////
void DNASuitPoint::write(Datagram &datagram) const {
    datagram.add_uint8(TYPECODE_DNASUITPOINT);
    datagram.add_uint8(_type);
    datagram.add_bool(_lb_index >= 0);
    if (_lb_index >= 0) {
        datagram.add_int32(_lb_index);
    }
    datagram.add_int32(_index);
    datagram.add_int32(_graph_id);
    datagram.add_stdfloat(_pos.get_x());
    datagram.add_stdfloat(_pos.get_y());
    datagram.add_stdfloat(_pos.get_z());
}

////////////////////////////////////////////////////////////////////
//     Function: DNASuitPoint::make_from_dgi
//       Access: Public
//  Description: Sets up the suit point from the Datagram Iterator.
////////////////////////////////////////////////////////////////////
void DNASuitPoint::make_from_dgi(DatagramIterator &dgi) {
    _type = (DNASuitPointType)dgi.get_uint8();
    bool has_lb_index = dgi.get_bool();
    if (has_lb_index) {
        _lb_index = dgi.get_int32();
    }
    _index = dgi.get_int32();
    _graph_id = dgi.get_int32();
    _pos.set_x(dgi.get_stdfloat());
    _pos.set_y(dgi.get_stdfloat());
    _pos.set_z(dgi.get_stdfloat());
}