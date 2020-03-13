#pragma once

#include "dnabase.h"

#include "DNAAnimProp.h"

#include <string>
#include <luse.h>
#include <typedReferenceCount.h>
#include <nodePath.h>
#include <modelNode.h>
#include <pvector.h>

class DNAStorage;

class EXPCL_DNA DNAInteractiveProp : public DNAAnimProp {
	PUBLISHED:
		DNAInteractiveProp(std::string initial_name);
		DNAInteractiveProp(const DNAInteractiveProp &interactive_prop);
		~DNAInteractiveProp();

		int get_cell_id();

		void set_cell_id(int cell_id);

	public:
		virtual NodePath traverse(NodePath& parent, DNAStorage* store, int editing = 0);

		virtual void write(std::ostream& out, DNAStorage* store, int indent_level = 0);

	protected:
		int cell_id;

	TYPE_HANDLE(DNAInteractiveProp, DNAAnimProp);
};