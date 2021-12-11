#pragma once

using uint = unsigned int;


namespace CGAFormat0_0 {

struct Header {
	uint signature;		// "CGAF"
	short version_low;  // 0
	short version_high; // 0
	uint file_size;

	uint block_table_offset;
	uint content_table_offset;
	uint reference_table_offset;
};

struct BlockTable {
	uint size;         // size = sizeof(BlockTable) + sizeof(Block) * block_number.
	uint block_number;
	// Block* blocks;
};

struct Block {
	uint content_offset;   // index of content table (wchar_t, 64-byte-stride, 0 terminated)
	uint parents_offset;   // index of reference table (uint, 16-byte-stride, -1 terminated)
	uint childs_offset;
};

struct ContentTable {
	uint size;       	   // size = sizeof(uint) + contents_size;
	// wchar_t* contents;
};

struct ReferenceTable {
	uint size;			   // size = sizeof(uint) + references_size;
	// uint* references_index;
#error position information
};


}  // namespace CGAFormat0_0