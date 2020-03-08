#pragma once

#include "dnabase.h"

#include "DNAGroup.h"
#include "DNAVisGroup.h"
#include "DNABattleCell.h"
#include "DNASuitPoint.h"

#include <luse.h>
#include <typedReferenceCount.h>
#include <pandaNode.h>
#include <modelNode.h>
#include <textFont.h>
#include <pvector.h>
#include <pmap.h>

class EXPCL_DNA DNAStorage {
    PUBLISHED:
        DNAStorage();
        ~DNAStorage();

        NodePath find_node(std::string &dna_string);

        void reset_DNAGroups();
        void reset_hood_nodes();
        void reset_nodes();
        void reset_place_nodes();
        void store_DNAGroup(PT(PandaNode) node, PT(DNAGroup) group);
        void store_DNAVisGroup(PT(PandaNode) node, PT(DNAVisGroup) group);
        void store_battle_cell(PT(DNABattleCell) cell);
        void store_block_article(std::string &block, std::string &article);
        void store_block_building_type(std::string &block, std::string &type);
        void store_block_door_pos_hpr(std::string &block, const LPoint3f &pos, const LPoint3f &hpr);
        void store_block_number(std::string &block, std::string &zone_id);
        void store_block_sign_transform(std::string &block, const LMatrix4f &mat);
        void store_block_title(std::string& block, std::string& title);
        void store_catalog_string(std::string &catalog_string, std::string &dna_string);
        void store_font(std::string &code_string, PT(TextFont) font);
        void store_hood_node(std::string &code_string, NodePath &node, std::string &code_category);
        void store_node(std::string &code_string, NodePath &node, std::string &code_category);
        void store_place_node(std::string &code_string, NodePath &node, std::string &code_category);
        void store_texture(std::string &code_string, PT(Texture) texture);

    private:
        pmap<std::string, std::string> Catalog2DNAStringMap;
        pmap<std::string, PT(Texture)> Code2TextureMap;
        pmap<std::string, NodePath> Code2NodeMap;
        pmap<std::string, PT(TextFont)> Code2FontMap;
        pmap<std::string, NodePath> Code2HoodNodeMap;
        pmap<int, int> Block2NumberMap;
        pmap<int, std::pair<LPoint3f, LPoint3f>> Block2DoorPosHprMap;
        pmap<int, LMatrix4f> Block2TransformMap;
        pmap<int, std::string> Block2TitleMap;
        pmap<int, std::string> Block2ArticleMap;
        pmap<int, std::string> Block2BuildingTypeMap;
        pmap<std::string, NodePath> Code2PlaceNodeMap;
        pmap<PT(PandaNode), PT(DNAGroup)> Node2GroupMap;
        pmap<PT(PandaNode), PT(DNAVisGroup)> Node2VisGroupMap;
        pmap<int, PT(DNASuitPoint)> Index2SuitPointMap;
        pvector<PT(DNABattleCell)> BattleCells;
        pvector<PT(DNAVisGroup)> VisGroupsAI;
};