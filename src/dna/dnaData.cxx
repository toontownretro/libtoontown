// Filename: dnaData.cxx
// Created by:  shochet (24May00)
//
////////////////////////////////////////////////////////////////////
#include "dnaData.h"
#include "config_dna.h"
#include "config_putil.h"

#include "string_utils.h"
#include "coordinateSystem.h"
#include "luse.h"
#include "dSearchPath.h"
#include "virtualFileSystem.h"

// Import any needed files for CDNA reading.
#include "dnaAnimBuilding.h"
#include "dnaAnimProp.h"
#include "dnaBattleCell.h"
#include "dnaBuildings.h"
#include "dnaCornice.h"
#include "dnaDoor.h"
#include "dnaInteractiveProp.h"
#include "dnaNode.h"
#include "dnaProp.h"
#include "dnaSign.h"
#include "dnaSignBaseline.h"
#include "dnaSignGraphic.h"
#include "dnaSignText.h"
#include "dnaStreet.h"
#include "dnaSuitPoint.h"
#include "dnaVisGroup.h"
#include "dnaWindow.h"

extern int dnayyparse(void);
#include "parserDefs.h"
#include "lexerDefs.h"

////////////////////////////////////////////////////////////////////
// Static variables
////////////////////////////////////////////////////////////////////
TypeHandle DNAData::_type_handle;


////////////////////////////////////////////////////////////////////
//     Function: DnaData::resolve_dna_filename
//       Access: Public, Static
//  Description: Looks for the indicated filename, first along the
//               indicated searchpath, and then along the dna_path and
//               finally along the model_path.  If found, updates the
//               filename to the full path and returns true;
//               otherwise, returns false.
////////////////////////////////////////////////////////////////////
bool DNAData::
resolve_dna_filename(Filename &dna_filename, const DSearchPath &searchpath) {
  VirtualFileSystem *vfs = VirtualFileSystem::get_global_ptr();
  
  vfs->resolve_filename(dna_filename, searchpath, "dna") ||
    vfs->resolve_filename(dna_filename, get_dna_path(), "dna") ||
    vfs->resolve_filename(dna_filename, get_model_path(), "dna") ||
    vfs->resolve_filename(dna_filename, searchpath, "cdna") ||
    vfs->resolve_filename(dna_filename, get_dna_path(), "cdna") ||
    vfs->resolve_filename(dna_filename, get_model_path(), "cdna");
  return vfs->exists(dna_filename);
}


////////////////////////////////////////////////////////////////////
//     Function: DNAData::read
//       Access: Public
//  Description: Opens the indicated filename and reads the DNA data
//               contents from it.  Returns true if the file was
//               successfully opened and read, false if there were
//               some errors, in which case the data may be partially
//               read.
//
//               error is the output stream to which to write error
//               messages.
////////////////////////////////////////////////////////////////////
bool DNAData::
read(Filename filename, std::ostream &error) {
  if (!resolve_dna_filename(filename)) {
    error << "Could not find " << filename << "\n";
    return false;
  }

  // We use binary mode to avoid Windows' end-of-line convention.
  filename.set_binary();
  set_dna_filename(filename);

  pifstream file;
  if (!filename.open_read(file)) {
    error << "Unable to open " << filename << "\n";
    return false;
  }
  
  if (filename.get_extension().compare("cdna") == 0) {
      return read_compressed(filename, error);
  }
  return read(file, error);
}


////////////////////////////////////////////////////////////////////
//     Function: DNAData::read
//       Access: Public
//  Description: Parses the DNA syntax contained in the indicated
//               input stream.  Returns true if the stream was a
//               completely valid DNA file, false if there were some
//               errors, in which case the data may be partially read.
////////////////////////////////////////////////////////////////////
bool DNAData::read(std::istream &in, std::ostream &error) {
    // First, dispense with any children we had previously.  We will
    // replace them with the new data.
    dna_cat.debug() << "start of dnaData.read\n";
    _group_vector.clear();

    dna_init_parser(in, error, get_dna_filename(), this);
    dnayyparse();
    dna_cleanup_parser();

    post_read(error);

    dna_cat.debug() << "end of DNAData.read\n";
    return (dna_error_count() == 0);
}

