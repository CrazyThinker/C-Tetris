#pragma once
class CRGBA
{
public:
	unsigned char Red, Green, Blue;
	float Alpha;

public:
	CRGBA();
	CRGBA(const class CRGBA &RGBA);
	CRGBA(unsigned char Red, unsigned char Green, unsigned char Blue, float Alpha = 1);
	~CRGBA();

	bool operator == (CRGBA d) const;
	bool operator != (CRGBA d) const;

public:
	unsigned char GetRed(void);
	unsigned char GetGreen(void);
	unsigned char GetBlue(void);

};

