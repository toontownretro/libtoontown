// Filename: dnaAnimBuilding.h
// Created by:  gjeon (12Nov09)
//
////////////////////////////////////////////////////////////////////
#pragma once

#include "dnabase.h"

#include "dnaStorage.h"
#include "dnaBuildings.h"
#include "pandaNode.h"
#include "nodePath.h"
#include "luse.h"
#include "pvector.h"

////////////////////////////////////////////////////////////////////
//       Class : DNAAnimBuilding
// Description : An animated building like a sneeizing building.
////////////////////////////////////////////////////////////////////
class EXPCL_TOONTOWN DNAAnimBuilding : public DNALandmarkBuilding  {
PUBLISHED:
  DNAAnimBuilding(const std::string &initial_name = "");
  DNAAnimBuilding(const DNAAnimBuilding &anim_building);

  virtual NodePath traverse(NodePath &parent, DNAStorage *store, int editing=0);
  virtual void write(std::ostream &out, DNAStorage *store, int indent_level = 0) const;

  INLINE void set_anim(std::string anim);
  INLINE std::string get_anim() const;

private:
  virtual DNAGroup* make_copy();
  std::string _anim;

public:
  static TypeHandle get_class_type() {
    return _type_handle;
  }
  static void init_type() {
    DNANode::init_type();
    register_type(_type_handle, "DNAAnimBuilding",
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

#include "dnaAnimBuilding.I"