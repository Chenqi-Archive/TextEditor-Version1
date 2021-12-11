#pragma once

#include "../global_manager.h"
#include "../file/paragraph_format.h"

#include "WndDesign/wnd/ListLayout.h"

#include <vector>


BEGIN_NAMESPACE(TextEditor)

using std::vector;

class Paragraph;


class ParagraphList : public ListLayout {
private:
	struct Style : public ListLayout::Style { Style(); };

public:
	ParagraphList();
	ParagraphList(Engine& engine, ParagraphListData data);
	~ParagraphList();

private:
	ParagraphListData data;
	vector<unique_ptr<Paragraph>> paragraph_list;

public:
	bool IsFileModified() const { return false; }
};


END_NAMESPACE(TextEditor)