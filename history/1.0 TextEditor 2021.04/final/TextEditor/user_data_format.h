#pragma once

#include "StaticStore/StaticStore.h"
#include "WndDesign/geometry/geometry.h"


using namespace StaticStore;
using WndDesign::Rect;


static constexpr wchar user_data_file_name[] = L"text.editor.user";


struct UserData {
	Rect main_frame_region;
};