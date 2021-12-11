#pragma once

#include "WndDesign.h"

#include <list>

using std::list;


class TextBlock;  // The text block that holds all text paragraphs.


// A text paragraph of a block.
class TextParagraph : public TextBox {
	struct Style : public TextBoxStyle { Style(); };

private:
	TextBlock& _block;  // The parent text block;
	list<TextParagraph>::iterator _id; // The position in the paragraph list.

public:
	TextParagraph(TextBlock& block);
	bool Handler(Msg msg, Para para) override;
};

