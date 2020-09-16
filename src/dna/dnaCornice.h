// Filename: dnaCornice.h
// Created by:  shochet (28Mar00)
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
//       Class : DNACornice
// Description : A cornice at the top of a flat building
////////////////////////////////////////////////////////////////////
class EXPCL_TOONTOWN DNACornice : public DNAGroup  {
PUBLISHED:
  DNACornice(const std::string &initial_name = "");
  DNACornice(const DNACornice &cornice);

  virtual NodePath traverse(NodePath &parent, DNAStorage *store, int editing=0);
  virtual void write(std::ostream &out, DNAStorage *store, int indent_level = 0) const;
  virtual void write(Datagram &datagram, DNAStorage *store) const;
  virtual void make_from_dgi(DatagramIterator &dgi, DNAStorage *store);

  void set_code(std::string code);
  std::string get_code() const;

  void set_color(const Colorf &color);
  Colorf get_color() const;

private:
  virtual DNAGroup* make_copy();

private:
  std::string _code;
  Colorf _color;

public:
  static TypeHandle get_class_type() {
    return _type_handle;
  }
  static void init_type() {
    DNAGroup::init_type();
    register_type(_type_handle, "DNACornice",
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