#pragma once

#include "../global_manager.h"

#include "WndDesign/wnd/OverlapLayout.h"


BEGIN_NAMESPACE(TextEditor)


class StartDialog : public OverlapLayout {
private:
	struct Style : public OverlapLayout::Style { Style(); };
public:
	StartDialog();
	~StartDialog();
private:
	unique_ptr<WndObject> create_file_button;
	unique_ptr<WndObject> open_file_button;
	unique_ptr<WndObject> recent_file_list;
private:
	virtual void Handler(Msg msg, Para para) override {
		if (msg == Msg::LoseFocus) { desktop.RemoveChild(*this); }
	}
};


END_NAMESPACE(TextEditor)