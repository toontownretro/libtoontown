// Filename: dnaAnimProp.cxx
// Created by:  gjeon (28Sep09)
//
////////////////////////////////////////////////////////////////////

#include "dnaInteractiveProp.h"
#include "sceneGraphReducer.h"
#include "modelNode.h"
#include "config_linmath.h"

////////////////////////////////////////////////////////////////////
// Static variables
////////////////////////////////////////////////////////////////////
TypeHandle DNAInteractiveProp::_type_handle;


////////////////////////////////////////////////////////////////////
//     Function: DNAInteractiveProp::Constructor
//       Access: Public
//  Description:
////////////////////////////////////////////////////////////////////
DNAInteractiveProp::DNAInteractiveProp(const std::string &initial_name) :
  DNAAnimProp(initial_name)
{
  _cell_id = -1;
}

////////////////////////////////////////////////////////////////////
//     Function: DNAInteractiveProp::Copy Constructor
//       Access: Public
//  Description:
////////////////////////////////////////////////////////////////////
DNAInteractiveProp::DNAInteractiveProp(const DNAInteractiveProp &interactive_prop) :
  DNAAnimProp(interactive_prop)
{
  _code = interactive_prop.get_code();
  _color = interactive_prop.get_color();
  _anim = interactive_prop.get_anim();
  _cell_id = interactive_prop.get_cell_id();
}


////////////////////////////////////////////////////////////////////
//     Function: DNAInteractiveProp::traverse
//       Access: Public
//  Description:
////////////////////////////////////////////////////////////////////
NodePath DNAInteractiveProp::traverse(NodePath &parent, DNAStorage *store, int editing) {

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

  prop_node_path.set_tag("DNAAnim", _anim);
  std::string cellIdStr;
  cellIdStr += _cell_id;
  prop_node_path.set_tag("DNACellIndex", cellIdStr);

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
//     Function: DNAInteractiveProp::write
//       Access: Public
//  Description: Writes the group and all children to output
////////////////////////////////////////////////////////////////////
void DNAInteractiveProp::write(std::ostream &out, DNAStorage *store, int indent_level) const {
  indent(out, indent_level) << "interactive_prop ";
  out << '"' << get_name() << '"' << " [\n";

  // Write out all properties
  indent(out, indent_level + 1) << "code [ " <<
    '"' << _code << '"' << " ]\n";
  indent(out, indent_level + 1) << "anim [ " <<
    '"' << _anim << '"' << " ]\n";
  indent(out, indent_level + 1) << "cell_id [ " <<
    _cell_id << " ]\n";
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
//     Function: DNAInteractiveProp::make_copy
//       Access: Public
//  Description: Copies all the children into our own vector
////////////////////////////////////////////////////////////////////
DNAGroup* DNAInteractiveProp::make_copy() {
  return new DNAInteractiveProp(*this);
}
