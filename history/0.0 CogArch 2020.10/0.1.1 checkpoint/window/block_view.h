#pragma once

#include "WndDesign.h"

#include "../block/block.h"

#include <list>

using std::list;


class SpaceView;


class BlockView : public EditBox {
private:
	friend class SpaceView;
	SpaceView& _space;

	list<BlockView>::iterator _iterator;
	bool _is_selected;

private:
	Block& _block;
	
public:
	BlockView(SpaceView& space, Point position, Block& block);

private:
	bool Handler(Msg msg, Para para);
	void AppendFigure(FigureQueue& figure_queue) override;	// For drawing moving bar and mask.
};