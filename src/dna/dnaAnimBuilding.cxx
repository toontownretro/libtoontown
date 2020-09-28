// Filename: dnaAnimBuilding.cxx
// Created by:  gjeon (12Nov09)
//
////////////////////////////////////////////////////////////////////

#include "dnaAnimBuilding.h"
#include "sceneGraphReducer.h"
#include "modelNode.h"
#include "config_linmath.h"

////////////////////////////////////////////////////////////////////
// Static variables
////////////////////////////////////////////////////////////////////
TypeHandle DNAAnimBuilding::_type_handle;


////////////////////////////////////////////////////////////////////
//     Function: DNAAnimBuilding::Constructor
//       Access: Public
//  Description:
////////////////////////////////////////////////////////////////////
DNAAnimBuilding::DNAAnimBuilding(const std::string &initial_name) :
  DNALandmarkBuilding(initial_name)
{
  _anim = "";
}

////////////////////////////////////////////////////////////////////
//     Function: DNAAnimBuilding::Copy Constructor
//       Access: Public
//  Description:
////////////////////////////////////////////////////////////////////
DNAAnimBuilding::DNAAnimBuilding(const DNAAnimBuilding &anim_building) :
  DNALandmarkBuilding(anim_building)
{
  _code = anim_building.get_code();
  _building_type = anim_building.get_building_type();
  _wall_color = anim_building.get_wall_color();
  _title = anim_building.get_title();
  _article = anim_building.get_article();
  _anim = anim_building.get_anim();
}


////////////////////////////////////////////////////////////////////
//     Function: DNAAnimBuilding::traverse
//       Access: Public
//  Description:
////////////////////////////////////////////////////////////////////
NodePath DNAAnimBuilding::traverse(NodePath &parent, DNAStorage *store, int editing) {
  // Try to find this building in the node map
  NodePath building_node_path = (store->find_node(_code)).copy_to(parent);

  // Retain the name from the dna
  building_node_path.node()->set_name(get_name());

  // Do not set the color until we can blend
  // Actually we can blend now, but nobody is using color now
  // building_walls_node_path.set_color(_wall_color);

  // Set the building position
  building_node_path.set_pos_hpr_scale(_pos, _hpr, _scale);
  building_node_path.set_tag("DNAAnim", _anim);

  // Remember the article and title of the building, for later:
  std::string block=store->get_block(get_name());
  store->store_block_title(block, _title);
  store->store_block_article(block, _article);

  // Copy the suit building origin to the parent:
  // our type is animbldg,we must have this
  setup_suit_building_origin(parent, building_node_path);
  
  // Traverse each node in our vector
  pvector<PT(DNAGroup)>::iterator i = _group_vector.begin();
  for(; i != _group_vector.end(); ++i) {
    PT(DNAGroup) group = *i;
    group->traverse(building_node_path, store, editing);
  }

  if (editing) {
    // Remember that this nodepath is associated with this dna group
    store->store_DNAGroup(building_node_path.node(), this);
  }
  else {
    SceneGraphReducer gr;
    // Get rid of the transitions
    gr.apply_attribs(building_node_path.node());
    gr.flatten(building_node_path.node(), ~0);

    // We do not have dna doors too
    // HQs need the door_origins around because they do not have dnaDoors
    //if (get_building_type() != string("hq")) {
      // Get rid of these placement origins since we do not need them anymore
    //  NodePath door_origin = building_node_path.find("**/*door_origin");
    //  if (!door_origin.is_empty()) {
    //    door_origin.remove_node();
    //  }
    //}
    // We need the sign_origin locator too
    //NodePath sign_origin = building_node_path.find("**/*sign_origin");
    //if (!sign_origin.is_empty()) {
    //  sign_origin.remove_node();
    //}
  }
  return building_node_path;
}


