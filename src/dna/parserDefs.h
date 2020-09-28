// Filename: parserDefs.h
// Created by:  shochet (25May00)
//
////////////////////////////////////////////////////////////////////

#pragma once

#include "toontownbase.h"

#include "pointerTo.h"
#include "pointerToArray.h"
#include "pta_double.h"
#include "luse.h"
#include <string>
#include "pvector.h"

#include "dnaData.h"
#include "dnaGroup.h"
#include "dnaSuitPoint.h"


typedef pvector< std::string > StringVector;

void dna_init_parser(std::istream &in, std::ostream &err, const std::string &filename, DNAData *top_node);

void dna_cleanup_parser();

// This structure holds the return value for each token.
// Traditionally, this is a union, and is declared with the %union
// declaration in the parser.y file, but unions are pretty worthless
// in C++ (you can't include an object that has member functions in a
// union), so we'll use a class instead.  That means we need to
// declare it externally, here.

#define YYSTYPE DNAYYSTYPE

class YYSTYPE {
    public:
        double _number;
        std::string _string;
        StringVector _string_vector;
        PTA_double _number_list;
        LVecBase3f _v3;
        LColorf _color;
        bool _bool;
        PT(DNAGroup) _dna_group;
        DNASuitPoint::DNASuitPointType _suit_point_type;
};