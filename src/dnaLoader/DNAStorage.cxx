#include "DNAStorage.h"

DNAStorage::DNAStorage() {

}

DNAStorage::~DNAStorage() {

}

PT(TextFont) DNAStorage::find_font(std::string &dna_string) {
	for (pmap<std::string, PT(TextFont)>::iterator it = Code2FontMap.begin(); it != Code2FontMap.end(); ++it) {
		if (it->first.compare(dna_string) == 0) {
			return it->second;
		}
	}
	dna_cat.error() << "font: " << dna_string << " not found in map" << std::endl;
	return nullptr;
}

NodePath DNAStorage::find_node(std::string &dna_string) {
	// Search all the maps a code can be present in and give us the node we may want.
	for (pmap<std::string, NodePath>::iterator it = Code2NodeMap.begin(); it != Code2NodeMap.end(); ++it) {
		if (it->first.compare(dna_string) == 0) {
			return it->second;
		}
	}
	for (pmap<std::string, NodePath>::iterator it = Code2HoodNodeMap.begin(); it != Code2HoodNodeMap.end(); ++it) {
		if (it->first.compare(dna_string) == 0) {
			return it->second;
		}
	}
	for (pmap<std::string, NodePath>::iterator it = Code2PlaceNodeMap.begin(); it != Code2PlaceNodeMap.end(); ++it) {
		if (it->first.compare(dna_string) == 0) {
			return it->second;
		}
	}
	// In libtoontown, .debug() and .spam() return a null Notify stream for both dna_cat and pets_cat.
	// This means that this notify out has to be either of those options.
	dna_cat.debug() << "node: " << dna_string << " not found in pool, hood, or place map, returning empty NodePath" << std::endl;
	return NodePath();
}

PT(Texture) DNAStorage::find_texture(std::string &dna_string) {
	for (pmap<std::string, PT(Texture)>::iterator it = Code2TextureMap.begin(); it != Code2TextureMap.end(); ++it) {
		if (it->first.compare(dna_string) == 0) {
			return it->second;
		}
	}
	dna_cat.error() << "texture: " << dna_string << " not found in map" << std::endl;
	return nullptr;
}

std::string DNAStorage::get_article_from_block_number(int block_number) {
	if (Block2ArticleMap.find(block_number) == Block2ArticleMap.end()) {
		dna_cat.error() << "block number: " << block_number << " not found in article map" << std::endl;
		return "";
	}
	return Block2ArticleMap[block_number];
}

std::string DNAStorage::get_block(std::string &name) {
	return name.substr(2, name.find(':', 0) - 2);
}

std::string DNAStorage::get_block_building_type(int block_number) {
	if (Block2BuildingTypeMap.find(block_number) == Block2BuildingTypeMap.end()) {
		dna_cat.debug() << "block number: " << block_number << " not found in building type map" << std::endl;
		return "";
	}
	return Block2BuildingTypeMap[block_number];
}

int DNAStorage::get_block_number_at(unsigned int index) {
	pmap<int, int>::iterator index_it = Block2NumberMap.begin();
	std::advance(index_it, (int)index);
	for (pmap<int, int>::iterator it = Block2NumberMap.begin(); it != Block2NumberMap.end(); it++) {
		if (it == Block2NumberMap.end()) {
			dna_cat.error() << "DNAStorage::get_block_number_at index not found, returning 0" << std::endl;
			break;
		} else if (it == index_it) {
			return it->second;
		}
	}
	return 0;
}

PosHpr DNAStorage::get_door_pos_hpr_block_at(unsigned int index) {
	pmap<int, PosHpr>::iterator index_it = Block2DoorPosHprMap.begin();
	std::advance(index_it, (int)index);
	for (pmap<int, PosHpr>::iterator it = Block2DoorPosHprMap.begin(); it != Block2DoorPosHprMap.end(); it++) {
		if (it == Block2DoorPosHprMap.end()) {
			dna_cat.error() << "DNAStorage::get_door_pos_hpr_block_at index not found, returning 0" << std::endl;
			break;
		} else if (it == index_it) {
			return it->second;
		}
	}
	return PosHpr();
}

