#pragma once
#include "RGBA.h"

class CCharacter
{
public:
	char Character[3];
	CRGBA FGColor, BGColor;

public:
	CCharacter(void);
	CCharacter(const CCharacter& Character);
	CCharacter(const char* Character, CRGBA FGColor, CRGBA BGColor);
	~CCharacter(void);

	bool operator == (CCharacter d) const;
	bool operator != (CCharacter d) const;

public:
	void PrintScreen(void);
};