////////////////////////////////////////////////////////////////////
//     Function: DNAAnimBuilding::write
//       Access: Public
//  Description: Writes the group and all children to output
////////////////////////////////////////////////////////////////////
void DNAAnimBuilding::write(std::ostream &out, DNAStorage *store, int indent_level) const {
  indent(out, indent_level) << "anim_building ";
  out << '"' << get_name() << '"' << " [\n";

  // Write out all properties
  indent(out, indent_level + 1) << "code [ " <<
    '"' << _code << '"' << " ]\n";
  if (!get_building_type().empty()) {
    indent(out, indent_level + 1) << "building_type [ " << '"' << get_building_type() << '"' << " ]\n";
  }

  // Whoops, the titles were entered as iso8859 and we need to convert them to utf8 
  // We only want to run this when we need to fix an improper encoding
  // Note - you need to change the indent function below too
  // std::string utf8title = TextNode::reencode_text(_title, TextNode::E_iso8859, TextNode::E_utf8);
  if (!_article.empty()) {
    indent(out, indent_level + 1) << "article [ " << '"' <<
      _article << '"' << " ]\n";
  }
  indent(out, indent_level + 1) << "title [ " << '"' <<
    _title << '"' << " ]\n";
  indent(out, indent_level + 1) << "anim [ " <<
    '"' << _anim << '"' << " ]\n";
  indent(out, indent_level + 1) << "pos [ " <<
    _pos[0] << " " << _pos[1] << " " << _pos[2] << " ]\n";
  if (temp_hpr_fix) {
    indent(out, indent_level + 1) << "nhpr [ " <<
      _hpr[0] << " " << _hpr[1] << " " << _hpr[2] << " ]\n";
  } else {
    indent(out, indent_level + 1) << "hpr [ " <<
      _hpr[0] << " " << _hpr[1] << " " << _hpr[2] << " ]\n";
  }

  // Do not write out color if it is white to save work
  if (!_wall_color.almost_equal(LVecBase4f(1.0, 1.0, 1.0, 1.0))) {
    indent(out, indent_level + 1) << "color [ " <<
      _wall_color[0] << " " << _wall_color[1] << " " << _wall_color[2] << " " << _wall_color[3] <<
      " ]\n";
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
//     Function: DNAAnimBuilding::write
//       Access: Public
//  Description: Writes the group to the Datagram.
////////////////////////////////////////////////////////////////////
void DNAAnimBuilding::write(Datagram &datagram, DNAStorage *store) const {
    datagram.add_uint8(TYPECODE_DNAANIMBUILDING);

    bool write_article = !_article.empty();
    // Do not write out color if it is white to save work
    bool write_color = !_wall_color.almost_equal(LVecBase4f(1.0, 1.0, 1.0, 1.0));
    bool write_building_type = !get_building_type().empty();

    // Set the bits in our bit flags. Each used bit corresponds to if
    // something was written.
    // The first bit is special as it designates if we're using the temp hpr fix or not.
    uint8_t flags = 0; //0b00000000 - This is here for a bit reference.
    flags |= temp_hpr_fix << 0;
    flags |= write_article << 1;
    flags |= write_color << 2;
    flags |= write_building_type << 3;

    datagram.add_uint8(flags);
    datagram.add_string(get_name());
    datagram.add_string(get_code());
    datagram.add_string(get_title());
    datagram.add_string(get_anim());
    if (write_article) {
        datagram.add_string(get_article());
    }
    if (write_building_type) {
        datagram.add_string(get_building_type());
    }
    datagram.add_stdfloat(_pos.get_z());
    datagram.add_stdfloat(_pos.get_y());
    datagram.add_stdfloat(_pos.get_x());
    datagram.add_stdfloat(_hpr.get_z());
    datagram.add_stdfloat(_hpr.get_y());
    datagram.add_stdfloat(_hpr.get_x());

    if (write_color) {
        datagram.add_stdfloat(_wall_color.get_w());
        datagram.add_stdfloat(_wall_color.get_z());
        datagram.add_stdfloat(_wall_color.get_y());
        datagram.add_stdfloat(_wall_color.get_x());
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
//     Function: DNAAnimBuilding::make_from_dgi
//       Access: Public
//  Description: Sets up the group from the Datagram Iterator.
////////////////////////////////////////////////////////////////////
void DNAAnimBuilding::make_from_dgi(DatagramIterator &dgi, DNAStorage *store) {
    // Read off what was written from the bit flags.
    uint8_t flags = dgi.get_uint8();
    bool is_hpr_fixed = (flags >> 0) & 1U;
    bool wrote_article = (flags >> 1) & 1U;
    bool wrote_color = (flags >> 2) & 1U;
    bool wrote_building_type = (flags >> 3) & 1U;
    
    set_name(dgi.get_string());
    set_code(dgi.get_string());
    set_title(dgi.get_string());
    set_anim(dgi.get_string());
    if (wrote_article) {
        set_article(dgi.get_string());
    }
    if (wrote_building_type) {
        std::string building_type = dgi.get_string();
        set_building_type(building_type);

        // Record this headquarter at this block in the storage
        store->store_block_building_type(get_name(), building_type);
    }
    set_pos(LVecBase3f(dgi.get_stdfloat(), dgi.get_stdfloat(), dgi.get_stdfloat()));
    if (temp_hpr_fix && !is_hpr_fixed) {
        set_hpr(old_to_new_hpr(LVecBase3f(dgi.get_stdfloat(), dgi.get_stdfloat(), dgi.get_stdfloat())));
    } else if (!temp_hpr_fix && is_hpr_fixed) {
        set_hpr(new_to_old_hpr(LVecBase3f(dgi.get_stdfloat(), dgi.get_stdfloat(), dgi.get_stdfloat())));
    } else {
        set_hpr(LVecBase3f(dgi.get_stdfloat(), dgi.get_stdfloat(), dgi.get_stdfloat()));
    }
    if (wrote_color) {
        set_wall_color(LColorf(dgi.get_stdfloat(), dgi.get_stdfloat(), dgi.get_stdfloat(), dgi.get_stdfloat()));
    }
}

////////////////////////////////////////////////////////////////////
//     Function: DNAAnimBuilding::make_copy
//       Access: Public
//  Description: Copies all the children into our own vector
////////////////////////////////////////////////////////////////////
DNAGroup* DNAAnimBuilding::make_copy() {
  return new DNAAnimBuilding(*this);
}
