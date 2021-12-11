#include "global_manager.h"
#include "wnd/main_frame.h"
#include "wnd/paragraph_list.h"
#include "wnd/start_dialog.h"
#include "wnd/desktop_dialog.h"


BEGIN_NAMESPACE(TextEditor)


GlobalManager& GlobalManager::GetGlobalManager() {
	GlobalManager global_manager;
	return global_manager;
}


GlobalManager::GlobalManager() :
	main_frame(std::make_unique<MainFrame>()),
	start_dialog(std::make_unique<StartDialog>()),
	save_file_dialog(std::make_unique<SaveFileDialog>()),
	open_file_error_dialog(std::make_unique<OpenFileErrorDialog>()),

	current_file_path(),
	paragraph_list(nullptr) {
}


GlobalManager::~GlobalManager() {}


void GlobalManager::Run() {
	desktop.AddChild(*main_frame);
	desktop.AddChild(*start_dialog);
	start_dialog->SetFocus();
}

void GlobalManager::OpenSaveFileDialog() {
	desktop.AddChild(*save_file_dialog);
	save_file_dialog->SetFocus();
}

void GlobalManager::CloseMainFrame() {
	if (IsFileModified()) {
		OpenSaveFileDialog();
		return;
	}
	desktop.Terminate();
}

void GlobalManager::CreateNewFile() {
	CloseCurrentFile();
	paragraph_list = main_frame->CreateNewFile();
	desktop.RemoveChild(*start_dialog);
}

void GlobalManager::OpenFileDialog() {

}

void GlobalManager::LoadFile(const wstring& file_path) {
	CloseCurrentFile(); // 
	unique_ptr<Engine> paragraph_engine;
	try {
		paragraph_engine = Engine::Create(file_path.c_str());
	} catch (...) {
		current_file_path = L"";
		desktop.AddChild(*open_file_error_dialog);
		return;
	}
	assert(paragraph_engine != nullptr);
	paragraph_list = main_frame->LoadFile(*paragraph_engine);
}

void GlobalManager::CloseCurrentFile() {

}

void GlobalManager::SaveCurrentFile() {
	if (current_file_path.empty()) {

	}
	auto paragraph_engine = Engine::Create(current_file_path.c_str());

}

const wstring GlobalManager::GetFileName() const {
	size_t index = current_file_path.find_last_of(L"/\\");
	if (index == size_t(-1)) { index = 0; }
	wstring ret = current_file_path.substr(index);
	if (ret.empty()) { return L"Untitled"; }
	return ret;
}

bool GlobalManager::IsFileModified() const {
	if (paragraph_list == nullptr) { return false; }
	return paragraph_list->IsFileModified();
}


END_NAMESPACE(TextEditor)