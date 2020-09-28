// Filename: dnaProp.cxx
// Created by:  shochet (28Mar00)
//
////////////////////////////////////////////////////////////////////

#include "dnaProp.h"
#include "sceneGraphReducer.h"
#include "modelNode.h"
#include "config_linmath.h"

////////////////////////////////////////////////////////////////////
// Static variables
////////////////////////////////////////////////////////////////////
TypeHandle DNAProp::_type_handle;


////////////////////////////////////////////////////////////////////
//     Function: DNAProp::Constructor
//       Access: Public
//  Description:
////////////////////////////////////////////////////////////////////
DNAProp::DNAProp(const std::string &initial_name) :
  DNANode(initial_name)
{
  _code = "";
  _color.set(1.0, 1.0, 1.0, 1.0);
}

////////////////////////////////////////////////////////////////////
//     Function: DNAProp::Copy Constructor
//       Access: Public
//  Description:
////////////////////////////////////////////////////////////////////
DNAProp::DNAProp(const DNAProp &prop) :
  DNANode(prop)
{
  _code = prop.get_code();
  _color = prop.get_color();
}


////////////////////////////////////////////////////////////////////
//     Function: DNAProp::traverse
//       Access: Public
//  Description:
////////////////////////////////////////////////////////////////////
NodePath DNAProp::traverse(NodePath &parent, DNAStorage *store, int editing) {
  NodePath prop_node_path;

  // A code of DCS means an empty reference node
  if (_code == "DCS") {
    PT(ModelNode) model_node = new ModelNode(get_name());
    model_node->set_preserve_transform(ModelNode::PT_net);
    prop_node_path = parent.attach_new_node(model_node);
  } else {
    // Try to find this prop in the node map
    NodePath source_prop = store->find_node(_code);
    if (source_prop.is_empty()) {
      // No such prop to be found.  Should we issue a warning?
      return NodePath();
    }
    prop_node_path = source_prop.copy_to(parent);
    if (source_prop.has_tag("DNARoot")) {
      prop_node_path.set_tag("DNARoot", source_prop.get_tag("DNARoot"));
    }
    if (source_prop.has_tag("DNACode")) {
      prop_node_path.set_tag("DNACode", source_prop.get_tag("DNACode"));
    }
    prop_node_path.node()->set_name(get_name());
  }

  prop_node_path.set_pos_hpr_scale(_pos, _hpr, _scale);

  // Note: this is a color scale, not a regular set color
  // so we can keep any poly color or vertex color that is
  // already there
  prop_node_path.set_color_scale(_color);

  // Traverse each node in our vector
  pvector<PT(DNAGroup)>::iterator i = _group_vector.begin();
  for(; i != _group_vector.end(); ++i) {
    PT(DNAGroup) group = *i;
    group->traverse(prop_node_path, store, editing);
  }

  if (editing) {
    // Remember that this nodepath is associated with this dna group
    store->store_DNAGroup(prop_node_path.node(), this);
  }

  return prop_node_path;
}



////////////////////////////////////////////////////////////////////
//     Function: DNAProp::write
//       Access: Public
//  Description: Writes the group and all children to output
////////////////////////////////////////////////////////////////////
void DNAProp::write(std::ostream &out, DNAStorage *store, int indent_level) const {
  indent(out, indent_level) << "prop ";
  out << '"' << get_name() << '"' << " [\n";

  // Write out all properties
  indent(out, indent_level + 1) << "code [ " <<
    '"' << _code << '"' << " ]\n";
  indent(out, indent_level + 1) << "pos [ " <<
    _pos[0] << " " << _pos[1] << " " << _pos[2] << " ]\n";
  if (temp_hpr_fix) {
    indent(out, indent_level + 1) << "nhpr [ " <<
      _hpr[0] << " " << _hpr[1] << " " << _hpr[2] << " ]\n";
  } else {
    indent(out, indent_level + 1) << "hpr [ " <<
      _hpr[0] << " " << _hpr[1] << " " << _hpr[2] << " ]\n";
  }

  // Only write out scale if it is not unity. This saves uneccessary work
  if (!_scale.almost_equal(LVecBase3f(1.0, 1.0, 1.0))) {
    indent(out, indent_level + 1) << "scale [ " <<
      _scale[0] << " " << _scale[1] << " " << _scale[2] << " ]\n";
  }
  // Only write out color if it is not white. This saves uneccessary work
  if (!_color.almost_equal(LVecBase4f(1.0, 1.0, 1.0, 1.0))) {
    indent(out, indent_level + 1) << "color [ " <<
      _color[0] << " " << _color[1] << " " << _color[2] << " " << _color[3] <<
      " ]\n";
  }

  // Write all the children
  pvector<PT(DNAGroup)>::const_iterator i = _group_vector.begin();
  for(; i != _group_vector.end(); ++i) {
    // Traverse each node in our vector
    PT(DNAGroup) group = *i;
    group->write(out, store, indent_level + 1);
  }

  // We dont traverse our children because we do not have any
  indent(out, indent_level) << "]\n";

}

