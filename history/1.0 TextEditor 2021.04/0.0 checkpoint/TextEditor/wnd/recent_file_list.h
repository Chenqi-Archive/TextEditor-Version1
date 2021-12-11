#pragma once

#include "WndDesign/wnd/ListLayout.h"

#include <vector>


BEGIN_NAMESPACE(TextEditor)

using WndDesign::ListLayout;

using std::unique_ptr;
using std::vector;

class RecentFile;


class RecentFileList : public ListLayout {
private:
	struct Style : public ListLayout::Style { Style(); };
public:
	RecentFileList() {}
	~RecentFileList() {}
private:
	vector<unique_ptr<RecentFile>> paragraph_list;
};


END_NAMESPACE(TextEditor)