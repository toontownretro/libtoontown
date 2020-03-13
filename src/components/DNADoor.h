#pragma once

#include "dnabase.h"

#include "DNAGroup.h"

#include <luse.h>
#include <typedReferenceCount.h>
#include <decalEffect.h>
#include <nodePath.h>
#include <pvector.h>

class DNAStorage;

class EXPCL_DNA DNADoor : public DNAGroup {
	PUBLISHED:
		DNADoor(std::string initial_name);
		DNADoor(const DNADoor &door);
		~DNADoor();

		std::string get_code();

		LVecBase4f get_color();

		void set_code(std::string &code);
		void set_color(const LVecBase4f &color);

	public:
		virtual NodePath traverse(NodePath &parent, DNAStorage *store, int editing = 0);
		virtual void write(std::ostream &out, DNAStorage *store, int indent_level = 0);

	protected:
		void setup_door(NodePath &node, const NodePath &parent, const NodePath &door_origin, DNAStorage *store, std::string &block, const LVecBase4f &color);

		std::string code;
		LVecBase4f color;

	TYPE_HANDLE(DNADoor, DNAGroup);
};