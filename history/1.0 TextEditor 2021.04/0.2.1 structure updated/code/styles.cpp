#include "main_frame.h"


MainFrame::Style::Style() {
	width.min(200px).normal(500px).max(100pct);
	height.min(200px).normal(600px).max(100pct);
	position.setHorizontalCenter().setVerticalCenter();
	border.width(3).color(color_transparent).setResizer(CreateAeroSnapBorderResizer());
	background.setColor(ColorSet::Indigo);
}

MenuBar::Style::Style() {
	width.setFixed(100pct);
	height.setFixed(30px);
	position.left(0px).top(0px);
	background.setColor(ColorSet::MediumPurple);
}

CloseButton::Style::Style() {
	width.setFixed(40px);
	height.setFixed(30px);
	position.top(0px).right(0px);
	background.setColor(color_transparent);
	background_hover.setColor(Color(ColorSet::DarkGray, 0x7F));
	background_press.setColor(Color(ColorSet::Gray, 0x7F));
}

TextArea::Style::Style() {
	width.setFixed(100pct); 
	position.left(0px).top(30px).bottom(0px);
	padding.set(20px, 10px, 20px, 10px);
	background.setColor(ColorSet::White);
	font.family(L"µ»œﬂ").size(20);
}