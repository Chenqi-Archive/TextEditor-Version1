#pragma once

#include "../global_manager.h"

#include "menu_bar.h"
#include "status_bar.h"

#include "WndDesign/wnd/OverlapLayout.h"


BEGIN_NAMESPACE(TextEditor)

class ParagraphList;


class MainFrame : public OverlapLayout {
private:
	struct Style : public OverlapLayout::Style { Style(); };
public:
	MainFrame();
	~MainFrame();
private:
	MenuBar menu_bar;
	StatusBar status_bar;
private:
	virtual const wstring GetTitle() const override;

	//// paragraph list management ////
private:
	unique_ptr<ParagraphList> paragraph_list;
public:
	ref_ptr<ParagraphList> CreateNewFile();
	ref_ptr<ParagraphList> LoadFile(Engine& engine);
};


END_NAMESPACE(TextEditor)