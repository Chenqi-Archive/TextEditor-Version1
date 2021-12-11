#include "main_frame.h"


MainFrame::Style::Style(Rect region) {
	width.min(200px).max(100pct);
	height.min(200px).max(100pct);
	if (region.IsEmpty()) {
		width.normal(500px); height.normal(600px);
		position.setHorizontalCenter().setVerticalCenter();
	} else {
		width.normal(px(region.size.width)); height.normal(px(region.size.height));
		position.left(px(region.point.x)).top(px(region.point.y));
	}
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