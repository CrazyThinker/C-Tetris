#include "RGBA.h"

CRGBA::CRGBA(void)
{
	this->Alpha = 1;
}

CRGBA::CRGBA(const class CRGBA& RGBA)
{
	this->Red = RGBA.Red;
	this->Green = RGBA.Green;
	this->Blue = RGBA.Blue;
	this->Alpha = RGBA.Alpha;
}

CRGBA::CRGBA(unsigned char Red, unsigned char Green, unsigned char Blue, float Alpha)
{
	this->Red = Red;
	this->Green = Green;
	this->Blue = Blue;
	this->Alpha = Alpha;
}

CRGBA::~CRGBA(void)
{
}

bool CRGBA::operator == (CRGBA d) const
{
	return (unsigned char)(255 - (255 - this->Red) * Alpha) == (unsigned char)(255 - (255 - d.Red) * Alpha)
		&& (unsigned char)(255 - (255 - this->Green) * Alpha) == (unsigned char)(255 - (255 - d.Green) * Alpha)
		&& (unsigned char)(255 - (255 - this->Blue) * Alpha) == (unsigned char)(255 - (255 - d.Blue) * Alpha);
}

bool CRGBA::operator != (CRGBA d) const
{
	return (unsigned char)(255 - (255 - this->Red) * Alpha) != (unsigned char)(255 - (255 - d.Red) * Alpha)
		|| (unsigned char)(255 - (255 - this->Green) * Alpha) != (unsigned char)(255 - (255 - d.Green) * Alpha)
		|| (unsigned char)(255 - (255 - this->Blue) * Alpha) != (unsigned char)(255 - (255 - d.Blue) * Alpha);
}

unsigned char CRGBA::GetRed(void)
{
	return (unsigned char)(255 - (255 - this->Red) * Alpha);
}

unsigned char CRGBA::GetGreen(void)
{
	return (unsigned char)(255 - (255 - this->Green) * Alpha);
}

unsigned char CRGBA::GetBlue(void)
{
	return (unsigned char)(255 - (255 - this->Blue) * Alpha);
}
