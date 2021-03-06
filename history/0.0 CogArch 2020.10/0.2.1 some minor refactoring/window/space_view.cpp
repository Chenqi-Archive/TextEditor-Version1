#include "space_view.h"
#include "main_frame.h"
#include "helper.h"

#include <random>


inline Point ChoosePointInRectAtRandom(Rect region) {
	std::random_device rd; // obtain a random number from hardware
	std::mt19937 gen(rd()); // seed the generator
	std::uniform_int_distribution<> 
		x_distr(region.point.x, region.point.x + static_cast<int>(region.size.width)),
		y_distr(region.point.y, region.point.y + static_cast<int>(region.size.height)); // define the range
	return Point(x_distr(gen), y_distr(gen));
}


inline vector<Block*> GetCommonParentBlocks(const vector<Block*>& blocks) {
	if (blocks.size() <= 1) { throw; }
	vector<Block*> parent_blocks;
	// Set initial count to all parents of the first block.
	uint initial_count = static_cast<uint>(blocks.size() - 1);
	for (auto& parent : blocks[0]->ParentBlocks()) {
		parent.parent->_block_index = initial_count;
	}
	// For other blocks, decrease all count of parents by one.
	for (uint i = initial_count; i > 0; --i) {
		for (auto& parent : blocks[i]->ParentBlocks()) {
			parent.parent->_block_index--;
		}
	}
	// Check the first block again, if the parent count becomes 0, add the parent to result.
	for (auto& parent : blocks[0]->ParentBlocks()) {
		if (parent.parent->_block_index == 0) {
			parent_blocks.push_back(parent);
		}
	}
	return parent_blocks;
}


struct SpaceViewStyle : public ScrollWndStyle {
	SpaceViewStyle() {
		size.setFixed(100pct, 100pct);
		position.left(0px).top(0px);
		background.setColor(ColorSet::AliceBlue);
		entire_region = region_infinite_tag;
	}
};


SpaceView::SpaceView(MainFrame& main_frame, const vector<Block*>& blocks, bool is_parent_view) :
	ScrollWnd(nullwnd, SpaceViewStyle()),
	_is_parent_view(is_parent_view),
	_current_blocks(blocks),
	_main_frame(main_frame),
	_space_description(*this, blocks),
	_caret(*this),
	_selection(*this),
	_scroller(*this) {

	if (is_parent_view == false) {
		// Load child blocks.
		if (blocks.size() != 1) { throw; }
		for (auto it : blocks[0]->ChildBlocks()) {
			AddBlock(*it.child, it.child_position, it.child_width, false);
		}
	} else {
		// Load parent blocks.
		if (blocks.size() == 0) { throw; }
		if (blocks.size() == 1) {
			for (auto& it : blocks[0]->ParentBlocks()) {
				AddBlock(*it.parent, child_position_auto, child_width_auto, false);
			}
		} else {
			for (auto it : GetCommonParentBlocks(blocks)) {
				AddBlock(*it, child_position_auto, child_width_auto, false);
			}
		}
	}

	// Attach to main frame.
	main_frame->AddChild(GetWnd());
}

BlockView& SpaceView::AddBlock(Block& block, Point position, uint width, bool create_relation) {
	if (create_relation) {
		if (_is_parent_view) {
			for (auto it_child : _current_blocks) {
				_main_frame._block_manager.CreateInheritanceRelation(block, *it_child, position, width);
			}
		} else {
			if (_current_blocks.size() != 1) { throw; }
			_main_frame._block_manager.CreateInheritanceRelation(*_current_blocks[0], block, position, width);
		}
	}

	if (position == child_position_auto) {
		position = ChoosePointInRectAtRandom(Rect(100, 100, 600, 300));

		// May calculate the position later.

	}
	auto& new_block = _child_blocks.emplace_front(*this, block, position, width);
	new_block._iterator = _child_blocks.begin();
	return new_block;
}

void SpaceView::RemoveBlock(BlockView& block) {
	if (_is_parent_view) {
		for (auto it_child : _current_blocks) {
			_main_frame._block_manager.DestroyInheritanceRelation(block._block, *it_child);
		}
	} else {
		if (_current_blocks.size() != 1) { throw; }
		_main_frame._block_manager.DestroyInheritanceRelation(*_current_blocks[0], block._block);
	}
	_child_blocks.erase(block._iterator);
}

