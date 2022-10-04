#pragma once
#include "Character.h"
#include "Point.h"

class CBlock : public CCharacter
{
public:
	int Type; // 0: �������, 1: ���, 2: ������

public:
	CBlock(void);
	CBlock(const CBlock& Block);
	CBlock(int Type, CCharacter Character);
	CBlock(int Type, const char* Character, CRGBA FGColor, CRGBA BGColor);
	~CBlock(void);

public:
	void PrintScreen(CPoint Point, CPoint pStarting = CPoint(0, 0));

};
