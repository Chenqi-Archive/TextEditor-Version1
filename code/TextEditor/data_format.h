#pragma once

#include "StaticStore/StaticStore.h"


using namespace StaticStore;


static constexpr wchar file_name[] = L"text.editor";


struct TextAeraData {
	ArrayIndex<wchar> index;
};