#include <iostream>
#include <string>
#include <locale>
#include <stdio.h>
#include <io.h>
#include <fcntl.h>

using namespace std;


using wchar = wchar_t;

static_assert(sizeof(wchar) == 2);


bool IsCharSingle(wchar ch) {
	/* 
	* https://docs.microsoft.com/en-us/windows/win32/intl/surrogates-and-supplementary-characters
	* 
	*/

	// high surrogate
	if (ch >= L'\xD800' && ch <= L'\xDBFF') { return false; }

	// low surrogate
	if (ch >= L'\xDC00' && ch <= L'\xDFFF') { return false; }

	return true;
}


bool IsCharChinese(wchar ch) {
	return ch >= L'\u4E00' && ch <= L'\u9FFF';
}

bool IsCharEnglish(wchar ch) {
	return ch >= L'\u0000' && ch <= L'\u007f';
}


int main() {
	/*
	* https://stackoverflow.com/questions/19193429/why-are-certain-unicode-characters-causing-stdwcout-to-fail-in-a-console-app
	* https://stackoverflow.com/questions/3207704/how-can-i-cin-and-cout-some-unicode-text
	* http://archives.miloush.net/michkap/archive/2008/03/18/8306597.html
	*/
	_setmode(_fileno(stdout), _O_WTEXT);
	_setmode(_fileno(stdin), _O_WTEXT);

	wstring str = L"ceshi测试";
	wcout << str << endl;
	while (true) {
		wcin >> str;
		if (str == L"exit") { break; }
		wcout << L'\t' << str << endl << L'\t';
		for (auto ch : str) {
			if (IsCharChinese(ch)) { wcout << L"C"; } 		//
			else if (IsCharEnglish(ch)) { wcout << L"E"; }	//
			else { wcout << L"N"; }							//
		}
		wcout << endl << L'\t';
		for (auto ch : str) {
			if (IsCharSingle(ch)) { wcout << L"S"; } 		//
			else { wcout << L"M"; }							//
		}
		wcout << endl;
	}
}