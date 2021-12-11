#include "main_frame.h"


#pragma comment(lib, "WndDesign.lib")
#pragma comment(lib, "StaticStore.lib")


class GlobalManager {
private:
	static constexpr wchar file_name[] = L"text.editor";

public:
	GlobalManager() { Load(); }
	~GlobalManager() { Save(); }

private:
	MainFrame main_frame;

public:
	void Run() {
		desktop.AddChild(main_frame);
		desktop.MessageLoop();
	}

private:
	void Load() {
		unique_ptr<Engine> engine = Engine::Create(file_name);
		TextAeraData data = engine->GetMetadata<TextAeraData>();
		main_frame.Load(*engine, data);
	}
	void Save() {
		unique_ptr<Engine> engine = Engine::Create(file_name);
		engine->Format();
		TextAeraData data = main_frame.Save(*engine);
		engine->SetMetadata<TextAeraData>(data);
	}
};


int main() {
	GlobalManager global_manager;
	global_manager.Run();
}