PosHpr DNAStorage::get_door_pos_hpr_from_block_number(int block_number) {
	if (Block2DoorPosHprMap.find(block_number) == Block2DoorPosHprMap.end()) {
		dna_cat.error() << "block number: " << block_number << " not found in map" << std::endl;
		return PosHpr();
	}
	return Block2DoorPosHprMap[block_number];
}

int DNAStorage::get_highest_suit_point_index() {
	int top_index = -1;
	for (pvector<PT(DNASuitPoint)>::iterator it = SuitPoints.begin(); it != SuitPoints.end(); ++it) {
		if ((*it)->get_index() > top_index) {
			top_index = (*it)->get_index();
		}
	}
	return top_index;
}

std::string DNAStorage::get_title_from_block_number(int block_number) {
	if (Block2TitleMap.find(block_number) == Block2TitleMap.end()) {
		dna_cat.error() << "block number: " << block_number << " not found in title map" << std::endl;
		return "";
	}
	return Block2TitleMap[block_number];
}

void DNAStorage::reset_DNAGroups() {
	Node2GroupMap.clear();
}

void DNAStorage::reset_DNAVisGroups() {
	Node2VisGroupMap.clear();
}

void DNAStorage::reset_DNAVisGroupsAI() {
	VisGroupsAI.clear();
}

void DNAStorage::reset_battle_cells() {
	BattleCells.clear();
}

void DNAStorage::reset_block_article() {
	Block2ArticleMap.clear();
}

void DNAStorage::reset_block_door_pos_hprs() {
	Block2DoorPosHprMap.clear();
}

void DNAStorage::reset_block_numbers() {
	Block2NumberMap.clear();
}

void DNAStorage::reset_block_sign_transforms() {
	Block2TransformMap.clear();
}

void DNAStorage::reset_block_title() {
	Block2TitleMap.clear();
}

void DNAStorage::reset_hood() {
	reset_hood_nodes();
	reset_place_nodes();
	reset_suit_points();
	reset_battle_cells();
}

void DNAStorage::reset_hood_nodes() {
	Code2HoodNodeMap.clear();
}

void DNAStorage::reset_nodes() {
	Code2NodeMap.clear();
}

void DNAStorage::reset_place_nodes() {
	Code2PlaceNodeMap.clear();
}

void DNAStorage::reset_suit_points() {
	SuitPoints.clear();
	Index2SuitPointMap.clear();
	StartPoint2SuitEdgeMap.clear();
}

void DNAStorage::reset_textures() {
	Code2TextureMap.clear();
}

void DNAStorage::store_DNAGroup(PT(PandaNode) node, PT(DNAGroup) group) {
	Node2GroupMap[node] = group;
}

void DNAStorage::store_DNAVisGroup(PT(PandaNode) node, PT(DNAVisGroup) group) {
	Node2VisGroupMap[node] = group;
}

void DNAStorage::store_battle_cell(PT(DNABattleCell) cell) {
	BattleCells.push_back(cell);
}

void DNAStorage::store_block_article(std::string &block, std::string &article) {
	Block2ArticleMap[atoi(get_block(block).c_str())] = article;
}

void DNAStorage::store_block_building_type(std::string &block, std::string &type) {
	int true_block = atoi(get_block(block).c_str());

	// In libtoontown, .debug() and .spam() return a null Notify stream for both dna_cat and pets_cat.
	// This means that this notify out has to be either of those options.
	dna_cat.debug() << "block: " << block << " blocknum: " << true_block << " type: " << type << std::endl;
	Block2BuildingTypeMap[true_block] = type;
}

void DNAStorage::store_block_door_pos_hpr(std::string &block, const LPoint3f &pos, const LPoint3f &hpr) {
	PosHpr pos_hpr;
	pos_hpr.pos = pos;
	pos_hpr.hpr = hpr;
	Block2DoorPosHprMap[atoi(get_block(block).c_str())] = pos_hpr;
}

void DNAStorage::store_block_number(std::string &block, std::string &zone_id) {
	Block2NumberMap[atoi(get_block(block).c_str())] = atoi(zone_id.c_str());
}

