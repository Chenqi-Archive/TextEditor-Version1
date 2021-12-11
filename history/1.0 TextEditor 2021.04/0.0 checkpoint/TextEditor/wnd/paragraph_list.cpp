#include "paragraph_list.h"
#include "paragraph.h"


BEGIN_NAMESPACE(TextEditor)


ParagraphList::ParagraphList() : ListLayout(std::make_unique<Style>()) {}

ParagraphList::ParagraphList(Engine& engine, ParagraphListData data) : ListLayout(std::make_unique<Style>()), data(data) {
	Array<ParagraphData> paragraph_array(engine, data.paragraph_list_index);
	vector<ParagraphData> tmp_buffer; tmp_buffer.resize(paragraph_array.GetLength());
	paragraph_array.Load(tmp_buffer.data());
	for (auto& data : tmp_buffer) {
		paragraph_list.push_back(std::make_unique<Paragraph>(engine, data));
		AppendChild(*paragraph_list.back());
	}
}

ParagraphList::~ParagraphList() {}


END_NAMESPACE(TextEditor)