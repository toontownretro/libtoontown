#pragma once

#include "dnabase.h"

#include "dnaNode.h"

#include <luse.h>
#include <typedReferenceCount.h>
#include <nodePath.h>
#include <pvector.h>

class DNAStorage;

/*
 * A landmark building.
 */
class EXPCL_TOONTOWN DNALandmarkBuilding : public DNANode {
    PUBLISHED:
        DNALandmarkBuilding(std::string initial_name);
        ~DNALandmarkBuilding();

        std::string get_article();
        std::string get_building_type();
        std::string get_code();
        std::string get_title();

        LVecBase4f get_wall_color();

        void set_article(std::string &article);
        void set_building_type(std::string &type);
        void set_code(std::string &code);
        void set_title(std::string &title);
        void set_wall_color(const LVecBase4f &wall_color);

    public:
        void setup_suit_building_origin(NodePath &parent, NodePath &node);

        virtual NodePath traverse(NodePath &parent, DNAStorage *store, int editing = 0);
        virtual void write(std::ostream &out, DNAStorage *store, int indent_level = 0);

    private:
        std::string article;
        std::string building_type;
        std::string code;
        std::string title;

        LVecBase4f wall_color;

    TYPE_HANDLE(DNALandmarkBuilding, DNANode);
};