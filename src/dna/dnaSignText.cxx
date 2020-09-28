// Filename: dnaSignText.cxx
// Created by:  skyler (2001-30-01)
//
////////////////////////////////////////////////////////////////////

#include "dnaSignText.h"
#include "dnaSignBaseline.h"
#include "dnaSign.h"
#include "modelPool.h"
#include "nodePath.h"
#include "textNode.h"
#include "staticTextFont.h"
#include "decalEffect.h"
#include "config_linmath.h"

////////////////////////////////////////////////////////////////////
// Static variables
////////////////////////////////////////////////////////////////////
TypeHandle DNASignText::_type_handle;

////////////////////////////////////////////////////////////////////
//     Function: DNASignText::Constructor
//       Access: Public
//  Description:
////////////////////////////////////////////////////////////////////
DNASignText::DNASignText(const std::string &initial_name) :
  DNANode(initial_name)
{
  _code = "";
  _color.set(1.0, 1.0, 1.0, 1.0);
  _letters = "";
  _use_baseline_color = true;
}

////////////////////////////////////////////////////////////////////
//     Function: DNASignText::Copy Constructor
//       Access: Public
//  Description:
////////////////////////////////////////////////////////////////////
DNASignText::DNASignText(const DNASignText &signText) :
  DNANode(signText)
{
  _code = signText.get_code();
  _color = signText.get_color();
  _letters = signText.get_letters();
  _use_baseline_color = signText._use_baseline_color;
}


////////////////////////////////////////////////////////////////////
//     Function: DNASignText::traverse
//       Access: Public
//  Description:
////////////////////////////////////////////////////////////////////
NodePath DNASignText::traverse(NodePath &parent, DNAStorage *store, int editing) {
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

  // Try to find this signText in the node map
  // NodePath signText_node_path = parent.attach_new_node("text");

  PT(DNASignBaseline) baseline = DCAST(DNASignBaseline, get_parent());

  // Use the baseline font, if available:
  TextFont *font = (TextFont *)NULL;
  if (_code.empty()) {
    font = baseline->get_font();
  } else {
    PT(PandaNode) font_node = (store->find_node(_code)).node();
    if (!font_node) {
      dna_cat.error()
        << "unable to find SignText font " << _code << std::endl;
    } else {
      font = new StaticTextFont(font_node);
    }
  }
  if (font == (TextFont *)NULL && !_letters.empty()) {
    font = TextNode::get_default_font();
    if (font == (TextFont *)NULL) {
      dna_cat.error()
        << "no font specified for '" << _letters 
        << "', and no default font available.\n";
    } else {
      dna_cat.warning()
        << "no font specified for '" << _letters << "', using default font.\n";
    }
  }

  // Use the baseline color, if available:
  Colorf color = _color;
  if (_use_baseline_color) {
    color = baseline->get_color();
  }

  // Try to find this signText in the node map
  PT(TextNode) text_node = new TextNode("sign");
  text_node->set_text_color(color);
  text_node->set_font(font);
  std::string letters = _letters;
  // Check for upper case flag:

  if (baseline->get_flags().find('c') != std::string::npos) {
    // We have to uppercase this carefully, allowing for encoded text.
    TextEncoder encoder;
    encoder.set_text(letters);
    int num_chars = encoder.get_num_chars();
    for (int i = 0; i < num_chars; i++) {
      int character = encoder.get_unicode_char(i);
      encoder.set_unicode_char(i, encoder.unicode_toupper(character));
    }
  }

  // Check for drop shadow flag:
  if (baseline->get_flags().find('d') != std::string::npos) {
    // A black shadow is too harsh: text_node->set_shadow_color(0.0, 0.0, 0.0, 1.0);
    text_node->set_shadow_color(
      color[0]*0.3, color[1]*0.3, color[2]*0.3, color[3]*0.7);
    text_node->set_shadow(0.03, 0.03);
  }
  text_node->set_text(letters); // set the text last.

  LVector3f bl_pos = _pos;
  LVector3f bl_hpr = _hpr;
  LVector3f bl_scale = _scale;
  if ((baseline->get_flags().find('b') != std::string::npos)
      && (baseline->isFirstLetterOfWord(letters))) {
    bl_scale[0]*=1.5;
    bl_scale[2]*=1.5;
  }
  baseline->baseline_next_pos_hpr_scale(bl_pos, bl_hpr, bl_scale,
    LVector3f(text_node->get_width(), 0.0, text_node->get_height()));

  NodePath signText_node_path = parent.attach_new_node(text_node->generate());
  // Place the signText at the bottom center of the building,
  // three feet out from the origin where the wall is
  signText_node_path.set_pos_hpr_scale(parent,
           bl_pos,
           bl_hpr,
           bl_scale);
  // Clear parent color higher in the hierarchy
  signText_node_path.set_color_off();
  signText_node_path.set_color(color);

  // Traverse each node in our vector
  pvector<PT(DNAGroup)>::iterator i = _group_vector.begin();
  for(; i != _group_vector.end(); ++i) {
    PT(DNAGroup) group = *i;
    group->traverse(signText_node_path, store, editing);
  }

  if (editing) {
    // Remember that this nodepath is associated with this dna group
    store->store_DNAGroup(signText_node_path.node(), this);
  }

  return signText_node_path;
}