void DNAStorage::store_block_sign_transform(std::string &block, const LMatrix4f &mat) {
	Block2TransformMap[atoi(get_block(block).c_str())] = mat;
}

void DNAStorage::store_block_title(std::string &block, std::string &title) {
	Block2TitleMap[atoi(get_block(block).c_str())] = title;
}

void DNAStorage::store_catalog_string(std::string &catalog_string, std::string &dna_string) {
	Catalog2DNAStringMap[catalog_string] = dna_string;
}

void DNAStorage::store_font(std::string &code_string, PT(TextFont) font) {
	Code2FontMap[code_string] = font;
}

void DNAStorage::store_hood_node(std::string &code_string, NodePath &node, std::string &code_category) {
	NodePath &path = node;
	if (code_category == "holiday_prop") {
		// Best i could do. It's likely a NodePath is constructed with the ModelNode.
		// But the code has been optimized and has to be rewritten.

		ModelNode modelNode(path.get_name());
		NodePath modelPath((PandaNode *)&modelNode);
		path = path.copy_to(modelPath);
	}
	if (path.node()) {
		path.set_tag("DNACode", code_string);
		path.set_tag("DNARoot", code_category);
	}
	Code2HoodNodeMap[code_string] = path;
}

void DNAStorage::store_node(std::string &code_string, NodePath &node, std::string &code_category) {
	NodePath &path = node;
	if (code_category == "holiday_prop") {
		// Best i could do. It's likely a NodePath is constructed with the ModelNode.
		// But the code has been optimized and has to be rewritten.

		ModelNode modelNode(path.get_name());
		NodePath modelPath((PandaNode *)&modelNode);
		path = path.copy_to(modelPath);
	}
	if (path.node()) {
		path.set_tag("DNACode", code_string);
		path.set_tag("DNARoot", code_category);
	}
	Code2NodeMap[code_string] = path;
}

void DNAStorage::store_place_node(std::string &code_string, NodePath &node, std::string &code_category) {
	NodePath &path = node;
	if (code_category == "holiday_prop") {
		// Best i could do. It's likely a NodePath is constructed with the ModelNode.
		// But the code has been optimized and has to be rewritten.

		ModelNode modelNode(path.get_name());
		NodePath modelPath((PandaNode *)&modelNode);
		path = path.copy_to(modelPath);
	}
	if (path.node()) {
		path.set_tag("DNACode", code_string);
		path.set_tag("DNARoot", code_category);
	}
	Code2PlaceNodeMap[code_string] = path;
}

void DNAStorage::store_suit_point(DNASuitPoint::DNASuitPointType type, LPoint3f pos) {
	// This is honestly my best guess.
	for (pvector<PT(DNASuitPoint)>::iterator it = SuitPoints.begin(); it != SuitPoints.end(); ++it) {
		DNASuitPoint *point = *it;
		if (!point) {
			// Added by me for security.
			continue;
		}
		LPoint3f point_pos = point->get_pos();
		LPoint3f pos_diff = point_pos - pos;
		constexpr double check_pos = 0.8999999761581420898;
		if (pos_diff[0] < check_pos && pos_diff[0] > -check_pos && pos_diff[1] < check_pos && pos_diff[1] > -check_pos && pos_diff[2] < check_pos && pos_diff[2] > -check_pos) {
			return;
		}
	}
	int new_index = get_highest_suit_point_index() + 1;
	PT(DNASuitPoint) new_suit_point = new DNASuitPoint(new_index, type, pos);
	store_suit_point(new_suit_point);
}

void DNAStorage::store_suit_point(PT(DNASuitPoint) point) {
	SuitPoints.push_back(point);
	Index2SuitPointMap[point->get_index()] = point;
}

void DNAStorage::store_texture(std::string &code_string, PT(Texture) texture) {
	texture->set_minfilter(SamplerState::FilterType::FT_linear_mipmap_linear);
    texture->set_magfilter(SamplerState::FilterType::FT_linear);
	texture->set_anisotropic_degree(4);
	Code2TextureMap[code_string] = texture;
}