void SpaceView::RemoveSelectedBlocks() {
	if (_is_parent_view) {
		for (auto& it_parent: _selected_blocks) {
			for (auto it_child : _current_blocks) {
				_main_frame._block_manager.DestroyInheritanceRelation(it_parent->_block, *it_child);
			}
			_child_blocks.erase(it_parent->_iterator);
		}
	} else {
		if (_current_blocks.size() != 1) { throw; }
		for (auto& it_child : _selected_blocks) {
			_main_frame._block_manager.DestroyInheritanceRelation(*_current_blocks[0], it_child->_block);
			_child_blocks.erase(it_child->_iterator);
		}
	}
	_selected_blocks.clear();
}

void SpaceView::EnterMyParentView() {
	if (!_is_parent_view) {
		if (_current_blocks.size() != 1) { throw; }
		_main_frame.EnterParentView({ _current_blocks[0] });
	}
}

void SpaceView::EnterChildView(Block& block) {
	_main_frame.EnterChildView(&block);
}

void SpaceView::EnterParentView(Block& block) {
	_main_frame.EnterParentView({ &block });
}

void SpaceView::EnterSelectedBlocksParentView() {
	vector<Block*> blocks; blocks.reserve(_selected_blocks.size());
	for (auto it : _selected_blocks) { blocks.push_back(&it->_block); }
	_main_frame.EnterParentView(blocks);
}

bool SpaceView::Handler(Msg msg, Para para) {
	if (IsMouseMsg(msg)) {
		auto& mouse_msg = GetMouseMsg(para);
		auto& position = mouse_msg.point;
		if (msg == Msg::LeftDown) {
			(*this)->SetFocus();
			if (mouse_msg.ctrl) {
				_selection.OnLeftDown(position);
			} else {
				UndoSelection();
				_scroller.OnLeftDown(position);
			}
		} else if(msg == Msg::MouseMove){
			_selection.OnMouseMove(position);
			if (!_scroller.OnMouseMove(position)) {  // Or the cursor has set to be Cursor::Move.
				SetCursor(Cursor::Text);
			}
		} else if (msg == Msg::LeftUp) {
			if (Rect selection = _selection.OnLeftUp(position); !selection.IsEmpty()) {
				SelectMoreBlocks(selection);
			}
			_scroller.OnLeftUp();
		} else if (msg == Msg::MouseWheel) {
			if (GetMouseMsg(para).wheel_delta < 0) {
				if (_selected_blocks.empty()) {
					EnterMyParentView();
				} else {
					EnterSelectedBlocksParentView();
				}
			}
		}
	} else if (IsKeyboardMsg(msg)) {
		if (msg == Msg::KeyDown) {
			switch (GetKeyMsg(para).key) {
			// Convert the control key messages to char messages.
			case Key::Enter: msg = Msg::Char; para = reinterpret_cast<Para>(L'\n'); break;
			case Key::Tab: msg = Msg::Char; para = reinterpret_cast<Para>(L'\t'); break;
			case Key::Backspace:  // fall through
			case Key::Delete: RemoveSelectedBlocks(); break;
			default: break;
			}
		}

		// When receives character/string/IME message, create a new Block at current caret position,
		//   hide the caret, and resend the message to the newly created Block.
		if (_caret.IsActive() && ((msg == Msg::Char && GetCharMsg(para) != 0) || msg == Msg::ImeStartComposition)) {
			// Create a new block.
			auto& block = _main_frame._block_manager.CreateBlock();
			auto& new_block = AddBlock(block, _caret.GetPosition(), child_width_auto, true);
			// Set focus so that all subsequent keyboard messages will be sent to the block.
			// And myself will receive Msg::LoseFocus at the same time, when the temporary caret will be hidden.
			new_block->SetFocus();
			// Resend the message to the block.
			new_block.Handler(msg, para);
		}
	} else if (msg == Msg::LoseFocus) {
		UndoSelection();
	}

	_caret.TrackMsg(msg, para);
	return true;
}

void SpaceView::AppendFigure(FigureQueue& figure_queue, Rect region_to_update) {
	_caret.AppendFigure(figure_queue);
	_selection.AppendFigure(figure_queue);
	_scroller.AppendFigure(figure_queue);
}
