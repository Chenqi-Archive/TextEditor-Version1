#pragma once

#include "StaticStore/StaticStore.h"


BEGIN_NAMESPACE(TextEditor)

using namespace StaticStore;


struct ParagraphListData {
	ArrayIndex paragraph_list_index;  // Array<ParagraphData>
};


struct ParagraphData {
	ArrayIndex text_string_index;  // Array<wchar>
};


END_NAMESPACE(TextEditor)