#include "Character.h"
#include "RGBA.h"
#include "Turboc.h"
#include "cful.h"

CCharacter::CCharacter(void)
{
	memset(this->Character, 0, sizeof(this->Character));
	this->FGColor = CRGBA(0, 0, 0);
	this->BGColor = CRGBA(0, 0, 0);
}

CCharacter::CCharacter(const CCharacter& Character)
{
	this->Character[0] = Character.Character[0], this->Character[1] = Character.Character[1], this->Character[2] = Character.Character[2];
	this->FGColor = Character.FGColor;
	this->BGColor = Character.BGColor;
}

CCharacter::CCharacter(const char* Character, CRGBA FGColor, CRGBA BGColor)
{
	this->Character[0] = Character[0], this->Character[1] = Character[1], this->Character[2] = '\0';
	this->FGColor = FGColor;
	this->BGColor = BGColor;
}

CCharacter::~CCharacter(void)
{
}

bool CCharacter::operator == (CCharacter d) const
{
	return this->Character[0] == d.Character[0] && this->Character[1] == d.Character[1] && this->FGColor == d.FGColor && this->BGColor == d.BGColor;
}

bool CCharacter::operator != (CCharacter d) const
{
	return this->Character[0] != d.Character[0] || this->Character[1] != d.Character[1] || this->FGColor != d.FGColor || this->BGColor != d.BGColor;
}

void CCharacter::PrintScreen(void)
{
	SET_FG_COLOR(this->FGColor.GetRed(), this->FGColor.GetGreen(), this->FGColor.GetBlue());
	SET_BG_COLOR(this->BGColor.GetRed(), this->BGColor.GetGreen(), this->BGColor.GetBlue());
	printf("%s", this->Character);
}