////////////////////////////////////////////////////////////////////
//     Function: DNAData::read_compressed
//       Access: Public
//  Description: Parses the CDNA data contained in the indicated
//               input stream.  Returns true if the stream was a
//               completely valid CDNA file, false if there were some
//               errors, in which case the data may be partially read.
////////////////////////////////////////////////////////////////////
bool DNAData::read_compressed(const Filename &filename, std::ostream &error) {
    // First, dispense with any children we had previously.  We will
    // replace them with the new data.
    dna_cat.debug() << "start of dnaData.read_compressed\n";
    _group_vector.clear();
    
    static VirtualFileSystem* vfs = VirtualFileSystem::get_global_ptr();
    Filename found(filename);
    
    std::string data;
    vfs->read_file(found, data, true);
    
    nassertr(data.size() > 7, false);
    nassertr(data.substr(0, 5) == "CDNA\n", false);
    data = data.substr(6);
    
    // Now let's read out the written version.
    uint8_t major_ver = (uint8_t)data[0];
    uint8_t minor_ver = (uint8_t)data[1];
    uint8_t very_minor_ver = (uint8_t)data[2];
    data = data.substr(3);

    // Get the stdfloat double mode for the datagram.
    bool stdfloat_double = (data[0] != 0);
    // Is the rest of our data compressed?
    bool compressed = (data[1] != 0);
    data = data.substr(2);

    dna_cat.debug() << "CDNA version: " << uint32_t(major_ver) << "." << uint32_t(minor_ver) << "." << uint32_t(very_minor_ver) << std::endl;
    dna_cat.debug() << "Stdfloat Doubles: " << uint32_t(stdfloat_double) << std::endl;
    dna_cat.debug() << "Compressed: " << uint32_t(compressed) << std::endl;

    // If our data is compressed, Decompress it with Panda3d's built in decompress string.
    if (compressed) {
        data = decompress_string(data);
    }
    
    // Create our Datagram and it's Iterator.
    Datagram dg(data.data(), data.size());
    // Set the stdfloat double mode.
    dg.set_stdfloat_double(stdfloat_double);
    DatagramIterator dgi(dg);
    
    // Parse the Iterator.
    PT(DNAGroup) current_group = this;
    while(dgi.get_remaining_size()) {
        uint8_t typecode = dgi.get_uint8();
        dna_cat.spam() << "Current Typecode: " << uint32_t(typecode) << std::endl;
        PT(DNAGroup) new_group;
        PT(DNASuitPoint) new_point;
        
        if (typecode == TYPECODE_RETURNMARKER) {
            nassertr(current_group != nullptr, 0);
            dna_cat.debug() << "TYPECODE_RETURNMARKER: " << std::endl;
            PT(DNAGroup) parent = current_group->get_parent();
            dna_cat.debug() << "Current Group: " << current_group->get_name() << ", New Group: " << (parent ? parent->get_name() : "nullptr") << std::endl;
            if (parent != nullptr) {
                current_group = parent;
            } else {
                nassertr(current_group->get_name() == "loader_data", 0);
            }
        } else {
            switch (typecode) {
                case TYPECODE_DNAGROUP:
                    new_group = new DNAGroup("unnamed_group");
                    break;
                case TYPECODE_DNAVISGROUP:
                    new_group = new DNAVisGroup("unnamed_visgroup");
                    break;
                case TYPECODE_DNANODE:
                    new_group = new DNANode("unnamed_node");
                    break;
                case TYPECODE_DNAPROP:
                    new_group = new DNAProp("unnamed_prop");
                    break;
                case TYPECODE_DNASIGN:
                    new_group = new DNASign("unnamed_sign");
                    break;
                case TYPECODE_DNASIGNBASELINE:
                    new_group = new DNASignBaseline("unnamed_signbaseline");
                    break;
                case TYPECODE_DNASIGNTEXT:
                    new_group = new DNASignText("unnamed_signtext");
                    break;
                case TYPECODE_DNASIGNGRAPHIC:
                    new_group = new DNASignGraphic("unnamed_signgraphic");
                    break;
                case TYPECODE_DNAWALL:
                    new_group = new DNAWall("unnamed_wall");
                    break;
                case TYPECODE_DNAWINDOWS:
                    new_group = new DNAWindows("unnamed_windows");
                    break;
                case TYPECODE_DNACORNICE:
                    new_group = new DNACornice("unnamed_cornice");
                    break;
                case TYPECODE_DNADOOR:
                    new_group = new DNADoor("unnamed_door");
                    break;
                case TYPECODE_DNAFLATDOOR:
                    new_group = new DNAFlatDoor("unnamed_flatdoor");
                    break;
                case TYPECODE_DNASTREET:
                    new_group = new DNAStreet("unnamed_street");
                    break;
                case TYPECODE_DNAFLATBUILDING:
                    new_group = new DNAFlatBuilding("unnamed_flatbuilding");
                    break;
                case TYPECODE_DNALANDMARKBUILDING:
                    new_group = new DNALandmarkBuilding("unnamed_landmarkbuilding");
                    break;
                case TYPECODE_DNAINTERACTIVEPROP:
                    new_group = new DNAInteractiveProp("unnamed_interactiveprop");
                    break;
                case TYPECODE_DNAANIMPROP:
                    new_group = new DNAAnimProp("unnamed_animprop");
                    break;
                case TYPECODE_DNAANIMBUILDING:
                    new_group = new DNAAnimBuilding("unnamed_animbuilding");
                    break;
                case TYPECODE_DNASUITPOINT:
                    new_point = new DNASuitPoint();
                    new_point->make_from_dgi(dgi);
                    _dna_store->store_suit_point(new_point);
                    new_group = nullptr; // We set it to nullptr so it does another loop.
                    break;
                default:
                    dna_cat.fatal() << "Invalid Type Code: " << uint32_t(typecode) << std::endl;
                    return 0;
            }
            if (new_group == nullptr) {
                continue;
            }
            new_group->make_from_dgi(dgi, _dna_store);
            
            if (current_group) {
                new_group->set_parent(current_group);
                current_group->add(new_group);
            }
            
            // If our class matches any of these, We can not parent stuff to it.
            // It will cause reading errors. There might be better way to do this.
            // If so we cn remove this in the future.
            if (!new_group->is_of_type(DNACornice::get_class_type()) &&
                !new_group->is_of_type(DNADoor::get_class_type()) &&
                !new_group->is_of_type(DNAFlatDoor::get_class_type()) &&
                !new_group->is_of_type(DNASignGraphic::get_class_type()) &&
                !new_group->is_of_type(DNASignText::get_class_type()) &&
                !new_group->is_of_type(DNAStreet::get_class_type()) &&
                !new_group->is_of_type(DNAWindows::get_class_type()))
            {
                //dna_cat.debug() << "Changing Parent:" << current_group->get_name() << " -> " << new_group->get_name() << std::endl;
                current_group = new_group;
            }
        }
    }

    post_read(error);

    dna_cat.debug() << "end of DNAData.read_compressed\n";
    return (dna_error_count() == 0);
}


