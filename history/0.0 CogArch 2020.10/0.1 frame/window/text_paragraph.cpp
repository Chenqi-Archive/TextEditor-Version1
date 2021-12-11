#include "text_paragraph.h"
#include "text_block.h"

inline TextParagraph::Style::Style() {
	auto_resize.width_auto_resize().height_auto_resize();
	position.left(0px).top(0px);
	border.width(0px);
	background.setColor(color_transparent);
	padding.left(5px).right(5px);
	paragraph.word_wrap(WordWrap::Character);
	font.family(L"µ»œﬂ").size(20px).color(ColorSet::Black);
}

TextParagraph::TextParagraph(TextBlock& block) : TextBox(block, Style()), _block(block){

}

bool TextParagraph::Handler(Msg msg, Para para) {
	return false;
}
