#pragma once

#include "block.h"

#include "BlockStore/block_layout.h"
#include "BlockStore/stl_helper.h"


using namespace BlockStore;


struct BlockBase {
	
	std::variant<TextBlock, ImageBlock, ListBlock, PlaneBlock> block;
};


auto layout(layout_type<BlockBase>) { return declare(&BlockBase::block); }
auto layout(layout_type<TextBlock>) { return declare(&TextBlock::text); }
auto layout(layout_type<ImageBlock>) { return declare(&ImageBlock::id, &ImageBlock::caption); }
auto layout(layout_type<ListBlock>) { return declare(&ListBlock::caption, &ListBlock::child_list); }
auto layout(layout_type<PlaneBlock>) { return declare(&PlaneBlock::caption, &PlaneBlock::child_list); }
auto layout(layout_type<PlaneBlock::ChildInfo>) {
	using type = PlaneBlock::ChildInfo; return declare(&type::child, &type::point, &type::width);
}
auto layout(layout_type<Point>) { return declare(&Point::x, &Point::y); }