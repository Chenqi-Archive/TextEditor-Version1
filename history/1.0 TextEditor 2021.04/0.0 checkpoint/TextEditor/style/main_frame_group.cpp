#include "../wnd/menu_bar.h"
#include "../wnd/paragraph_list.h"
#include "../wnd/paragraph.h"
#include "../wnd/status_bar.h"


BEGIN_NAMESPACE(TextEditor)

/*
MainFrame (OverlapLayout)
	MenuBar (OverlapLayout)
	ParagraphList (ListLayout)
		Paragraph
	StatusBar (OverlapLayout)
*/


MenuBar::Style::Style() {
	width.setFixed(100pct);
	height.setFixed(30px);
	position.left(0px).top(0px);
	background.setColor(ColorSet::MediumOrchid);
}


ParagraphList::Style::Style() {
	width.setFixed(100pct);
	position.left(0px).top(30px).bottom(25px);
	padding.set(20px, 10px, 20px, 10px);
	client.height(length_auto);
	gridline.width(0);
}


Paragraph::Style::Style() {
	width.setFixed(100pct);
	height.setFixed(100pct);
	client.height(length_auto);
}


StatusBar::Style::Style() {
	width.setFixed(100pct);
	height.setFixed(25px);
	position.left(0px).bottom(0px);
}


END_NAMESPACE(TextEditor)