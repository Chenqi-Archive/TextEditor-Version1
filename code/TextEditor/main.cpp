#include "main_frame.h"
#include "WndDesign/widget/MessageBox.h"


#pragma comment(lib, "WndDesign.lib")
#pragma comment(lib, "StaticStore.lib")


class GlobalManager {
private:
	static constexpr wchar file_name[] = L"text.editor";

public:
	GlobalManager() { 
		desktop.AddChild(main_frame);
		Load(); 
		desktop.MessageLoop();
	}
	~GlobalManager() { 
		Save(); 
	}

private:
	unique_ptr<Engine> engine;
	MainFrame main_frame;

private:
	void Load() {
		try {
			engine = Engine::Create(file_name);
		} catch (...) {
			GetMessageBox().Alert(L"Open File Error", []() { desktop.Terminate(); });
			return;
		}
		try {
			TextAeraData data = engine->GetMetadata<TextAeraData>();
			main_frame.Load(*engine, data);
		} catch (...) {
			engine->Format();
			TextAeraData data;
			main_frame.Load(*engine, data);  // index is invalid, so everything will be cleared
		}
	}
	void Save() {
		if (engine == nullptr) { return; }
		engine->Format();
		TextAeraData data = main_frame.Save(*engine);
		engine->SetMetadata<TextAeraData>(data);
	}
};


int main() {
	GlobalManager global_manager;
}