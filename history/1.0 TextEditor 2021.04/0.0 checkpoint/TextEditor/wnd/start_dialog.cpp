#include "start_dialog.h"
#include "start_dialog_widget.h"
#include "recent_file_list.h"


BEGIN_NAMESPACE(TextEditor)

using std::make_unique;


StartDialog::StartDialog() :
	OverlapLayout(make_unique<Style>()),
	create_file_button(make_unique<CreateFileButton>()),
	open_file_button(make_unique<OpenFileButton>()),
	recent_file_list(make_unique<RecentFileList>()) {
	AddChild(*create_file_button);
	AddChild(*open_file_button);
	AddChild(*recent_file_list);
}

StartDialog::~StartDialog() {}


END_NAMESPACE(TextEditor)