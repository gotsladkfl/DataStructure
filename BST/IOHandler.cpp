#include "IOHandler.h"



string IOHandler :: getString() const
{
	string s;
	cin >> s;
	return s;
}

void IOHandler :: showMenu() const
{
	cout<<"���ڿ����� �Է��ϼ��� (�������� 0) : ";
}