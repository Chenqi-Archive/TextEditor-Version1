#pragma once

#include "menu_bar.h"
#include "text_area.h"

#include "WndDesign/wnd/OverlapLayout.h"


class MainFrame : public OverlapLayout {
private:
	struct Style : OverlapLayout::Style { Style(); };

public:
	MainFrame() : OverlapLayout(std::make_unique<Style>()) {
		AddChild(menu_bar);
		AddChild(text_area);
	}
	~MainFrame() {}

private:
	MenuBar menu_bar;
	TextArea text_area;
};