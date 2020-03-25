#pragma once
#include "dnabase.h"

#include <luse.h>
#include <typedReferenceCount.h>
#include <nodePath.h>
#include <pvector.h>

class DNASuitPoint;

class EXPCL_TOONTOWN SuitLeg {
	public:
        enum Type {
            WalkFromStreet = 0x0,
            WalkToStreet = 0x1,
            Walk = 0x2,
            FromSky = 0x3,
            ToSky = 0x4,
            FromSuitBuilding = 0x5,
            ToSuitBuilding = 0x6,
            ToToonBuilding = 0x7,
            FromCogHQ = 0x8,
            ToCogHQ = 0x9,
            Off = 0xA,
        };

	PUBLISHED:
        int get_block_number();
        int get_point_a();
        int get_point_b();
        int get_zone_id();

        double get_leg_time();
        double get_start_time();

        LPoint3f get_pos_a();
        LPoint3f get_pos_b();
        LPoint3f get_pos_at_time(double time);

        std::string get_type_name(SuitLeg::Type type);

        void output(std::ostream &out);

    public:
        SuitLeg(SuitLeg::Type type, double start_time, double leg_time, int zone_id, int block_number, DNASuitPoint *point_a, DNASuitPoint *point_b);
        ~SuitLeg();
        void operator=(SuitLeg &other);

    protected:
        Type type;
        double start_time;
        double leg_time;
        int zone_id;
        int block_number;
        int point_a;
        int point_b;
        LPoint3f pos_a;
        LPoint3f pos_b;
};