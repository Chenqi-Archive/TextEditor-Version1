#pragma once

#include "WndDesign.h"


class MainFrame;

class MenuBar : public Wnd {
private:
	class Title : public TextBox {
	public:
		Title(MenuBar& menu_bar);
	};

	class CloseButton : public Button {
		MainFrame& _main_frame;
	public:
		CloseButton(MenuBar& menu_bar);
		void OnClick() override;
		void AppendFigure(FigureQueue& figure_queue) override; // For drawing "x"
	};

private:
	MainFrame& _main_frame;
	Title _title;
	CloseButton _close_button;

public:
	MenuBar(MainFrame& main_frame, const wstring& title);
	void SetTitle(const wstring& title) { _title->SetText(title); }

private:
	bool Handler(Msg msg, Para para);
};
