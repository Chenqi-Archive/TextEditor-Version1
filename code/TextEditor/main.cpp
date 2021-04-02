#include "WndDesign/WndDesign.h"
#include "WndDesign/wnd/EditBox.h"
#include "StaticStore/StaticStore.h"


using namespace WndDesign;
using namespace StaticStore;


#pragma comment(lib, "WndDesign.lib")
#pragma comment(lib, "StaticStore.lib")


struct TextAeraData {
	ArrayIndex<wchar> index;
};


class TextArea : public EditBox {
private:
	struct Style : EditBox::Style {
		Style() {
			width.normal(500px).max(100pct);
			height.normal(70pct).max(100pct);
			position.setHorizontalCenter().top(100px);
			border.width(3).color(ColorSet::Black).setResizer(CreateAeroSnapBorderResizer());
			padding.set(20px, 10px, 20px, 10px);
			background.setColor(ColorSet::White);
			paragraph.line_height(130pct).tab_size(200pct);
			font.family(L"µ»œﬂ").size(20);
		}
	};

public:
	TextArea() : EditBox(std::make_unique<Style>()) {}
	~TextArea() {}

public:
	void Load(Engine& engine, TextAeraData data) {
		Array<wchar> text_array(engine, data.index); 
		auto [text, length] = text_array.Load();
		SetText(wstring(text, length));
	}
	const TextAeraData Save(Engine& engine) {
		TextAeraData data;
		Array<wchar> text_array(engine, data.index);
		const wstring& text = GetText();
		text_array.Store(text.data(), text.length());
		return data;
	}
};


class GlobalManager {
private:
	static constexpr wchar file_name[] = L"test.te";
	TextArea text_area;
public:
	GlobalManager() { Load(); }
	~GlobalManager() { Save(); }
public:
	void Run() {
		desktop.AddChild(text_area);
		desktop.MessageLoop();
	}
private:
	void Load() {
		unique_ptr<Engine> engine = Engine::Create(file_name);
		TextAeraData data = engine->GetMetadata<TextAeraData>();
		text_area.Load(*engine, data);
	}
	void Save() {
		unique_ptr<Engine> engine = Engine::Create(file_name);
		engine->Format();
		TextAeraData data = text_area.Save(*engine);
		engine->SetMetadata<TextAeraData>(data);
	}
};


int main() {
	GlobalManager global_manager;
	global_manager.Run();
}