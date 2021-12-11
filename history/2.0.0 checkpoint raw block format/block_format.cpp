#pragma once

#include "../common/core.h"

#include <vector>


enum class Type : uchar {
	Text,
	Image,
	Set,
	List,
	Plane,
};


constexpr uint max_text_length = 255;
constexpr uint max_caption_length = 63;
constexpr uint max_child_size = 31;


struct Header {
	bool has_prev;
	Type type;
	uchar child_size;
	uchar text_length;
	uint size() const;
};

uint Header::size() const {
	static_assert(sizeof(wchar) == 2);
	static_assert(sizeof(Header) == 4);
	uint size_header = 4;
	uint size_prev = 4 * (uint)has_prev;
	uint size_child = 4 * child_size;
	uint size_content;
	switch (type) {
	case Type::Text: size_content = 0; break;
	case Type::Image: size_content = 4; break;
	case Type::Set: size_content = 0; break;
	case Type::List: size_content = 0; break;
	case Type::Plane: size_content = child_size * 6; break;
	default: throw std::invalid_argument("invalid block type");
	}
	uint size_text = 2 * text_length;
	return size_header + size_prev + size_child + size_content + size_text;
}


using BlockId = uint;


template<class T>
using span = std::pair<T, uint>;


struct BlockData {
	const std::vector<char> data;
	Header header() const { return *reinterpret_cast<const Header*>(data.data()); }
	span<BlockId> child_list() const {}
};


struct BlockText {
	
};