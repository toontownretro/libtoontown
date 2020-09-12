// Filename: dnaDoor.h
// Created by:  shochet (27Jun00)
//
////////////////////////////////////////////////////////////////////
#pragma once

#include "dnabase.h"
#include "dnaNode.h"
#include "dnaBuildings.h"
#include "pandaNode.h"
#include "nodePath.h"
#include "luse.h"
#include "pvector.h"

////////////////////////////////////////////////////////////////////
//       Class : DNADoor
// Description : A door
////////////////////////////////////////////////////////////////////
class EXPCL_TOONTOWN DNADoor : public DNAGroup  {
PUBLISHED:
  DNADoor(const std::string &initial_name = "");
  DNADoor(const DNADoor &door);

  virtual NodePath traverse(NodePath &parent, DNAStorage *store, int editing=0);
  virtual void write(std::ostream &out, DNAStorage *store, int indent_level = 0) const;

  void set_code(std::string code);
  std::string get_code() const;

  void set_color(const Colorf &color);
  Colorf get_color() const;

  static void setup_door(NodePath& door_node_path,
      NodePath& parent, NodePath& door_origin, DNAStorage *store,
      const std::string& block, const LVector4f& color);

private:
  virtual DNAGroup* make_copy();

protected:
  std::string _code;
  Colorf _color;

public:
  static TypeHandle get_class_type() {
    return _type_handle;
  }
  static void init_type() {
    DNAGroup::init_type();
    register_type(_type_handle, "DNADoor",
                  DNAGroup::get_class_type()
                  );
  }
  virtual TypeHandle get_type() const {
    return get_class_type();
  }
  virtual TypeHandle force_init_type() {init_type(); return get_class_type();}

private:
  static TypeHandle _type_handle;
};



////////////////////////////////////////////////////////////////////
//       Class : DNAFlatDoor
// Description : A door for a flat buildings
////////////////////////////////////////////////////////////////////
class EXPCL_TOONTOWN DNAFlatDoor : public DNADoor {
PUBLISHED:
  DNAFlatDoor(const std::string &initial_name = "");
  DNAFlatDoor(const DNAFlatDoor &door);

  virtual NodePath traverse(NodePath &parent, DNAStorage *store, int editing=0);
  virtual void write(std::ostream &out, DNAStorage *store, int indent_level = 0) const;

private:
  virtual DNAGroup* make_copy();

public:
  static TypeHandle get_class_type() {
    return _type_handle;
  }
  static void init_type() {
    DNADoor::init_type();
    register_type(_type_handle, "DNAFlatDoor",
                  DNADoor::get_class_type()
                  );
  }
  virtual TypeHandle get_type() const {
    return get_class_type();
  }
  virtual TypeHandle force_init_type() {init_type(); return get_class_type();}

private:
  static TypeHandle _type_handle;
};