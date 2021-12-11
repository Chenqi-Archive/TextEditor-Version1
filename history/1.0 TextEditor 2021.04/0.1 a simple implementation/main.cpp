#include "WndDesign/WndDesign.h"
#include "WndDesign/wnd/EditBox.h"
#include "StaticStore/StaticStore.h"


using namespace WndDesign;
using namespace StaticStore;


#pragma comment(lib, "WndDesign.lib")
#pragma comment(lib, "StaticStore.lib")


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
	TextArea(Engine& engine) : 
		EditBox(std::make_unique<Style>()),
		engine(engine),
		meta_index(engine.GetMetadata<ArrayIndex>()) {
		Array<wchar> text_array(engine, meta_index);
		wstring text; text.resize(text_array.GetLength()); text_array.Load(text.data());
		SetText(std::move(text));
	}
	~TextArea() {
		Array<wchar> text_array(engine, meta_index);
		engine.Format();
		const wstring& text = GetText();
		text_array.Store(text.data(), text.length());
		engine.SetMetadata<ArrayIndex>(meta_index);
	}
private:
	Engine& engine;
	ArrayIndex meta_index;
};


int main() {
	auto engine = Engine::Create(L"test.te");
	TextArea text_area(*engine);
	desktop.AddChild(text_area);
	desktop.MessageLoop();
	return 0;
}