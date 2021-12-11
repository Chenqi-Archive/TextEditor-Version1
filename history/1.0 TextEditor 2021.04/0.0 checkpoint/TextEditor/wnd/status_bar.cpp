#include "status_bar.h"


BEGIN_NAMESPACE(TextEditor)


StatusBar::StatusBar() : 
	OverlapLayout(std::make_unique<Style>()) {}

StatusBar::~StatusBar() {}


END_NAMESPACE(TextEditor)