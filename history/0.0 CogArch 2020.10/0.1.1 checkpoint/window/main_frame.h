#pragma once

#include "menu_bar.h"
#include "space_view.h"

#include <memory>

using std::unique_ptr;


class MainFrame : public Wnd {
public:
	MainFrame();
	bool Handler(Msg msg, Para para);

private:
	MenuBar _menu_bar;

	SystemWindowBorderResizer _border_resizer;


	////////////////////////////////////////////////////////////
	////                   View Switching                   ////
	////////////////////////////////////////////////////////////
private:
	unique_ptr<SpaceView> _space_view;

public:
	void SwitchSpaceView(Block& block);
};