////////////////////////////////////////////////////////////////////
//     Function: DNAData::resolve_externals
//       Access: Public
//  Description: Loads up all the dna files referenced by <File>
//               entries within the dna structure, and inserts their
//               contents in place of the <File> entries.  Searches
//               for files in the searchpath, if not found directly,
//               and writes error messages to the indicated output
//               stream.  Returns true if all externals were loaded
//               successfully, false otherwise.
////////////////////////////////////////////////////////////////////
bool DNAData::
resolve_externals(const std::string &searchpath, std::ostream &error) {
  //return r_resolve_externals(searchpath, error, get_coordinate_system());
  return false;
}

////////////////////////////////////////////////////////////////////
//     Function: DNAData::write_dna
//       Access: Public
//  Description: The main interface for writing complete dna or cdna files.
////////////////////////////////////////////////////////////////////
bool DNAData::
write_dna(Filename filename, std::ostream &error, DNAStorage *store) {
  // We use binary mode to avoid Windows' end-of-line convention.
  filename.set_binary();
  filename.unlink();

  pofstream file;
  if (!filename.open_write(file)) {
    error << "Unable to open " << filename << " for writing.\n";
    return false;
  }
  
  if (filename.get_extension().compare("cdna") == 0) {
      return write_cdna(file, error, store);
  } else {
      return write_dna(file, error, store);
  }
}

