#include "suitLeg.h"

#include "dnaSuitPoint.h"

SuitLeg::SuitLeg(SuitLeg::Type type, double start_time, double leg_time, int zone_id, int block_number, DNASuitPoint *point_a, DNASuitPoint *point_b) {
    this->start_time = start_time;
    this->zone_id = zone_id;
    this->leg_time = leg_time;
    this->type = type;
    this->block_number = block_number;
    this->point_a = point_a->get_index();
    this->point_b = point_b->get_index();
    pos_a = point_a->get_pos();
    pos_b = point_b->get_pos();
}

SuitLeg::~SuitLeg() {

}

void SuitLeg::operator=(SuitLeg &other) {
    type = other.type;
    start_time = other.start_time;
    leg_time = other.leg_time;
    zone_id = other.zone_id;
    block_number = other.block_number;
    point_a = other.point_a;
    point_b = other.point_b;
    pos_a = other.pos_a;
    pos_b = other.pos_b;
}

int SuitLeg::get_block_number() {
    return block_number;
}

double SuitLeg::get_leg_time() {
    return leg_time;
}

int SuitLeg::get_point_a() {
    return point_a;
}

int SuitLeg::get_point_b() {
    return point_b;
}

LPoint3f SuitLeg::get_pos_a() {
    return pos_a;
}

LPoint3f SuitLeg::get_pos_at_time(double time) {
    LPoint3f point;

    switch (type) {
        case Type::FromSky:
        case Type::FromSuitBuilding:
        case Type::FromCogHQ:
            point = pos_a;
            break;
        case Type::ToSky:
        case Type::ToSuitBuilding:
        case Type::ToToonBuilding:
        case Type::ToCogHQ:
        case Type::Off:
            point = pos_b;
            break;
        default:
            if (time >= 0.0) {
                if (time > leg_time) {
                    point = pos_b;
                }
                else {
                    double new_time = time / leg_time;
                    point = (pos_b - pos_a) * new_time;
                    point = pos_a + point;
                }
            }
            else {
                point = pos_a;
            }
            break;
    }
    return point;
}

LPoint3f SuitLeg::get_pos_b() {
    return pos_b;
}

double SuitLeg::get_start_time() {
    return start_time;
}

std::string SuitLeg::get_type_name(SuitLeg::Type type) {
    switch (type) {
        case Type::WalkFromStreet:
            return "WalkFromStreet";
        case Type::WalkToStreet:
            return "WalkToStreet";
        case Type::Walk:
            return "Walk";
        case Type::FromSky:
            return "FromSky";
        case Type::ToSky:
            return "ToSky";
        case Type::FromSuitBuilding:
            return "FromSuitBuilding";
        case Type::ToSuitBuilding:
            return "ToSuitBuilding";
        case Type::ToToonBuilding:
            return "ToToonBuilding";
        case Type::FromCogHQ:
            return "FromCogHQ";
        case Type::ToCogHQ:
            return "ToCogHQ";
        case Type::Off:
            return "Off";
        default:
            return "**invalid**";
    }
}

int SuitLeg::get_zone_id() {
    return zone_id;
}

void SuitLeg::output(std::ostream &out) {
    out << "(" << get_type_name(type) << ", " << start_time << " (" << leg_time << "), " << zone_id << ", " << point_a << ", " << point_b << ")";
}