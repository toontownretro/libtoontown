#pragma once

#include "dnabase.h"

#include <luse.h>
#include <typedReferenceCount.h>
#include <vector_int.h>

class EXPCL_TOONTOWN DNASuitPath : public TypedReferenceCount {
    PUBLISHED:
        DNASuitPath();
        DNASuitPath(int reserve_length);
        DNASuitPath(const DNASuitPath &path);
        ~DNASuitPath();

        void copy(const DNASuitPath &path);
        int get_num_points();
        int get_point_index(int i);
        void output(std::ostream &out);

    public:
        void add_point(int point);
        void reverse_path();

    private:
        vector_int points;

    TYPE_HANDLE(DNASuitPath, TypedReferenceCount);
};