////////////////////////////////////////////////////////////////////
//     Function: DNAData::write_dna
//       Access: Public
//  Description: The main interface for writing complete dna files.
////////////////////////////////////////////////////////////////////
bool DNAData::
write_dna(std::ostream &out, std::ostream &error, DNAStorage *store) {
  pre_write();
  write(out, store, 0);
  return true;
}

////////////////////////////////////////////////////////////////////
//     Function: DNAData::write_cdna
//       Access: Public
//  Description: The main interface for writing complete cdna files.
////////////////////////////////////////////////////////////////////
bool DNAData::
write_cdna(std::ostream &out, std::ostream &error, DNAStorage *store) {
  Datagram datagram = Datagram();
  write(datagram, store);
  
  DatagramIterator dgi(datagram, 0);
  // Grab the size for the data we just worked on.
  size_t size = dgi.get_remaining_size();
  nassertr(size > 0, false);
  // Create our string to store our data.
  std::string data;
  data.resize(size);
  // Extract our bytes out into the string.
  dgi.extract_bytes((unsigned char *)data.data(), size);
  // Now we finally add the data to our main datagram.
  datagram.append_data(data.data(), data.size());
  // Finally write our data to the file.
  out << data << std::flush;
  return true;
}



////////////////////////////////////////////////////////////////////
//     Function: DNAData::set_coordinate_system
//       Access: Public
//  Description: Changes the coordinate system of the DNAData.  If the
//               coordinate system was previously different, this may
//               result in a conversion of the data.
////////////////////////////////////////////////////////////////////
void DNAData::
set_coordinate_system(CoordinateSystem new_coordsys) {
  if (new_coordsys == CS_default) {
    new_coordsys = get_default_coordinate_system();
  }
  if (new_coordsys != _coordsys &&
      (_coordsys != CS_default && _coordsys != CS_invalid)) {
    // Time to convert the data.
    //    r_transform(LMatrix4d::convert_mat(_coordsys, new_coordsys),
    //          LMatrix4d::convert_mat(new_coordsys, _coordsys),
    //          new_coordsys);
  }

  _coordsys = new_coordsys;
}




////////////////////////////////////////////////////////////////////
//     Function: DNAData::post_read
//       Access: Private
//  Description: Does whatever processing is appropriate after reading
//               the data in from an dna file.
////////////////////////////////////////////////////////////////////
void DNAData::
post_read(std::ostream &error) {

  // Resolve filenames that are relative to the dna file.
  //resolve_filenames(get_dna_filename().get_dirname());
}

////////////////////////////////////////////////////////////////////
//     Function: DNAData::pre_write
//       Access: Private
//  Description: Does whatever processing is appropriate just before
//               writing the data out to an dna file.
////////////////////////////////////////////////////////////////////
void DNAData::
pre_write() {

}

