// Filename: dnaSignGraphic.cxx
// Created by:  skyler (2001-30-01)
//
////////////////////////////////////////////////////////////////////

#include "dnaSignGraphic.h"
#include "dnaSignBaseline.h"
#include "nodePath.h"
#include "decalEffect.h"
#include "config_linmath.h"
#include "dcast.h"

////////////////////////////////////////////////////////////////////
// Static variables
////////////////////////////////////////////////////////////////////
TypeHandle DNASignGraphic::_type_handle;

////////////////////////////////////////////////////////////////////
//     Function: DNASignGraphic::Constructor
//       Access: Public
//  Description:
////////////////////////////////////////////////////////////////////
DNASignGraphic::DNASignGraphic(const std::string &initial_name) :
  DNANode(initial_name)
{
  _code = "";
  _color.set(1.0, 1.0, 1.0, 1.0);
  _width = 0.0;
  _height = 0.0;
  _use_baseline_color = true;
}

////////////////////////////////////////////////////////////////////
//     Function: DNASignGraphic::Copy Constructor
//       Access: Public
//  Description:
////////////////////////////////////////////////////////////////////
DNASignGraphic::DNASignGraphic(const DNASignGraphic &graphic) :
  DNANode(graphic)
{
  _code = graphic.get_code();
  _color = graphic.get_color();
  _width = graphic.get_width();
  _height = graphic.get_height();
  _use_baseline_color = graphic._use_baseline_color;
}


////////////////////////////////////////////////////////////////////
//     Function: DNASignGraphic::traverse
//       Access: Public
//  Description:
////////////////////////////////////////////////////////////////////
NodePath DNASignGraphic::traverse(NodePath &parent, DNAStorage *store, int editing) {
  // Make this a decal onto the baseline.  Walk up to the previous
  // GeomNode in the parent history.
  NodePath geom_parent = parent;
  PandaNode *node = geom_parent.node();
  while (!node->is_geom_node() && !geom_parent.is_singleton()) {
    geom_parent = geom_parent.get_parent();
    node = geom_parent.node();
  }
  if (node->is_geom_node()) {
    node->set_effect(DecalEffect::make());
  }

  // Try to find this sign graphic in the node map
  NodePath graphic_node_path = (store->find_node(_code)).copy_to(parent);

  PT(DNASignBaseline) baseline = DCAST(DNASignBaseline, get_parent());

  // Use the baseline color, if available:
  Colorf color = _color;
  if (_use_baseline_color) {
    color = baseline->get_color();
  }

  LVector3f bl_pos = _pos;
  LVector3f bl_hpr = _hpr;
  LVector3f bl_scale = _scale;
  baseline->baseline_next_pos_hpr_scale(bl_pos, bl_hpr, bl_scale,
    LVector3f(get_width(), 0.0, get_height()));

  // Place the graphic on the baseline:
  graphic_node_path.set_pos_hpr_scale(parent,
           bl_pos,
           bl_hpr,
           bl_scale);
  graphic_node_path.set_color(color);

  // Traverse each node in our vector
  pvector<PT(DNAGroup)>::iterator i = _group_vector.begin();
  for(; i != _group_vector.end(); ++i) {
    PT(DNAGroup) group = *i;
    group->traverse(graphic_node_path, store, editing);
  }

  if (editing) {
    // Remember that this nodepath is associated with this dna group
    store->store_DNAGroup(graphic_node_path.node(), this);
  }

  return graphic_node_path;
}



////////////////////////////////////////////////////////////////////
//     Function: DNASignGraphic::write
//       Access: Public
//  Description: Writes the group and all children to output
////////////////////////////////////////////////////////////////////
void DNASignGraphic::write(std::ostream &out, DNAStorage *store, int indent_level) const {
  indent(out, indent_level) << "graphic [\n";

  // Write out all properties
  indent(out, indent_level + 1) << "code [ " <<
    '"' << _code << '"' << " ]\n";
  if (_width) {
    indent(out, indent_level + 1) << "width [ " <<
      _width << " ]\n";
  }
  if (_height) {
    indent(out, indent_level + 1) << "height [ " <<
      _height << " ]\n";
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

  indent(out, indent_level) << "]\n";
}

////////////////////////////////////////////////////////////////////
//     Function: DNASignGraphic::write
//       Access: Public
//  Description: Writes the group to the Datagram.
////////////////////////////////////////////////////////////////////
void DNASignGraphic::write(Datagram &datagram, DNAStorage *store) const {
    datagram.add_uint8(TYPECODE_DNASIGNGRAPHIC);
    bool write_pos = !_pos.almost_equal(LVecBase3f::zero());
    bool write_hpr = !_hpr.almost_equal(LVecBase3f::zero());
    bool write_scale = !_scale.almost_equal(LVecBase3f(1.0, 1.0, 1.0));
    bool write_color = !_color.almost_equal(LVecBase4f(1.0, 1.0, 1.0, 1.0));
    bool write_width = _width;
    bool write_height = _height;
    datagram.add_bool(write_pos);
    datagram.add_bool(write_hpr);
    datagram.add_bool(write_scale);
    datagram.add_bool(write_color);
    datagram.add_bool(write_width);
    datagram.add_bool(write_height);
    datagram.add_string(get_name());
    datagram.add_string(get_code());
    if (write_pos) {
        datagram.add_stdfloat(_pos.get_x());
        datagram.add_stdfloat(_pos.get_y());
        datagram.add_stdfloat(_pos.get_z());
    }
    if (write_hpr) {
        datagram.add_bool(temp_hpr_fix);
        datagram.add_stdfloat(_hpr.get_x());
        datagram.add_stdfloat(_hpr.get_y());
        datagram.add_stdfloat(_hpr.get_z());
    }
    if (write_scale) {
        datagram.add_stdfloat(_scale.get_x());
        datagram.add_stdfloat(_scale.get_y());
        datagram.add_stdfloat(_scale.get_z());
    }
     if (write_color) {
        datagram.add_stdfloat(_color.get_x());
        datagram.add_stdfloat(_color.get_y());
        datagram.add_stdfloat(_color.get_z());
        datagram.add_stdfloat(_color.get_w());
     }
     if (write_width) {
        datagram.add_stdfloat(_width);
     }
     if (write_height) {
        datagram.add_stdfloat(_height);
     }
  
    // Write all the children
    pvector<PT(DNAGroup)>::const_iterator i = _group_vector.begin();
    for(; i != _group_vector.end(); ++i) {
        // Traverse each node in our vector
        PT(DNAGroup) group = *i;
        group->write(datagram, store);
    }
}

////////////////////////////////////////////////////////////////////
//     Function: DNASignGraphic::make_from_dgi
//       Access: Public
//  Description: Sets up the group from the Datagram Iterator.
////////////////////////////////////////////////////////////////////
void DNASignGraphic::make_from_dgi(DatagramIterator &dgi, DNAStorage *store) {
    bool wrote_pos = dgi.get_bool();
    bool wrote_hpr = dgi.get_bool();
    bool wrote_scale = dgi.get_bool();
    bool wrote_color = dgi.get_bool();
    bool wrote_width = dgi.get_bool();
    bool wrote_height = dgi.get_bool();
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
    if (wrote_width) {
        set_width(dgi.get_stdfloat());
    }
    if (wrote_height) {
        set_height(dgi.get_stdfloat());
    }
}

////////////////////////////////////////////////////////////////////
//     Function: DNASignGraphic::make_copy
//       Access: Public
//  Description: Copies all the children into our own vector
////////////////////////////////////////////////////////////////////
DNAGroup* DNASignGraphic::make_copy() {
  return new DNASignGraphic(*this);
}
