#pragma once

#include <d2d1.h>  
#include <d2d1helper.h>  
#include <dwrite.h>  

#pragma comment(lib, "dwrite.lib")  
#pragma comment(lib, "d2d1.lib")

static ID2D1Factory* g_factory;
static ID2D1HwndRenderTarget* g_render_target;


void OnPaint() {
	g_factory->CreateHwndRenderTarget()
}



LRESULT CALLBACK TextBoxProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {
	switch (msg) {
		case WM_PAINT: OnPaint(); break;
		default:
			return DefWindowProc(hWnd, msg, wParam, lParam);
	}
	return 0;

}

void CreateTextBox(HWND hWnd, int x, int y) {
	static bool classRegistered = false;

	const wchar_t className[] = L"CogArchTextBoxClass";
	const wchar_t titleName[] = L"TextBox";

	if (!classRegistered) {
		WNDCLASSEX wc = {};
		wc.cbSize = sizeof(WNDCLASSEX);
		wc.hInstance = GetModuleHandle(NULL);
		//wc.style = CS_HREDRAW | CS_VREDRAW;
		wc.hCursor = LoadCursor(NULL, IDC_IBEAM);
		wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);  // 不加的话如果窗口大小变化会出现黑色
		wc.lpfnWndProc = TextBoxProc;
		wc.lpszClassName = className;

		if (!RegisterClassEx(&wc)) {
			return ;
		}

		classRegistered = true;
	}

	CreateWindowEx(NULL,
				   className, titleName,
				   WS_CHILD | WS_VISIBLE | WS_BORDER,
				   x, y, 200, 200,
				   hWnd, NULL, GetModuleHandle(NULL), NULL);
}