
#include "window/main_frame.h"


#ifdef _DEBUG
#pragma comment(lib, "../build/x64/Debug/WndDesignHelper.lib")
#else
#pragma comment(lib, "../build/x64/Release/WndDesignHelper.lib")
#endif


MainFrame* main_frame;

void Init(uint argc, const wchar_t* argv[]) {
	main_frame = new MainFrame();
}

void Final() {
	delete main_frame;  // main_frame will auto metically save file when destructs.
}
