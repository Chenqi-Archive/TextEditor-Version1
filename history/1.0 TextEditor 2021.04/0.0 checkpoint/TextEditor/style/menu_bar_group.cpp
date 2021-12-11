#include "../wnd/menu_bar_widget.h"


BEGIN_NAMESPACE(TextEditor)

/*
MenuBar (OverlapLayout)
	FileMenu (Button)
	EditMenu (Button)
	TitleBar (TextBox)
	MinimizeButton (Button)
	MaximizeButton (Button)
	CloseButton (Button)
*/


FileMenu::Style::Style() {
	width.setFixed(50px);
	height.setFixed(20px);
	position.top(5px).left(5px);
	background_hover.setColor(ColorSet::Gray);
	background_press.setColor(ColorSet::DimGray);
}


EditMenu::Style::Style() {
	width.setFixed(50px);
	height.setFixed(20px);
	position.top(5px).left(60px);
	background_hover.setColor(ColorSet::Gray);
	background_press.setColor(ColorSet::DimGray);
}


TitleBar::Style::Style() {
	height.setFixed(20px);
	position.setHorizontalCenter();
	font.size(18px);
}


MinimizeButton::Style::Style() {
	width.setFixed(50px);
	height.setFixed(20px);
	position.top(5px).right(115px);
	background_hover.setColor(ColorSet::Gray);
	background_press.setColor(ColorSet::DimGray);
}


MaximizeButton::Style::Style() {
	width.setFixed(50px);
	height.setFixed(20px);
	position.top(5px).right(60px);
	background_hover.setColor(ColorSet::Gray);
	background_press.setColor(ColorSet::DimGray);
}


CloseButton::Style::Style() {
	width.setFixed(50px);
	height.setFixed(20px);
	position.top(5px).right(5px);
	background_hover.setColor(ColorSet::LightCoral);
	background_press.setColor(ColorSet::Firebrick);
}


END_NAMESPACE(TextEditor)