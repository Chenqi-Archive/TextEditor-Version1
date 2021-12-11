#include "paragraph.h"


BEGIN_NAMESPACE(TextEditor)


Paragraph::Paragraph() : TextBox(std::make_unique<Style>(), L"") {}

Paragraph::Paragraph(Engine& engine, ParagraphData data) : TextBox(std::make_unique<Style>(), L""), data(data) {
	Array<wchar> text_array(engine, data.text_string_index);
	wstring text(text_array.GetLength(), L'\0');
	text_array.Load(text.data());
	SetText(std::move(text));
}

Paragraph::~Paragraph() {}


END_NAMESPACE(TextEditor)