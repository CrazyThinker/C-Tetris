#pragma once
class CKeyboard
{
public:
	int Key;
	bool Type;

public:
	CKeyboard();
	CKeyboard(int Key, bool Type);
	CKeyboard(const CKeyboard& d);
	~CKeyboard();
	bool operator == (CKeyboard d) const;

	void GetKey(void);

};

const CKeyboard KB_EXITGAME(27, 1), KB_BACKSPACE(8, 1), KB_RETURN(13, 1), KB_SPACEBAR(32, 1);
const CKeyboard KB_ARROW_UP(72, 0), KB_ARROW_DOWN(80, 0), KB_ARROW_LEFT(75, 0), KB_ARROW_RIGHT(77, 0);
