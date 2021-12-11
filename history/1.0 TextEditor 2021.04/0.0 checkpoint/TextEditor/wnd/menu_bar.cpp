#include "menu_bar.h"
#include "menu_bar_widget.h"


BEGIN_NAMESPACE(TextEditor)

using std::make_unique;


MenuBar::MenuBar() : 
	OverlapLayout(make_unique<Style>()),
	file_menu(make_unique<FileMenu>()),
	edit_menu(make_unique<EditMenu>()),
	title_bar(make_unique<TitleBar>()),
	minimize_button(make_unique<MinimizeButton>()),
	maximize_button(make_unique<MaximizeButton>()),
	close_button(make_unique<CloseButton>())
{
	AddChild(*file_menu);
	AddChild(*edit_menu);
	AddChild(*title_bar);
	AddChild(*minimize_button);
	AddChild(*maximize_button);
	AddChild(*close_button);
}

MenuBar::~MenuBar() {}


END_NAMESPACE(TextEditor)