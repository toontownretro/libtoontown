#pragma once

#include "dnabase.h"

#include "dnaDoor.h"

#include <luse.h>
#include <typedReferenceCount.h>
#include <decalEffect.h>
#include <nodePath.h>
#include <pvector.h>

class DNAStorage;

/**
 * A door for a flat buildings
 */
class EXPCL_TOONTOWN DNAFlatDoor : public DNADoor {
	PUBLISHED:
	    DNAFlatDoor(std::string initial_name);
		DNAFlatDoor(const DNAFlatDoor &door);
		~DNAFlatDoor();

	public:
		virtual NodePath traverse(NodePath& parent, DNAStorage* store, int editing = 0);

		virtual void write(std::ostream& out, DNAStorage* store, int indent_level = 0);

	TYPE_HANDLE(DNAFlatDoor, DNADoor);
};