#include "DNAStorage.h"

DNAStorage::DNAStorage() {

}

DNAStorage::~DNAStorage() {

}

NodePath DNAStorage::find_node(std::string dna_string) {
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
	dna_cat.warning() << "node: " << dna_string << " not found in pool, hood, or place map, returning empty NodePath" << std::endl;
	return NodePath();
}

void DNAStorage::store_DNAGroup(PT(PandaNode) node, PT(DNAGroup) group) {
	Node2GroupMap[node] = group;
}