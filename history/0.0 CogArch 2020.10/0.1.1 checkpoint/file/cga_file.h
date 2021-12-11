#pragma once

#include "cga_format_0_0.h"

#include "../window/WndDesign.h"


namespace CGAFormat0_0 {


// May be able to determine file version later. (Use CommonHeader and CGAFormat0_0::Header)

class CGAFile : private File {
private:
	Header* _header;
	BlockTable* _block_table;
	ContentTable* _content_table;
	ReferenceTable* _reference_table;

private:
	Block* GetBlock(uint index) {
		if (index >= _block_table->block_number) { return nullptr; }
		return &reinterpret_cast<Block*>(&_block_table[1])[index];
	}
	const wchar_t* GetBlockContent(Block& block) {

	}


public:
	CGAFile(const wstring& file) :File() { Open(file); }
	~CGAFile() { Close(); }
	bool Open(const wstring& file);
	void Close();
	bool IsValid() const { return File::IsValid(); }
};


}  // namespace CGAFormat0_0