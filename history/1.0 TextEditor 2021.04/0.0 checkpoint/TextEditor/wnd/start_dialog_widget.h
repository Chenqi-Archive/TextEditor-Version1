#pragma once

#include "../global_manager.h"
#include "../file/user_data_format.h"

#include "WndDesign/wnd/Button.h"
#include "WndDesign/wnd/ListLayout.h"
#include "WndDesign/wnd/OverlapLayout.h"


BEGIN_NAMESPACE(TextEditor)


class CreateFileButton : public Button {
private:
	struct Style : public Button::Style { Style(); };
public:
	CreateFileButton() : Button(std::make_unique<Style>()) {}
	~CreateFileButton() {}
private:
	virtual void OnClick() override {
		Button::OnClick();
		GetGlobalManager().CreateNewFile();
	}
};


class OpenFileButton : public Button {
private:
	struct Style : public Button::Style { Style(); };
public:
	OpenFileButton() : Button(std::make_unique<Style>()) {}
	~OpenFileButton() {}
private:
	virtual void OnClick() override {
		Button::OnClick();
		GetGlobalManager().OpenFileDialog();
	}
};


class RecentFileEntry;

class RecentFileList : public ListLayout {
private:
	struct Style : public ListLayout::Style { Style(); };
public:
	RecentFileList() : ListLayout(std::make_unique<Style>()) {}
	~RecentFileList() {}
private:
	RecentFileListData data;
	vector<unique_ptr<RecentFileEntry>> recent_file_list;

	/* should remove duplicate files, and sort by last use date */
};


class RecentFileEntry : public OverlapLayout {
private:
	struct Style : public OverlapLayout::Style { Style(); };
public:
	RecentFileEntry() : OverlapLayout(std::make_unique<Style>()) {}
	~RecentFileEntry() {}
private:
	RecentFileData data;
private:
	TextBox file_name;
	TextBox file_directory;
public:
	const wstring GetFilePath() {
		return file_directory.GetText() + L"/" + file_name.GetText();
	}
private:
	virtual void OnClick() override {
		GetGlobalManager().LoadFile(GetFilePath());
	}
};


END_NAMESPACE(TextEditor)