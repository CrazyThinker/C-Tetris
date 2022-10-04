#include "Keyboard.h"
#include "Turboc.h"

CKeyboard::CKeyboard(void)
{
}

CKeyboard::CKeyboard(int Key, bool Type)
{
	this->Key = Key, this->Type = Type;
}

CKeyboard::CKeyboard(const CKeyboard& d)
{
	this->Key = d.Key, this->Type = d.Type;
}

CKeyboard::~CKeyboard(void)
{
}

bool CKeyboard::operator == (CKeyboard d) const
{
	return this->Key == d.Key && this->Type == d.Type;
}

void CKeyboard::GetKey(void)
{
	this->Key = _getch();
	this->Type = true;
	if (this->Key == 0 || this->Key == 0xE0)
	{
		this->Key = _getch();
		this->Type = false;
	}
}