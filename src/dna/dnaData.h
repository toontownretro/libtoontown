// Filename: dnaData.h
// Created by:  shochet (24May00)
//
////////////////////////////////////////////////////////////////////

#pragma once

#include "toontownbase.h"

#include <typedReferenceCount.h>
#include <filename.h>
#include <coordinateSystem.h>
#include <pnotify.h>
#include <dSearchPath.h>
#include <datagram.h>
#include <datagramIterator.h>

#include <string>

#include "dnaGroup.h"
#include "dnaStorage.h"
#include "dnaConstants.h"

static std::ostream &error_stream = nout;

///////////////////////////////////////////////////////////////////
//       Class : DNAData
// Description : This is the primary interface into all the DNA data,
//               and the root of the DNA file structure.  An DNAData
//               structure corresponds exactly with an DNA file on the
//               disk.
//
////////////////////////////////////////////////////////////////////
class EXPCL_TOONTOWN DNAData : public DNAGroup {
PUBLISHED:
  INLINE DNAData(const std::string &initial_name = "");
  INLINE DNAData(const DNAData &copy);
  INLINE DNAData &operator = (const DNAData &copy);

  bool read(Filename filename, std::ostream &error = error_stream);
  bool read(std::istream &in, std::ostream &error = error_stream);
  
  bool read_compressed(std::istream &in, std::ostream &error = error_stream);

  static bool resolve_dna_filename(Filename &dna_filename, const DSearchPath &searchpath = DSearchPath());
  bool resolve_externals(const std::string &searchpath, std::ostream &error = error_stream);

  bool write_dna(Filename filename, std::ostream &error, DNAStorage *store);
  bool write_dna(std::ostream &out, std::ostream &error, DNAStorage *store);

  void set_coordinate_system(CoordinateSystem coordsys);
  INLINE CoordinateSystem get_coordinate_system() const;

  INLINE void set_dna_filename(const Filename &directory);
  INLINE const Filename &get_dna_filename() const;

  INLINE void set_dna_storage(DNAStorage *store);
  INLINE DNAStorage *get_dna_storage();

  virtual void write(std::ostream &out, DNAStorage *store, int indent_level = 0) const;
  virtual void write(Datagram &datagram, DNAStorage *store) const;

private:
  virtual DNAGroup* make_copy();

private:
  void post_read(std::ostream &error);
  void pre_write();

  CoordinateSystem _coordsys;
  Filename _dna_filename;
  DNAStorage *_dna_store;

public:
  static TypeHandle get_class_type() {
    return _type_handle;
  }
  static void init_type() {
    DNAGroup::init_type();
    register_type(_type_handle, "DNAData",
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

#include "dnaData.I"