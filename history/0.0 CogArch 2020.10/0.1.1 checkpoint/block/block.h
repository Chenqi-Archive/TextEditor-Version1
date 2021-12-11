#pragma once

#include <string>
#include <list>
#include <vector>

using std::wstring;  // For storing block contents.
using std::vector;   // For maintaining parent and child blocks.  (May use list or set later.)


class Block : Uncopyable {
private:
	friend class BlockManager;
	std::list<Block>::iterator _iterator;

	struct _Child_Block_Info { 
		Block* child; 
		Point position; 
	};
	struct _Parent_Block_Info { 
		Block* parent;
		list<_Child_Block_Info>::iterator iterator;
		bool operator<(const _Parent_Block_Info& other) const { return parent < other.parent; }
	};

private:
	wstring _content;

	vector<_Parent_Block_Info> _parent_blocks;  // All abstract blocks.
	list<_Child_Block_Info> _child_blocks;

	//vector<Block*> dependent_blocks;
	//vector<Block*> referenced_blocks;


public:
};