// Filename: dnaSuitEdge.h
// Created by:  shochet (28Jan01)
//
////////////////////////////////////////////////////////////////////
#pragma once

#include "dnabase.h"
//#include "toontownbase.h"

#include "typedObject.h"
#include "pointerTo.h"
#include "typedReferenceCount.h"
#include <string>
#include "dnaSuitPoint.h"

class DNAStorage;

////////////////////////////////////////////////////////////////////
//       Class : DNASuitEdge
// Description :
////////////////////////////////////////////////////////////////////
class EXPCL_TOONTOWN DNASuitEdge : public TypedReferenceCount {

PUBLISHED:
  DNASuitEdge(PT(DNASuitPoint) start_point,
              PT(DNASuitPoint) end_point,
              std::string zone_id);
  INLINE bool operator == (const DNASuitEdge &other) const;

  INLINE PT(DNASuitPoint) get_start_point() const;
  INLINE PT(DNASuitPoint) get_end_point() const;
  INLINE std::string get_zone_id() const;
  INLINE void set_zone_id(std::string zone_id);
  void output(std::ostream &out) const;

  virtual void write(std::ostream &out, DNAStorage *store, int indent_level = 0) const;

private:
  PT(DNASuitPoint) _start_point;
  PT(DNASuitPoint) _end_point;
  std::string _zone_id;

public:
  static TypeHandle get_class_type() {
    return _type_handle;
  }
  static void init_type() {
    TypedReferenceCount::init_type();
    register_type(_type_handle, "DNASuitEdge",
                  TypedReferenceCount::get_class_type()
                  );
  }
  virtual TypeHandle get_type() const {
    return get_class_type();
  }
  virtual TypeHandle force_init_type() {init_type(); return get_class_type();}

private:
  static TypeHandle _type_handle;
};


INLINE std::ostream &operator << (std::ostream &out, const DNASuitEdge &edge) {
  edge.output(out);
  return out;
}


#include "dnaSuitEdge.I"