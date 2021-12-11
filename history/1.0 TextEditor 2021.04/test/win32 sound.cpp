#include <Windows.h>

#pragma comment(lib, "winmm.lib")

int main() {
	PlaySoundW(L"SystemStart", NULL, SND_ALIAS);
}