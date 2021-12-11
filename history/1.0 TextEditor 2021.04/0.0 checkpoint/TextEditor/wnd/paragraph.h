#pragma once

#include "../global_manager.h"
#include "../file/paragraph_format.h"

#include "WndDesign/wnd/TextBox.h"


BEGIN_NAMESPACE(TextEditor)


class Paragraph : public TextBox {
private:
	struct Style : public TextBox::Style { Style(); };
public:
	Paragraph();
	Paragraph(Engine& engine, ParagraphData data);
	~Paragraph();
private:
	ParagraphData data;
};


END_NAMESPACE(TextEditor)