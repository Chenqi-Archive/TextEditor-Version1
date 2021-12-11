#pragma once

#include "WndDesign/WndDesign.h"
#include "StaticStore/StaticStore.h"


BEGIN_NAMESPACE(TextEditor)

using namespace WndDesign;
using namespace StaticStore;

class MainFrame;
class ParagraphList;
class StartDialog;
class SaveFileDialog;
class OpenFileErrorDialog;


class GlobalManager {
private:
	GlobalManager();
	~GlobalManager();
public:
	static GlobalManager& GetGlobalManager();

	//// desktop window management ////
private:
	unique_ptr<MainFrame> main_frame;
	unique_ptr<StartDialog> start_dialog;
	unique_ptr<SaveFileDialog> save_file_dialog;
	unique_ptr<OpenFileErrorDialog> open_file_error_dialog;
public:
	void Run();
	void OpenSaveFileDialog();
	void CloseMainFrame();

	//// file management ////
private:
	wstring current_file_path;
	ref_ptr<ParagraphList> paragraph_list;
public:
	void CreateNewFile();
	void OpenFileDialog();
	void LoadFile(const wstring& file_path);
	void CloseCurrentFile();
	void SaveCurrentFile();
	const wstring GetFileName() const;
	bool IsFileModified() const;
};

inline GlobalManager& GetGlobalManager() { return GlobalManager::GetGlobalManager(); }


END_NAMESPACE(TextEditor)