////////////////////////////////////////////////////////////////////
//     Function: DNAProp::write
//       Access: Public
//  Description: Writes the group to the Datagram.
////////////////////////////////////////////////////////////////////
void DNAProp::write(Datagram &datagram, DNAStorage *store) const {
    datagram.add_uint8(TYPECODE_DNAPROP);
    datagram.add_string(get_name());
    datagram.add_string(get_code());
    
    // Write if we wrote scale and color, Then include if we have the hpr fix.
    bool write_scale = !_scale.almost_equal(LVecBase3f(1.0, 1.0, 1.0));
    bool write_color = !_color.almost_equal(LVecBase4f(1.0, 1.0, 1.0, 1.0));
    datagram.add_bool(write_scale);
    datagram.add_bool(write_color);
    datagram.add_bool(temp_hpr_fix);
    
    datagram.add_stdfloat(_pos.get_z());
    datagram.add_stdfloat(_pos.get_y());
    datagram.add_stdfloat(_pos.get_x());
    datagram.add_stdfloat(_hpr.get_z());
    datagram.add_stdfloat(_hpr.get_y());
    datagram.add_stdfloat(_hpr.get_x());
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
//     Function: DNAProp::make_from_dgi
//       Access: Public
//  Description: Sets up the group from the Datagram Iterator.
////////////////////////////////////////////////////////////////////
void DNAProp::make_from_dgi(DatagramIterator &dgi, DNAStorage *store) {
    set_name(dgi.get_string());
    set_code(dgi.get_string());
    
    // Get if there is scale and color written and if the hpr is fixed.
    bool wrote_scale = dgi.get_bool();
    bool wrote_color = dgi.get_bool();
    bool is_hpr_fixed = dgi.get_bool();
    
    set_pos(LVecBase3f(dgi.get_stdfloat(), dgi.get_stdfloat(), dgi.get_stdfloat()));
    // Just because normally old hpr is scrapped, 
    // Doesn't mean we don't want to convert it still.
    if (temp_hpr_fix && !is_hpr_fixed) {
        set_hpr(old_to_new_hpr(LVecBase3f(dgi.get_stdfloat(), dgi.get_stdfloat(), dgi.get_stdfloat())));
    } else if (!temp_hpr_fix && is_hpr_fixed) {
        set_hpr(new_to_old_hpr(LVecBase3f(dgi.get_stdfloat(), dgi.get_stdfloat(), dgi.get_stdfloat())));
    } else {
        set_hpr(LVecBase3f(dgi.get_stdfloat(), dgi.get_stdfloat(), dgi.get_stdfloat()));
    }
    if (wrote_scale) {
        set_scale(LVecBase3f(dgi.get_stdfloat(), dgi.get_stdfloat(), dgi.get_stdfloat()));
    }
    if (wrote_color) {
        set_color(Colorf(dgi.get_stdfloat(), dgi.get_stdfloat(), dgi.get_stdfloat(), dgi.get_stdfloat()));
    }
}

////////////////////////////////////////////////////////////////////
//     Function: DNAProp::make_copy
//       Access: Public
//  Description: Copies all the children into our own vector
////////////////////////////////////////////////////////////////////
DNAGroup* DNAProp::make_copy() {
  return new DNAProp(*this);
}