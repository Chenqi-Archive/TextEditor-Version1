#include <iostream>
#include <string>
#include <locale>
#include <stdio.h>
#include <io.h>
#include <fcntl.h>
#include <cassert>

#include <icu.h>


#pragma comment(lib, "icu.lib")


using namespace std;


using uint = unsigned int;
using wchar = wchar_t;



struct Range {
	uint begin;
	uint length;
};


const Range GetWordAtPos(const wstring& str, uint pos) {
	uint size = (uint)str.size();
	if (pos >= size) { return { 0,0 }; }

	UErrorCode status = U_ZERO_ERROR;

	static_assert(sizeof(wchar_t) == sizeof(UChar));
	UBreakIterator* ubreak_iterator = ubrk_open(UBRK_WORD, "", (const UChar*)str.c_str(), (uint)str.length(), &status);

	uint end = ubrk_following(ubreak_iterator, pos);
	uint begin = ubrk_previous(ubreak_iterator);
	assert(end >= begin);

	ubrk_close(ubreak_iterator);

	return { begin, end - begin };
}


int main() {
	_setmode(_fileno(stdout), _O_WTEXT);
	_setmode(_fileno(stdin), _O_WTEXT);

	wstring str = L"Win32下ICU库中文分词测试";

	while (true) {

		// in normal order
		uint pos = 0;
		while (pos < str.size()) {
			Range range = GetWordAtPos(str, pos);
			wcout<< str.substr(range.begin, range.length) << L" ";
			assert(range.begin + range.length <= str.size());
			pos = range.begin + range.length;
		}
		wcout << endl;

		// in reverse order
		pos = (uint)str.size() - 1;
		while (pos < str.size()) {
			Range range = GetWordAtPos(str, pos);
			wcout << str.substr(range.begin, range.length) << L" ";
			assert(range.begin + range.length <= str.size());
			pos = range.begin - 1; // if pos underflows, the loop will break
		}
		wcout << endl << endl;


		// read more test strings from console
		wcin >> str;

		if (str == L"exit") { break; }
	}
}