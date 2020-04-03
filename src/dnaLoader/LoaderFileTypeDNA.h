#pragma once

#include "dnabase.h"

#include "loaderFileType.h"

class DNAStorage;

class EXPCL_TOONTOWN LoaderFileTypeDNA : public LoaderFileType {
    public:
        LoaderFileTypeDNA();
        virtual ~LoaderFileTypeDNA();

        virtual std::string get_name() const;
        virtual std::string get_extension() const;

        virtual PT(PandaNode) load_file(const Filename &path, const LoaderOptions &options, BamCacheRecord *record) const;

        virtual void resolve_filename(Filename &filename) const;

        static DNAStorage *_dna_store;

    TYPE_HANDLE(LoaderFileTypeDNA, LoaderFileType);
};