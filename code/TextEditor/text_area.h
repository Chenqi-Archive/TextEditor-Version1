#pragma once

#include "data_format.h"

#include "WndDesign/WndDesign.h"
#include "WndDesign/wnd/EditBox.h"
#include "WndDesign/widget/MessageBox.h"


using namespace WndDesign;


class TextArea : public EditBox {
private:
	struct Style : EditBox::Style { Style(); };

public:
	TextArea() : EditBox(std::make_unique<Style>()) {
		Load();
	}
	~TextArea() {
		Save();
	}

private:
	unique_ptr<Engine> engine;

public:
	void Load() {
		try {
			engine = Engine::Create(file_name);
		} catch (...) {
			GetMessageBox().Alert(L"Open File Error", []() { desktop.Terminate(); });
			return;
		}
		try {
			TextAeraData data = engine->GetMetadata<TextAeraData>();
			auto [text, length] = engine->LoadArray(data.index);
			SetText(wstring(text, length));
		} catch (...) {
			engine->Format();
		}
	}
	void Save() {
		if (engine == nullptr) { return; }
		engine->Format();
		TextAeraData data;
		const wstring& text = GetText();
		engine->SaveArray(data.index, text.data(), text.length());
		engine->SetMetadata<TextAeraData>(data);
	}
};