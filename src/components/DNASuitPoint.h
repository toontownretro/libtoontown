#pragma once

#include "dnabase.h"

#include <luse.h>
#include <typedReferenceCount.h>

class EXPCL_DNA DNASuitPoint : public TypedReferenceCount {
    public:
        enum DNASuitPointType {
            STREET_POINT = 0,
            FRONT_DOOR_POINT = 1,
            SIDE_DOOR_POINT = 2,
            COGHQ_IN_POINT = 3,
            COGHQ_OUT_POINT = 4,
        };

    PUBLISHED:
        DNASuitPoint(int index, DNASuitPointType type, LPoint3f pos, int lb_index = -1);
        ~DNASuitPoint();
        
        int get_graph_id();
        int get_index();
        int get_landmark_building_index();
        
        DNASuitPointType get_point_type();
        
        LPoint3f get_pos();
        
        bool is_terminal();
        
        void output(std::ostream &out);
        void set_graph_id(int graph_id);
        void set_index(int index);
        void set_landmark_building_index(int lb_index);
        void set_point_type(DNASuitPointType type);
        void set_pos(const LPoint3f &pos);
        virtual void write(std::ostream &out, int indent_level = 0);
        
    private:
        int graph_id = 0;
        int index;
        int lb_index;
        
        DNASuitPointType type;
        
        LPoint3f pos;
        
    TYPE_HANDLE(DNASuitPoint, TypedReferenceCount);
};