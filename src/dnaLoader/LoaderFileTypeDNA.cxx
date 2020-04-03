#include "LoaderFileTypeDNA.h"

#include "DNAStorage.h"

#include <coordinateSystem.h>
#include <virtualFileSystem.h>

TypeHandle LoaderFileTypeDNA::_type_handle;

DNAStorage * LoaderFileTypeDNA::_dna_store = nullptr;

LoaderFileTypeDNA::LoaderFileTypeDNA() {

}

LoaderFileTypeDNA::~LoaderFileTypeDNA() {

}

void LoaderFileTypeDNA::resolve_filename(Filename &filename) const {
	VirtualFileSystem *vfs = VirtualFileSystem::get_global_ptr();
	ConfigVariableSearchPath &dna_path = get_dna_path();
	ConfigVariableSearchPath &model_path = get_model_path();

	vfs->resolve_filename(filename, dna_path.get_value());
	vfs->resolve_filename(filename, model_path.get_value());
}

std::string LoaderFileTypeDNA::get_name() const {
	return "DNA";
}

std::string LoaderFileTypeDNA::get_extension() const {
	return "dna";
}

PT(PandaNode) LoaderFileTypeDNA::load_file(const Filename &path, const LoaderOptions &options, BamCacheRecord *record) const {
	if (!_dna_store) {
		_dna_store = new DNAStorage();
		// Finish RE
	}
	PT(PandaNode) dna_node = load_dna_file(_dna_store, path.get_fullpath(), CoordinateSystem::CS_default, 0);
	return dna_node;
}