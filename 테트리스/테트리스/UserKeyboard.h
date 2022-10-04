#pragma once
class CUserKeyboard
{
public:
	int Up, Down, Left, Right, Command, Hold;

public:
	CUserKeyboard(void);
	CUserKeyboard(int Up, int Down, int Left, int Right, int Command, int Hold);
	CUserKeyboard(CUserKeyboard& UserKeyboard);
	~CUserKeyboard(void);
};

const CUserKeyboard UserKey1(38, 40, 37, 39, 188, 190);
const CUserKeyboard UserKey2('W', 'S', 'A', 'D', 32, 90);
