#include "dnaLandmarkBuilding.h"
#include "dnaStorage.h"

TypeHandle DNALandmarkBuilding::_type_handle;

/**
 *
 */
DNALandmarkBuilding::DNALandmarkBuilding(std::string initial_name) : DNANode(initial_name) {
    wall_color = LVecBase4f(1.0, 1.0, 1.0, 1.0);
}

/**
 *
 */
DNALandmarkBuilding::~DNALandmarkBuilding() {

}

/**
 *
 */
std::string DNALandmarkBuilding::get_article() {
    return article;
}

/**
 *
 */
std::string DNALandmarkBuilding::get_building_type() {
    return building_type;
}

/**
 *
 */
std::string DNALandmarkBuilding::get_code() {
    return code;
}

/**
 *
 */
std::string DNALandmarkBuilding::get_title() {
    return title;
}

/**
 *
 */
LVecBase4f DNALandmarkBuilding::get_wall_color() {
    return wall_color;
}

/**
 *
 */
void DNALandmarkBuilding::set_article(std::string &article) {
    this->article = article;
}

/**
 *
 */
void DNALandmarkBuilding::set_building_type(std::string &type) {
    this->building_type = type;
}

/**
 *
 */
void DNALandmarkBuilding::set_code(std::string &code) {
    this->code = code;
}

/**
 *
 */
void DNALandmarkBuilding::set_title(std::string &title) {
    this->title = title;
}

/**
 *
 */
void DNALandmarkBuilding::set_wall_color(const LVecBase4f &wall_color) {
    this->wall_color = wall_color;
}

/**
 *
 */
void DNALandmarkBuilding::setup_suit_building_origin(NodePath &parent, NodePath &node) {
    if (name.size() > 2 && name[0] == 't' && name[1] == 'b' && isdigit(name[2]) && name.find(':', 0) != std::string::npos) {
        name[0] = 's';
        NodePath found_path = node.find("**/*suit_building_origin");
        if (found_path.is_empty()) {
            dna_cat.warning() << "DNALandmarkBuilding " << name << " did not find **/*suit_building_origin" << std::endl;
            NodePath attached_path = parent.attach_new_node(name);
            attached_path.set_pos_hpr_scale(get_pos(), get_hpr(), get_scale());
            return;
        }
        found_path.wrt_reparent_to(parent);
        found_path.set_name(name);
    }
}

/**
 *
 */
NodePath DNALandmarkBuilding::traverse(NodePath &parent, DNAStorage *store, int editing) {
    NodePath _np = store->find_node(code);
    _np = _np.copy_to(parent);
    _np.set_name(name);
    _np.set_pos_hpr_scale(get_pos(), get_hpr(), get_scale());
    int block_number = atoi(store->get_block(name).c_str());
    title = store->get_title_from_block_number(block_number);
    article = store->get_article_from_block_number(block_number);
    if (!building_type.size()) {
        setup_suit_building_origin(parent, _np);
    }

    for (pvector<PT(DNAGroup)>::iterator it = children.begin(); it != children.end(); ++it) {
        (*it)->traverse(_np, store, editing);
    }

    if (editing) {
        PT(DNAGroup) PT_this = (DNAGroup*)this;
        PT(PandaNode) store_node = _np.node();
        store->store_DNAGroup(store_node, PT_this);
    } else {
        _np.flatten_strong();
        if (building_type.compare("hq") != 0) {
            NodePath door_origin = _np.find("**/*door_origin");
            if (!door_origin.is_empty()) {
                door_origin.remove_node();
            }
        }
        NodePath sign_origin = _np.find("**/*sign_origin");
        if (!sign_origin.is_empty()) {
            sign_origin.remove_node();
        }
    }
    return _np;
}

/**
 *
 */
void DNALandmarkBuilding::write(std::ostream &out, DNAStorage *store, int indent_level) {
    indent(out, indent_level);
    out << "landmark_building \"" << name << "\" [" << std::endl;
    indent(out, indent_level + 1);
    out << "code \"" << code << "\" ]" << std::endl;
    if (building_type.size()) {
        indent(out, indent_level + 1);
        out << "building_type \"" << building_type << "\" ]" << std::endl;
    }
    if (article.size()) {
        indent(out, indent_level + 1);
        out << "article \"" << article << "\" ]" << std::endl;
    }
    indent(out, indent_level + 1);
    out << "title \"" << title << "\" ]" << std::endl;

    indent(out, indent_level + 1);
    out << "pos [ " << pos[0] << " " << pos[1] << " " << pos[2] << " ]" << std::endl;

    indent(out, indent_level + 1);
    if (temp_hpr_fix) {
        out << "nhpr [ ";
    } else {
        out << "hpr [ ";
    }
    out << hpr[0] << " " << hpr[1] << " " << hpr[2] << " ]" << std::endl;

    if (wall_color != LVecBase4f(1.0, 1.0, 1.0, 1.0)) {
        indent(out, indent_level + 1);
        out << "color [ " << wall_color[0] << " " << wall_color[1] << " " << wall_color[2] << " " << wall_color[3] << " ]" << std::endl;
    }
    for (pvector<PT(DNAGroup)>::iterator it = children.begin(); it != children.end(); ++it) {
        (*it)->write(out, store, indent_level + 1);
    }
    indent(out, indent_level);
    out << "]" << std::endl;
}