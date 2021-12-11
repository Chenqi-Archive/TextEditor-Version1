#pragma once

#include "core.h"

#include "BlockStore/block_ref.h"

#include "WndDesign/geometry/point.h"

#include <string>
#include <vector>



struct BlockBase;

using ChildRef = BlockStore::BlockRef<BlockBase>;

using WndDesign::Point;


struct TextBlock {
	std::wstring text;
};


struct ImageBlock {
	uint64 id;
	std::wstring caption;
};


struct ListBlock {
	std::wstring caption;
	std::vector<ChildRef> child_list;
};


struct PlaneBlock {
	struct ChildInfo {
		ChildRef child;
		Point point;
		uint width;
	};
	std::wstring caption;
	std::vector<ChildInfo> child_list;
};