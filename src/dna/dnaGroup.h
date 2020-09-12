// Filename: dnaGroup.h
// Created by:  shochet (24May00)
//
////////////////////////////////////////////////////////////////////

#pragma once
//
////////////////////////////////////////////////////////////////////
// Includes
////////////////////////////////////////////////////////////////////
//#include "toontownbase.h"
#include "dnabase.h"

#include "typedObject.h"
#include "namable.h"
#include "nodePath.h"
#include "pvector.h"
#include <string>
#include "pointerTo.h"
#include "typedReferenceCount.h"

class DNAStorage;

////////////////////////////////////////////////////////////////////
//       Class : DNAGroup
// Description : A group of dna nodes
////////////////////////////////////////////////////////////////////
class EXPCL_TOONTOWN DNAGroup : public TypedReferenceCount, public Namable {
PUBLISHED:
  DNAGroup(const std::string &initial_name = "");
  DNAGroup(const DNAGroup &group);

  virtual NodePath traverse(NodePath &parent, DNAStorage *store, int editing=0);
  NodePath top_level_traverse(NodePath &parent, DNAStorage *store, int editing=0);

  void add(PT(DNAGroup) group);
  void remove(PT(DNAGroup) group);
  INLINE PT(DNAGroup) at(uint index);
  INLINE PT(DNAGroup) current();
  INLINE int get_num_children();
  INLINE PT(DNAGroup) get_parent() const;

  virtual void write(std::ostream &out, DNAStorage *store, int indent_level = 0) const;

  void ls() const;

public:
  INLINE void set_parent(PT(DNAGroup));
  INLINE void clear_parent();

protected:
  pvector<PT(DNAGroup)> _group_vector;

private:
  virtual DNAGroup* make_copy();
  // Ok, the parent pointer is not going to be a PointerTo to prevent
  // circular references from being leaked
  // TODO: in this destructor, null out all the children's parent pointers
  // so they will have NULL pointers, and not "bad" pointers
  DNAGroup* _parent;

  TYPE_HANDLE2(DNAGroup, TypedReferenceCount, Namable)
};


#include "dnaGroup.I"