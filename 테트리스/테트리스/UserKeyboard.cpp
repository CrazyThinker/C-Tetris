#include "UserKeyboard.h"

CUserKeyboard::CUserKeyboard(void)
{
}

CUserKeyboard::CUserKeyboard(int Up, int Down, int Left, int Right, int Command, int Hold)
{
	this->Up = Up;
	this->Down = Down;
	this->Left = Left;
	this->Right = Right;
	this->Command = Command;
	this->Hold = Hold;
}

CUserKeyboard::CUserKeyboard(CUserKeyboard& UserKeyboard)
{
	this->Up = UserKeyboard.Up;
	this->Down = UserKeyboard.Down;
	this->Left = UserKeyboard.Left;
	this->Right = UserKeyboard.Right;
	this->Command = UserKeyboard.Command;
	this->Hold = UserKeyboard.Hold;
}

CUserKeyboard::~CUserKeyboard(void)
{
}
