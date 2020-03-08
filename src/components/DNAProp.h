#pragma once

#include "dnabase.h"

#include "DNANode.h"

#include <luse.h>
#include <typedReferenceCount.h>
#include <nodePath.h>
#include <pvector.h>

class DNAStorage;

class EXPCL_DNA DNAProp : public DNANode {
	PUBLISHED:
		DNAProp(std::string initial_name);
		DNAProp(const DNAProp& prop);
		~DNAProp();

		std::string get_code();

		LVector4f get_color();

		void set_code(std::string &code);
		void set_color(const LVecBase4f &color);

	public:
		virtual NodePath traverse(NodePath& parent, DNAStorage* store, int editing = 0);

		virtual void write(std::ostream& out, DNAStorage* store, int indent_level = 0);

	protected:
		std::string code;
		LVecBase4f color;

	TYPE_HANDLE(DNAProp, DNANode);
};