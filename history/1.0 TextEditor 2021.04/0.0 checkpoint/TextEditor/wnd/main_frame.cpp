#include "main_frame.h"
#include "menu_bar.h"
#include "paragraph_list.h"
#include "status_bar.h"


BEGIN_NAMESPACE(TextEditor)


MainFrame::MainFrame() :
	OverlapLayout(std::make_unique<Style>()) {
	AddChild(menu_bar);
	AddChild(status_bar);
}

MainFrame::~MainFrame() {}

const wstring MainFrame::GetTitle() const {
	return GetGlobalManager().GetFileName() + L" - TextEditor"; 
}

ref_ptr<ParagraphList> MainFrame::CreateNewFile() {
	paragraph_list = std::make_unique<ParagraphList>();
	return paragraph_list.get();
}

ref_ptr<ParagraphList> MainFrame::LoadFile(Engine& engine) {
	paragraph_list = std::make_unique<ParagraphList>(engine);
	return paragraph_list.get();
}


END_NAMESPACE(TextEditor)