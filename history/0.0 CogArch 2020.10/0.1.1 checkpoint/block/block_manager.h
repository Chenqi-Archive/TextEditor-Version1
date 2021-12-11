#pragma once

#include "block.h"
#include "../file/cga_file.h"

#include <list>
#include <algorithm>

using std::list;


class BlockManager : Uncopyable{
private:
	list<Block> _blocks;


public:
	Block& CreateBlock() {
		auto& block = _blocks.emplace_front();
		block._iterator = _blocks.begin();
		return block;
	}
	void DestroyBlock(Block& block) {
		// First clear all relationships.


		// Then remove it.
		_blocks.erase(block._iterator);
	}


public:
	void LoadFromFile(CGAFormat0_0::CGAFile file);
	void SaveToFile(CGAFormat0_0::CGAFile file);


public:
	// Inheritance relation.
	void CreateInheritanceRelation(Block& parent, Block& child) {
		if (HasInheritanceRelation(parent, child)) { return; }  // Relation already exists.
		parent._child_blocks.push_back(&child); // May skip this for large abstract blocks.
		child._parent_blocks.push_back(&parent);
	}
	void DestroyInheritanceRelation(Block& parent, Block& child) {
		auto it_parent = std::find(child._parent_blocks.begin(), child._parent_blocks.end(), &parent);
		if (it_parent == child._parent_blocks.end()) { return; }  // Relation does not exist.
		child._parent_blocks.erase(it_parent);
		auto it_child = std::find(parent._child_blocks.begin(), parent._child_blocks.end(), &child);
		if (it_child == parent._child_blocks.end()) { return; }  // Relation does not exist or not saved by parent.
		parent._child_blocks.erase(it_child);
	}
	bool HasInheritanceRelation(Block& parent, Block& child) const {
		// Only check child block's parent.
		auto it_parent = std::find(child._parent_blocks.begin(), child._parent_blocks.end(), &parent);
		return it_parent != child._parent_blocks.end();
	}

	// Dependence relation.
	// ...
};