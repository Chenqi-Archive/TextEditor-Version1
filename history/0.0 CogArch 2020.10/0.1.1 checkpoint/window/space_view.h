#pragma once

#include "block_view.h"


class SpaceView : public ScrollWnd {
private:
	MainFrame& _main_frame;
public:
	SpaceView(MainFrame& main_frame);


	///////////////////////////////////////////////////////////
	////                  Message Handling                 ////
	///////////////////////////////////////////////////////////
private:
	bool Handler(Msg msg, Para para);

private:
	enum class MouseDragType {None, Dragging, Selecting};
	Point _mouse_down_layer_position;



	////////////////////////////////////////////////////////////
	////                Child Block Managing                ////
	////////////////////////////////////////////////////////////
private:
	BlockView _description;
	list<BlockView> _child_blocks;

	vector<list<BlockView>::iterator> _selected_blocks;

public:
	void SelectMoreBlocks(Rect region);
	void SelectMoreBlocks(BlockView& block_view);
	void ClearSelection();

	void AddBlockAtFixedPosition(Point position, Block& block);
	void AddBlockAtRandomPosition(Block& block);  //
	void RemoveSelectedBlocks();
};