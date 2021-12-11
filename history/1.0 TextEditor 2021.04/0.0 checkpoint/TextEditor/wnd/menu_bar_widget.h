#pragma once

#include "WndDesign/wnd/Button.h"
#include "WndDesign/wnd/TextBox.h"


BEGIN_NAMESPACE(TextEditor)

using namespace WndDesign;


class FileMenu : public Button {
private:
	struct Style : public Button::Style { Style(); };
public:
	FileMenu() : Button(std::make_unique<Style>(), L"File") {}
	~FileMenu() {}
private:
	virtual void OnClick() override {
		Button::OnClick();

		// Show File Menu List

	}
};


class EditMenu : public Button {
private:
	struct Style : public Button::Style { Style(); };
public:
	EditMenu() : Button(std::make_unique<Style>(), L"Edit") {}
	~EditMenu() {}
private:
	virtual void OnClick() override {
		Button::OnClick();
	}
};


class TitleBar : public TextBox {
private:
	struct Style : public TextBox::Style { Style(); };
public:
	TitleBar() : TextBox(std::make_unique<Style>(), L"Untitled") {}
	~TitleBar() {}
private:
	virtual bool NonClientHitTest(Size display_size, Point point) const override { return false; }
};


class MinimizeButton : public Button {
private:
	struct Style : public Button::Style { Style(); };
public:
	MinimizeButton() : Button(std::make_unique<Style>()) {}
	~MinimizeButton() {}
private:
	virtual void OnClick() override {
		Button::OnClick();
	}
	virtual void OnComposite(FigureQueue& figure_queue, Size display_size, Rect invalid_display_region) const override {
		figure_queue.Append(Rect(point_zero, display_size).Center() - Vector(5, 0), new Line(Vector(10, 0), ColorSet::White, 1.0));
		Button::OnComposite(figure_queue, display_size, invalid_display_region);
	}
};


class MaximizeButton : public Button {
private:
	struct Style : public Button::Style { Style(); };
public:
	MaximizeButton() : Button(std::make_unique<Style>()) {}
	~MaximizeButton() {}
private:
	virtual void OnClick() override {
		Button::OnClick();
	}
	virtual void OnComposite(FigureQueue& figure_queue, Size display_size, Rect invalid_display_region) const override {
		figure_queue.Append(Rect(point_zero, display_size).Center() - Vector(5, 5), new Line(Vector(10, 0), ColorSet::White, 1.0));
		Button::OnComposite(figure_queue, display_size, invalid_display_region);
	}
};

class CloseButton : public Button {
private:
	struct Style : public Button::Style { Style(); };
public:
	CloseButton() : Button(std::make_unique<Style>()) {}
	~CloseButton() {}
private:
	virtual void OnClick() override {
		Button::OnClick();
	}
};


END_NAMESPACE(TextEditor)