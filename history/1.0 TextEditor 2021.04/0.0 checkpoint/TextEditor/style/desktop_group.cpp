#include "../wnd/main_frame.h"
#include "../wnd/start_dialog.h"


BEGIN_NAMESPACE(TextEditor)

/*
Desktop
	MainFrame (OverlapLayout)
	StartDialog (OverlapLayout)
*/


MainFrame::Style::Style() {
	width.min(200px).normal(600px);
	height.min(200px).normal(650px);
	position.setHorizontalCenter().setVerticalCenter();
	border.color(ColorSet::Black).width(3).setResizer(CreateAeroSnapBorderResizer());
	background.setColor(ColorSet::White);
}


StartDialog::Style::Style() {
	width.setFixed(500px);
	height.setFixed(400px);
	position.setHorizontalCenter().setVerticalCenter();
	border.color(ColorSet::Black).width(3);
	background.setColor(ColorSet::White);
}


END_NAMESPACE(TextEditor)