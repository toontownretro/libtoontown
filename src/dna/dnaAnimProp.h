// Filename: dnaAnimProp.h
// Created by:  gjeon (18Sep09)
//
////////////////////////////////////////////////////////////////////
#pragma once

#include "dnabase.h"

#include "dnaStorage.h"
#include "dnaProp.h"

#include <pandaNode.h>
#include <nodePath.h>
#include <luse.h>
#include <pvector.h>

////////////////////////////////////////////////////////////////////
//       Class : DNAAnimProp
// Description : An animated prop like a walking hydrant.
////////////////////////////////////////////////////////////////////
class EXPCL_TOONTOWN DNAAnimProp : public DNAProp  {
PUBLISHED:
  DNAAnimProp(const std::string &initial_name = "");
  DNAAnimProp(const DNAAnimProp &anim_prop);

  virtual NodePath traverse(NodePath &parent, DNAStorage *store, int editing=0);
  virtual void write(std::ostream &out, DNAStorage *store, int indent_level = 0) const;
  virtual void write(Datagram &datagram, DNAStorage *store) const;
  virtual void make_from_dgi(DatagramIterator &dgi, DNAStorage *store);

  INLINE void set_anim(std::string anim);
  INLINE std::string get_anim() const;

private:
  virtual DNAGroup* make_copy();

protected:
  std::string _anim;

public:
  static TypeHandle get_class_type() {
    return _type_handle;
  }
  static void init_type() {
    DNANode::init_type();
    register_type(_type_handle, "DNAAnimProp",
                  DNANode::get_class_type()
                  );
  }
  virtual TypeHandle get_type() const {
    return get_class_type();
  }
  virtual TypeHandle force_init_type() {init_type(); return get_class_type();}

private:
  static TypeHandle _type_handle;
};

#include "dnaAnimProp.I"