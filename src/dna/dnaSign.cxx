// Filename: dnaSign.cxx
// Created by:  skyler (2001-30-01)
//
////////////////////////////////////////////////////////////////////

#include "dnaSign.h"
#include "nodePath.h"
#include "decalEffect.h"
#include "sceneGraphReducer.h"
#include "config_linmath.h"

////////////////////////////////////////////////////////////////////
// Static variables
////////////////////////////////////////////////////////////////////
TypeHandle DNASign::_type_handle;

////////////////////////////////////////////////////////////////////
//     Function: DNASign::Constructor
//       Access: Public
//  Description:
////////////////////////////////////////////////////////////////////
DNASign::DNASign(const std::string &initial_name) :
  DNANode(initial_name)
{
  _code = "";
  _color.set(1.0, 1.0, 1.0, 1.0);
}

////////////////////////////////////////////////////////////////////
//     Function: DNASign::Copy Constructor
//       Access: Public
//  Description:
////////////////////////////////////////////////////////////////////
DNASign::DNASign(const DNASign &sign) :
  DNANode(sign)
{
  _code = sign.get_code();
  _color = sign.get_color();
}


////////////////////////////////////////////////////////////////////
//     Function: DNASign::traverse
//       Access: Public
//  Description:
////////////////////////////////////////////////////////////////////
NodePath DNASign::traverse(NodePath &parent, DNAStorage *store, int editing) {
  // Make this a decal onto the wall

  // First look for a node called sign_decal
  // If it is there, use it otherwise just use the _front node like the door does
  NodePath building_front = parent.find("**/sign_decal");
  if (building_front.is_empty()) {
    building_front = parent.find("**/*_front");
  }

  // If the building front is empty, Our sign won't work no matter what.
  nassertr(!building_front.is_empty(), parent);

  // If the _front is not a GeomNode, look for the first geom node under that
  if (!building_front.node()->is_geom_node()) {
    building_front = building_front.find("**/+GeomNode");
  }

  PandaNode *node = building_front.node();
  node->set_effect(DecalEffect::make());

  // Try to find this sign in the node map
  NodePath sign_node_path;
  if (!_code.empty()) {
    sign_node_path = (store->find_node(_code)).copy_to(building_front);
    if (sign_node_path.is_empty()) {
      nout << "Sign not found in storage: " << _code << std::endl;
      return parent;
    }
    sign_node_path.node()->set_name("sign");
  } else {
    sign_node_path = building_front.attach_new_node(new ModelNode("sign"));
  }
  nassertr(!sign_node_path.is_empty(), parent);

#ifndef DEPTH_FIX
  // Turn off the writing of z-buffer information:
  sign_node_path.set_depth_write(0);
  //sign_node_path.node()->set_name("sign");
#endif

  // The Sign_origin is a special node in the model with a local
  // origin that we position the sign wrt
  NodePath sign_origin = parent.find("**/*sign_origin");
  nassertr(!sign_origin.is_empty(), parent);

  // Place the sign on the building:
  sign_node_path.set_pos_hpr_scale(sign_origin, _pos, _hpr, _scale);
  sign_node_path.set_color(_color);

  // Traverse each node in our vector
  pvector<PT(DNAGroup)>::iterator i = _group_vector.begin();
  for(; i != _group_vector.end(); ++i) {
    PT(DNAGroup) group = *i;
    group->traverse(sign_node_path, store, editing);
  }
  if (editing) {
    // Remember that this nodepath is associated with this dna group
    store->store_DNAGroup(sign_node_path.node(), this);
  } else {
    // Remember the sign origin for later.  For this we have to find
    // the building node, which is usually parent, but might be
    // farther up.
    NodePath building = parent;
    while (!building.is_empty() && 
           (building.get_name().empty() ||
            building.get_name().substr(0, 2) != "tb")) {
      building = building.get_parent();
    }
    // We only want do this is we have found a building and it is a landmark building (avoids billboards)
    if ((!building.is_empty()) && strstr(building.get_name().c_str(), "landmark") != 0) {
      std::string block=store->get_block(building.get_name());
      store->store_block_sign_transform(block, sign_origin.get_transform(building)->get_mat());
    }

    // Get rid of the transitions and flatten
    if (!sign_node_path.is_empty()) {
      SceneGraphReducer gr;
      gr.apply_attribs(sign_node_path.node());
      gr.flatten(sign_node_path.node(), ~0);
    }
  }
  return sign_node_path;
}


////////////////////////////////////////////////////////////////////
//     Function: DNASign::write
//       Access: Public
//  Description: Writes the group and all children to output
////////////////////////////////////////////////////////////////////
void DNASign::write(std::ostream &out, DNAStorage *store, int indent_level) const {
  indent(out, indent_level) << "sign [\n";

  // Write out all properties
  if (!_code.empty()) {
    indent(out, indent_level + 1) << "code [ " <<
      '"' << _code << '"' << " ]\n";
  }
  if (!_color.almost_equal(LVecBase4f(1.0, 1.0, 1.0, 1.0))) {
    indent(out, indent_level + 1) << "color [ " <<
      _color[0] << " " << _color[1] << " " <<
      _color[2] << " " << _color[3] << " ]\n";
  }
  if (!_pos.almost_equal(LVecBase3f::zero())) {
    indent(out, indent_level + 1) << "pos [ " <<
      _pos[0] << " " << _pos[1] << " " << _pos[2] << " ]\n";
  }
  if (!_hpr.almost_equal(LVecBase3f::zero())) {
    if (temp_hpr_fix) {
      indent(out, indent_level + 1) << "nhpr [ " <<
        _hpr[0] << " " << _hpr[1] << " " << _hpr[2] << " ]\n";
    } else {
      indent(out, indent_level + 1) << "hpr [ " <<
        _hpr[0] << " " << _hpr[1] << " " << _hpr[2] << " ]\n";
    }
  }
  if (!_scale.almost_equal(LVecBase3f(1.0, 1.0, 1.0))) {
    indent(out, indent_level + 1) << "scale [ " <<
      _scale[0] << " " << _scale[1] << " " << _scale[2] << " ]\n";
  }

  // Write all the children
  pvector<PT(DNAGroup)>::const_iterator i = _group_vector.begin();
  for(; i != _group_vector.end(); ++i) {
    // Traverse each node in our vector
    PT(DNAGroup) group = *i;
    group->write(out, store, indent_level + 1);
  }

  indent(out, indent_level) << "]\n";
}

