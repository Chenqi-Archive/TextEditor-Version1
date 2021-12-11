#pragma once

#include "WndDesign/wnd/OverlapLayout.h"


BEGIN_NAMESPACE(TextEditor)

using WndDesign::OverlapLayout;
using std::unique_ptr;


class MenuBar : public OverlapLayout {
private:
	struct Style : public OverlapLayout::Style { Style(); };
public:
	MenuBar();
	~MenuBar();
private:
	unique_ptr<WndObject> file_menu;
	unique_ptr<WndObject> edit_menu;
	unique_ptr<WndObject> title_bar;
	unique_ptr<WndObject> minimize_button;
	unique_ptr<WndObject> maximize_button;
	unique_ptr<WndObject> close_button;
};


END_NAMESPACE(TextEditor)