#pragma once

#include "dnabase.h"

#include "dnaProp.h"

#include <string>
#include <luse.h>
#include <typedReferenceCount.h>
#include <nodePath.h>
#include <modelNode.h>
#include <pvector.h>

class DNAStorage;

class EXPCL_TOONTOWN DNAAnimProp : public DNAProp {
	PUBLISHED:
		DNAAnimProp(std::string initial_name);
		DNAAnimProp(const DNAAnimProp& anim_prop);
		~DNAAnimProp();

		std::string get_anim();

		void set_anim(std::string &anim);

	public:
		virtual NodePath traverse(NodePath& parent, DNAStorage* store, int editing = 0);

		virtual void write(std::ostream& out, DNAStorage* store, int indent_level = 0);

	protected:
		std::string anim;

	TYPE_HANDLE(DNAAnimProp, DNAProp);
};