#pragma once

#include "dnabase.h"

#include <luse.h>
#include <typedReferenceCount.h>

class DNASuitPoint;
class DNAStorage;

class EXPCL_TOONTOWN DNASuitEdge : public TypedReferenceCount {
    PUBLISHED:
        DNASuitEdge(PT(DNASuitPoint) start_point, PT(DNASuitPoint) end_point, std::string zone_id);
        ~DNASuitEdge();

        PT(DNASuitPoint) get_end_point();
        PT(DNASuitPoint) get_start_point();

        std::string get_zone_id();

        bool operator==(const DNASuitEdge& other);

        void output(std::ostream& out);
        void set_zone_id(std::string zone_id);
        virtual void write(std::ostream& out, DNAStorage *store, int indent_level = 0);

    private:
        PT(DNASuitPoint) start_point;
        PT(DNASuitPoint) end_point;
        std::string zone_id;
    
    TYPE_HANDLE(DNASuitEdge, TypedReferenceCount);
};