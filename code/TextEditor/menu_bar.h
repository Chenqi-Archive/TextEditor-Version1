#pragma once

#include "WndDesign/WndDesign.h"
#include "WndDesign/wnd/OverlapLayout.h"
#include "WndDesign/wnd/Button.h"
#include "WndDesign/system/win32_aero_snap.h"


using namespace WndDesign;


class CloseButton : public Button {
private:
	struct Style : Button::Style { Style(); };

public:
	CloseButton() : Button(std::make_unique<Style>()) {}
	~CloseButton() {}

private:
	virtual void OnClick() override {
		desktop.Terminate();
	}
	virtual void OnComposite(FigureQueue& figure_queue, Size display_size, Rect invalid_display_region) const override {
		figure_queue.Append(Point(15, 10), new Line(Vector(10, 10), ColorSet::White, 1.0));
		figure_queue.Append(Point(15, 20), new Line(Vector(10, -10), ColorSet::White, 1.0));
	}
};


class MenuBar : public OverlapLayout {
private:
	struct Style : OverlapLayout::Style { Style(); };

public:
	MenuBar() : OverlapLayout(std::make_unique<Style>()) {
		AddChild(close_button);
	}
	~MenuBar() {}

private:
	CloseButton close_button;

private:
	virtual void Handler(Msg msg, Para para) override {
		OverlapLayout::Handler(msg, para);
		if (msg == Msg::LeftDown) { AeroSnapDraggingEffect(*this, GetMouseMsg(para).point); }
	}
};