////////////////////////////////////////////////////////////////////
//     Function: DNAData::write
//       Access: Public, Virtual
//  Description: Writes the dna data out to the indicated output
//               stream.
////////////////////////////////////////////////////////////////////
void DNAData::
write(std::ostream &out, DNAStorage *store, int indent_level) const {
  // Write out anything the store wants to write
  store->fixup();
  store->write(out, indent_level);

  // Do not write out this group, just the children
  // DNAGroup::write(out, store, indent_level);
  // Write all the children
  pvector<PT(DNAGroup)>::const_iterator i = _group_vector.begin();
  for(; i != _group_vector.end(); ++i) {
    // Traverse each node in our vector
    PT(DNAGroup) group = *i;
    group->write(out, store, indent_level);
  }

  out << std::flush;
}

////////////////////////////////////////////////////////////////////
//     Function: DNAData::write
//       Access: Public, Virtual
//  Description: Writes the dna data out to the indicated Datagram.
////////////////////////////////////////////////////////////////////
void DNAData::
write(Datagram &datagram, DNAStorage *store) const {
    dna_cat.debug() << "Writing CDNA file...." << std::endl;
    // Write our header. This is will be checked on read.
    datagram.append_data("CDNA\n", 6);
    
    // Write out our current CDNA version.
    // This will let any future reader versions act accordingly. 
    datagram.add_uint8(CDNA_VER_MAJOR);
    datagram.add_uint8(CDNA_VER_MINOR);
    datagram.add_uint8(CDNA_VER_VERY_MINOR);
    
    // We need to save if the Datagram has stdfloat double enabled for reading.
    // Float sizes can vary in Panda3D and it's important to support it.
    bool stdfloat_double = datagram.get_stdfloat_double();
    datagram.add_bool(stdfloat_double);

    // For now, We compress by default. Some files above a certain size should
    // probably require compression in the future.
    bool compress = compress_cdna.get_value();
    datagram.add_bool(compress);

    int compression_level = std::min(std::max(cdna_compression_level.get_value(), 0), 9);

    dna_cat.debug() << "CDNA version: " << uint32_t(CDNA_VER_MAJOR) << "." << uint32_t(CDNA_VER_MINOR) << "." << uint32_t(CDNA_VER_VERY_MINOR) << std::endl;
    dna_cat.debug() << "Stdfloat Doubles: " << uint32_t(stdfloat_double) << std::endl;
    dna_cat.debug() << "Compression: " << uint32_t(compress) << std::endl;
    if (compress) {
        dna_cat.debug() << "Compression Level: " << compression_level << std::endl;
    }
    
    // Create a working Datagram to seperate our dna data from our header data.
    Datagram workDg = Datagram();

    // Write out anything the store wants to write
    store->fixup();
    store->write(workDg);

    // Do not write out this group, just the children
    // DNAGroup::write(datagram, store);
    // Write all the children
    pvector<PT(DNAGroup)>::const_iterator i = _group_vector.begin();
    for(; i != _group_vector.end(); ++i) {
        // Traverse each node in our vector
        PT(DNAGroup) group = *i;
        group->write(workDg, store);
    }
    

    DatagramIterator dgi(workDg, 0);
    // Grab the size for the data we just worked on.
    size_t size = dgi.get_remaining_size();
    // Create our string to store our data.
    std::string data;
    data.resize(size);
    // Extract our bytes out into the string.
    dgi.extract_bytes((unsigned char *)data.data(), size);
    // If we're compressing the data, Use Panda3d's built in compress string to compress it.
    if (compress) {
        data = compress_string(data, compression_level);
    }
    // Now we finally add the data to our main datagram.
    datagram.append_data(data.data(), data.size());
}


////////////////////////////////////////////////////////////////////
//     Function: DNAData::make_copy
//       Access: Public
//  Description: Copies all the children into our own vector
////////////////////////////////////////////////////////////////////
DNAGroup* DNAData::make_copy() {
  return new DNAData(*this);
}
