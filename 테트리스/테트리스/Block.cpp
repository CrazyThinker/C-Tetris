#include "Block.h"
#include "RGBA.h"
#include "Turboc.h"
#include "cful.h"

CBlock::CBlock(void)
{
	this->Type = 0;
}

CBlock::CBlock(const CBlock& Block)
{
	this->Type = Block.Type;
	this->Character[0] = Block.Character[0], this->Character[1] = Block.Character[1], this->Character[2] = Block.Character[2];
	this->FGColor = Block.FGColor;
	this->BGColor = Block.BGColor;
}

CBlock::CBlock(int Type, CCharacter Character)
{
	this->Type = Type;
	this->Character[0] = Character.Character[0], this->Character[1] = Character.Character[1], this->Character[2] = Character.Character[2];
	this->FGColor = Character.FGColor;
	this->BGColor = Character.BGColor;
}

CBlock::CBlock(int Type, const char* Character, CRGBA FGColor, CRGBA BGColor)
{
	this->Type = Type;
	this->Character[0] = Character[0], this->Character[1] = Character[1], this->Character[2] = Character[2];
	this->FGColor = FGColor;
	this->BGColor = BGColor;
}

CBlock::~CBlock(void)
{
}

void CBlock::PrintScreen(CPoint Point, CPoint pStarting)
{
	gotoxy(pStarting.y + Point.y * 2 - 2, pStarting.x + Point.x - 1);
	CCharacter::PrintScreen();
}
