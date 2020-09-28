// Filename: dnaSuitPoint.h
// Created by:  shochet (28Jan01)
//
////////////////////////////////////////////////////////////////////
#pragma once

#include "toontownbase.h"
#include "dnaConstants.h"

#include "config_dna.h"
#include "typedObject.h"
#include "pointerTo.h"
#include "typedReferenceCount.h"
#include "luse.h"

////////////////////////////////////////////////////////////////////
//       Class : DNASuitPoint
// Description :
////////////////////////////////////////////////////////////////////
class EXPCL_TOONTOWN DNASuitPoint : public TypedReferenceCount {
    PUBLISHED:
        enum DNASuitPointType { 
            STREET_POINT,
            FRONT_DOOR_POINT,
            SIDE_DOOR_POINT,
            COGHQ_IN_POINT,
            COGHQ_OUT_POINT
        };

        DNASuitPoint(int index, DNASuitPointType type, LPoint3f pos, int lb_index = -1);
        INLINE void set_index(int index);
        INLINE int get_index() const;
        INLINE void set_point_type(DNASuitPointType type);
        INLINE DNASuitPointType get_point_type() const;
        INLINE void set_pos(LPoint3f pos);
        INLINE LPoint3f get_pos() const;
        INLINE void set_graph_id(int graph_id);
        INLINE int get_graph_id() const;
        INLINE void set_landmark_building_index(int lb_index);
        INLINE int get_landmark_building_index() const;

        INLINE bool is_terminal() const;

        void output(std::ostream &out) const;

        virtual void write(std::ostream &out, int indent_level = 0) const;
        virtual void write(Datagram &datagram) const;
        virtual void make_from_dgi(DatagramIterator &dgi);
      
    public:
        DNASuitPoint();

    private:
        int _index;
        DNASuitPointType _type;
        LPoint3f _pos;
        // Sequence number to identify which of several disconnected graphs
        // the suit point may belong to.
        int _graph_id;
        // Index of landmark building if this is a door point
        int _lb_index = -1;

    public:
        static TypeHandle get_class_type() { return _type_handle; }
        static void init_type() {
          TypedReferenceCount::init_type();
          register_type(_type_handle, "DNASuitPoint",
                        TypedReferenceCount::get_class_type()
                        );
        }
        virtual TypeHandle get_type() const { return get_class_type(); }
        virtual TypeHandle force_init_type() {init_type(); return get_class_type();}

    private:
        static TypeHandle _type_handle;
};


INLINE std::ostream &operator << (std::ostream &out, const DNASuitPoint &point) {
    point.output(out);
    return out;
}

std::ostream &operator << (std::ostream &out, DNASuitPoint::DNASuitPointType type);

#include "dnaSuitPoint.I"