////////////////////////////////////////////////////////////////////
//     Function: DNASignText::write
//       Access: Public
//  Description: Writes the group and all children to output
////////////////////////////////////////////////////////////////////
void DNASignText::write(std::ostream &out, DNAStorage *store, int indent_level) const {
  indent(out, indent_level) << "text [\n";

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
  //TODO: enquote_string(_letters), to fix output like """
  // (which is a doublequoted doublequote), and "well "hello" there!"
  if (_letters=="\"") {
    indent(out, indent_level + 1) << "letters [ '\"' ]\n";
  } else {
    indent(out, indent_level + 1) << "letters [ " <<
      '"' << _letters << '"' << " ]\n";
  }

  indent(out, indent_level) << "]\n";
}

////////////////////////////////////////////////////////////////////
//     Function: DNASignText::write
//       Access: Public
//  Description: Writes the group to the Datagram.
////////////////////////////////////////////////////////////////////
void DNASignText::write(Datagram &datagram, DNAStorage *store) const {
    datagram.add_uint8(TYPECODE_DNASIGNTEXT);
    bool write_code = !_code.empty();
    bool write_pos = !_pos.almost_equal(LVecBase3f::zero());
    bool write_hpr = !_hpr.almost_equal(LVecBase3f::zero());
    bool write_scale = !_scale.almost_equal(LVecBase3f(1.0, 1.0, 1.0));
    bool write_color = !_color.almost_equal(LVecBase4f(1.0, 1.0, 1.0, 1.0));

    // Set the bits in our bit flags. Each used bit corresponds to if
    // something was written.
    uint8_t flags = 0; //0b00000000 - This is here for a bit reference.
    flags |= write_code << 0;
    flags |= write_pos << 1;
    flags |= write_hpr << 2;
    flags |= write_scale << 3;
    flags |= write_color << 4;

    datagram.add_uint8(flags);
    datagram.add_string(get_name());
    datagram.add_string(get_letters());
    if (write_code) {
        datagram.add_string(get_code());
    }
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
}

////////////////////////////////////////////////////////////////////
//     Function: DNASignText::make_from_dgi
//       Access: Public
//  Description: Sets up the group from the Datagram Iterator.
////////////////////////////////////////////////////////////////////
void DNASignText::make_from_dgi(DatagramIterator &dgi, DNAStorage *store) {
    uint8_t flags = dgi.get_uint8();

    // Read off what was written from the bit flags.
    bool wrote_code = (flags >> 0) & 1U;
    bool wrote_pos = (flags >> 1) & 1U;
    bool wrote_hpr = (flags >> 2) & 1U;
    bool wrote_scale = (flags >> 3) & 1U;
    bool wrote_color = (flags >> 4) & 1U;

    set_name(dgi.get_string());
    set_letters(dgi.get_string());
    if (wrote_code) {
        set_code(dgi.get_string());
    }
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
//     Function: DNASignText::make_copy
//       Access: Public
//  Description: Copies all the children into our own vector
////////////////////////////////////////////////////////////////////
DNAGroup* DNASignText::make_copy() {
  return new DNASignText(*this);
}
