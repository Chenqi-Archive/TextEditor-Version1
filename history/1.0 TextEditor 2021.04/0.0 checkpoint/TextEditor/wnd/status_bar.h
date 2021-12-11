#pragma once

#include "WndDesign/wnd/OverlapLayout.h"


BEGIN_NAMESPACE(TextEditor)

using WndDesign::OverlapLayout;


class StatusBar : public OverlapLayout {
private:
	struct Style : public OverlapLayout::Style { Style(); };
public:
	StatusBar();
	~StatusBar();
};


END_NAMESPACE(TextEditor)