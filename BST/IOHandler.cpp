#include "IOHandler.h"



string IOHandler :: getString() const
{
	string s;
	cin >> s;
	return s;
}

void IOHandler :: showMenu() const
{
	cout<<"문자열들을 입력하세요 (마지막은 0) : ";
}