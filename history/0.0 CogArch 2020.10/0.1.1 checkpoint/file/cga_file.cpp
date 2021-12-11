#include "cga_file.h"


namespace CGAFormat0_0 {


bool CGAFile::Open(const wstring& file) {
	do {
		if (!File::Open(file)) { break; }

		ulonglong size = GetSize();

		// If size is 0, create a new file.


		char* address = reinterpret_cast<char*>(GetAddress());

		uint offset = 0;
		if (size < offset + sizeof(Header)) { break; }
		_header = reinterpret_cast<Header*>(address + offset);
		if (_header->signature != *(reinterpret_cast<uint*>("CGAF"))) { break; }
		if (_header->version_low != 0 || _header->version_high != 0) { break; }
		if (_header->file_size != static_cast<uint>(size)) { break; }

		offset = _header->block_table_offset;
		if (size < offset + sizeof(BlockTable)) { break; }
		_block_table = reinterpret_cast<BlockTable*>(address + offset);
		if (_block_table->size != sizeof(BlockTable) + _block_table->block_number * sizeof(Block)) { break; }
		if (size < offset + _block_table->size) { break; }

		offset = _header->content_table_offset;
		if (size < offset + sizeof(ContentTable)) { break; }
		_content_table = reinterpret_cast<ContentTable*>(address + offset);
		if (size < offset + _content_table->size) { break; }

		offset = _header->reference_table_offset;
		if (size < offset + sizeof(ReferenceTable)) { break; }
		_reference_table = reinterpret_cast<ReferenceTable*>(address + offset);
		if (size < offset + _reference_table->size) { break; }

		return true;

	} while (0);

Error:
	Close();
	return false;
}


void CGAFile::Close() {
	_header = nullptr;
	_block_table = nullptr;
	_content_table = nullptr;
	_reference_table = nullptr;
	File::Close();
}


}  // namespace CGAFormat0_0