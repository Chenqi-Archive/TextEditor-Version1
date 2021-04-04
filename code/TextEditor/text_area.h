#pragma once

#include "data_format.h"

#include "WndDesign/wnd/EditBox.h"


using namespace WndDesign;


class TextArea : public EditBox {
private:
	struct Style : EditBox::Style { Style(); };

public:
	TextArea() : EditBox(std::make_unique<Style>()) {}
	~TextArea() {}

public:
	void Load(Engine& engine, TextAeraData data) {
		auto [text, length] = Array<wchar>(engine, data.index).Load();
		SetText(wstring(text, length));
	}
	const TextAeraData Save(Engine& engine) {
		TextAeraData data;
		const wstring& text = GetText();
		Array<wchar>(engine, data.index).Save(text.data(), text.length());
		return data;
	}
};