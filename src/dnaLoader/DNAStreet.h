#pragma once

#include "dnabase.h"

#include "DNANode.h"

#include <luse.h>
#include <typedReferenceCount.h>
#include <nodePath.h>
#include <pvector.h>

class DNAStorage;

class EXPCL_TOONTOWN DNAStreet : public DNANode {
	PUBLISHED:
		DNAStreet(std::string initial_name);
		DNAStreet(const DNAStreet &street);
		~DNAStreet();

		std::string get_code();
		std::string get_curb_texture();
		std::string get_sidewalk_texture();
		std::string get_street_texture();

		LVecBase4f get_curb_color();
		LVecBase4f get_sidewalk_color();
		LVecBase4f get_street_color();

		void set_code(std::string &code);
		void set_curb_color(LVecBase4f &color);
		void set_curb_texture(std::string &curb_texture);
		void set_sidewalk_color(LVecBase4f &color);
		void set_sidewalk_texture(std::string &sidewalk_texture);
		void set_street_color(LVecBase4f &color);
		void set_street_texture(std::string &street_texture);

	public:
		virtual NodePath traverse(NodePath &parent, DNAStorage *store, int editing = 0);
		virtual void write(std::ostream &out, DNAStorage *store, int indent_level = 0);

	protected:
		std::string code;
		std::string curb_texture;
		std::string sidewalk_texture;
		std::string street_texture;

		LVecBase4f curb_color;
		LVecBase4f sidewalk_color;
		LVecBase4f street_color;

	TYPE_HANDLE(DNAStreet, DNANode);
};