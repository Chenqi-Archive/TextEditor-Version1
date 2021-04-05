#include "main_frame.h"


#pragma comment(lib, "WndDesign.lib")
#pragma comment(lib, "StaticStore.lib")


int main() {
	MainFrame main_frame;
	desktop.AddChild(main_frame);
	desktop.MessageLoop();
}