#pragma once
#include "Character.h"
#include "Point.h"
#include "Resource.h"

class CDoubleScreen
{
public:
	CPoint MapSize, pStarting;
	CCharacter VirtualScreen[MAP_SIZE + 2][MAP_SIZE + 2], RealScreen[MAP_SIZE + 2][MAP_SIZE + 2];

public:
	CDoubleScreen(void);
	CDoubleScreen(const CDoubleScreen& DoubleScreen);
	~CDoubleScreen(void);

public:
	void ShowScreen(void);
	void Print(int x,int y, CCharacter Character);
};
