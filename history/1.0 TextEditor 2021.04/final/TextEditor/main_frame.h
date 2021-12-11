#pragma once

#include "menu_bar.h"
#include "text_area.h"

#include "user_data_format.h"

#include "WndDesign/wnd/OverlapLayout.h"


class MainFrame : public OverlapLayout {
private:
	struct Style : OverlapLayout::Style { Style(Rect region); };

public:
	MainFrame() : OverlapLayout(std::make_unique<Style>(GetUserDataRegion())) {
		AddChild(menu_bar);
		AddChild(text_area);
	}
	~MainFrame() {
		SaveUserData();
	}

private:
	MenuBar menu_bar;
	TextArea text_area;

private:
	const Rect GetUserDataRegion() {
		unique_ptr<Engine> engine;
		UserData user_data;
		try {
			engine = Engine::Create(user_data_file_name);
		} catch (...) {
			return user_data.main_frame_region;
		}
		try {
			user_data = engine->GetMetadata<UserData>();
		} catch (...) {}
		return user_data.main_frame_region;
	}

	void SaveUserData() {
		unique_ptr<Engine> engine;
		try {
			engine = Engine::Create(user_data_file_name);
		} catch (...) {
			return;
		}
		engine->Format();
		UserData user_data; user_data.main_frame_region = GetRegionOnParent();
		engine->SetMetadata<UserData>(user_data);
	}
};