////////////////////////////////////////////////////////////////////
//     Function: DNASign::write
//       Access: Public
//  Description: Writes the group to the Datagram.
////////////////////////////////////////////////////////////////////
void DNASign::write(Datagram &datagram, DNAStorage *store) const {
    datagram.add_uint8(TYPECODE_DNASIGN);
    bool write_pos = !_pos.almost_equal(LVecBase3f::zero());
    bool write_hpr = !_hpr.almost_equal(LVecBase3f::zero());
    bool write_scale = !_scale.almost_equal(LVecBase3f(1.0, 1.0, 1.0));
    bool write_color = !_color.almost_equal(LVecBase4f(1.0, 1.0, 1.0, 1.0));

    // Set the bits in our bit flags. Each used bit corresponds to if
    // something was written.
    uint8_t flags = 0; //0b00000000 - This is here for a bit reference.
    flags |= write_pos << 0;
    flags |= write_hpr << 1;
    flags |= write_scale << 2;
    flags |= write_color << 3;

    datagram.add_uint8(flags);
    datagram.add_string(get_name());
    datagram.add_string(get_code());
    if (write_pos) {
        datagram.add_stdfloat(_pos.get_z());
        datagram.add_stdfloat(_pos.get_y());
        datagram.add_stdfloat(_pos.get_x());
    }
    if (write_hpr) {
        datagram.add_bool(temp_hpr_fix);
        datagram.add_stdfloat(_hpr.get_z());
        datagram.add_stdfloat(_hpr.get_y());
        datagram.add_stdfloat(_hpr.get_x());
    }
    if (write_scale) {
        datagram.add_stdfloat(_scale.get_z());
        datagram.add_stdfloat(_scale.get_y());
        datagram.add_stdfloat(_scale.get_x());
    }
     if (write_color) {
        datagram.add_stdfloat(_color.get_w());
        datagram.add_stdfloat(_color.get_z());
        datagram.add_stdfloat(_color.get_y());
        datagram.add_stdfloat(_color.get_x());
     }
  
    // Write all the children
    pvector<PT(DNAGroup)>::const_iterator i = _group_vector.begin();
    for(; i != _group_vector.end(); ++i) {
        // Traverse each node in our vector
        PT(DNAGroup) group = *i;
        group->write(datagram, store);
    }

    // We add a return marker to inform our dna reader that this grouping is over.
    datagram.add_uint8(TYPECODE_RETURNMARKER);
}

////////////////////////////////////////////////////////////////////
//     Function: DNASign::make_from_dgi
//       Access: Public
//  Description: Sets up the group from the Datagram Iterator.
////////////////////////////////////////////////////////////////////
void DNASign::make_from_dgi(DatagramIterator &dgi, DNAStorage *store) {
    // Read off what was written from the bit flags.
    uint8_t flags = dgi.get_uint8();
    bool wrote_pos = (flags >> 0) & 1U;
    bool wrote_hpr = (flags >> 1) & 1U;
    bool wrote_scale = (flags >> 2) & 1U;
    bool wrote_color = (flags >> 3) & 1U;

    set_name(dgi.get_string());
    set_code(dgi.get_string());
    if (wrote_pos) {
        set_pos(LVecBase3f(dgi.get_stdfloat(), dgi.get_stdfloat(), dgi.get_stdfloat()));
    }
    if (wrote_hpr) {
        // Just because normally old hpr is scrapped, 
        // Doesn't mean we don't want to convert it still.
        bool is_hpr_fixed = dgi.get_bool();
        if (temp_hpr_fix && !is_hpr_fixed) {
            set_hpr(old_to_new_hpr(LVecBase3f(dgi.get_stdfloat(), dgi.get_stdfloat(), dgi.get_stdfloat())));
        } else if (!temp_hpr_fix && is_hpr_fixed) {
            set_hpr(new_to_old_hpr(LVecBase3f(dgi.get_stdfloat(), dgi.get_stdfloat(), dgi.get_stdfloat())));
        } else {
            set_hpr(LVecBase3f(dgi.get_stdfloat(), dgi.get_stdfloat(), dgi.get_stdfloat()));
        }
    }
    if (wrote_scale) {
        set_scale(LVecBase3f(dgi.get_stdfloat(), dgi.get_stdfloat(), dgi.get_stdfloat()));
    }
    if (wrote_color) {
        set_color(LColorf(dgi.get_stdfloat(), dgi.get_stdfloat(), dgi.get_stdfloat(), dgi.get_stdfloat()));
    }
}

////////////////////////////////////////////////////////////////////
//     Function: DNASign::make_copy
//       Access: Public
//  Description: Copies all the children into our own vector
////////////////////////////////////////////////////////////////////
DNAGroup* DNASign::make_copy() {
  return new DNASign(*this);
}
