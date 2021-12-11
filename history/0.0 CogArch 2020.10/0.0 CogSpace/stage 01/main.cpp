#include <Windows.h>
#include <windowsx.h>

#include "textbox.h"

LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

int APIENTRY wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
			LPWSTR lpCmdLine, int nCmdShow) 
{
	const wchar_t className[] = L"CogArchWndClass";
	const wchar_t titleName[] = L"CogArch";

	WNDCLASSEX wc = {};
	wc.cbSize = sizeof(WNDCLASSEX);
	wc.hInstance = hInstance;
	//wc.style = CS_HREDRAW | CS_VREDRAW;
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);  // 不加的话如果窗口大小变化会出现黑色
	wc.lpfnWndProc = WndProc;
	wc.lpszClassName = className;

	if (!RegisterClassEx(&wc)) {
		return 0;
	}

	HWND hWnd = CreateWindowEx(NULL,
							   className, titleName,
							   WS_OVERLAPPEDWINDOW,
							   200, 200, 800, 500,
							   NULL, NULL, hInstance, NULL);

	if (hWnd == NULL) {
		return 0;
	}

	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);

	MSG msg;

	while (GetMessage(&msg, NULL, 0, 0)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return (int)msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {
	switch (msg) {
		case WM_PAINT: {
				PAINTSTRUCT ps;
				HDC hdc = BeginPaint(hWnd, &ps);

				EndPaint(hWnd, &ps);
			}break;
		case WM_LBUTTONUP: { // 左键按下创建文本框
				CreateTextBox(hWnd, GET_X_LPARAM(lParam), GET_Y_LPARAM(lParam));
			}break;
		case WM_DESTROY:
			PostQuitMessage(0);
			break;
		default:	
			return DefWindowProc(hWnd, msg, wParam, lParam);
	}
	return 0;
}

