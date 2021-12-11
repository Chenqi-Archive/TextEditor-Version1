#pragma once

#include "StaticStore/StaticStore.h"


BEGIN_NAMESPACE(TextEditor)

using namespace StaticStore;


struct RecentFileListData {
	ArrayIndex recent_file_list_index;  // Array<ParagraphData>
};


struct RecentFileData {
	ArrayIndex file_path;  // Array<wchar>
};


END_NAMESPACE(TextEditor)