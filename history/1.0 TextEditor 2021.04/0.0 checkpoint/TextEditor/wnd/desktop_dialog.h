#pragma once

#include "../global_manager.h"

#include "WndDesign/wnd/TextBox.h"
#include "WndDesign/wnd/OverlapLayout.h"


BEGIN_NAMESPACE(TextEditor)


class SaveFileDialog : public OverlapLayout {
private:
	struct Style : public OverlapLayout::Style { Style(); };
public:
	SaveFileDialog() : OverlapLayout(std::make_unique<Style>()) {}
	~SaveFileDialog() {}
private:
	virtual void Handler(Msg msg, Para para) override {
		if (msg == Msg::LoseFocus) { desktop.RemoveChild(*this); }
	}
};


class OpenFileErrorDialog : public TextBox {
private:
	struct Style : public TextBox::Style { Style(); };
public:
	OpenFileErrorDialog() : TextBox(std::make_unique<Style>(), L"Open File Error") {}
	~OpenFileErrorDialog() {}
private:
	virtual void Handler(Msg msg, Para para) override {
		if (msg == Msg::LoseFocus) { desktop.RemoveChild(*this); }
	}
};


END_NAMESPACE(TextEditor)