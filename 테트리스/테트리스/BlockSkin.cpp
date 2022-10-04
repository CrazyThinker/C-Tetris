#include "BlockSkin.h"

CBlockSkin::CBlockSkin(void)
{
}

CBlockSkin::~CBlockSkin(void)
{
}

void CBlockSkin::BasicSkin(CPoint MapSize)
{
	int i, j;
	CRGBA BasicBk(255, 255, 255);
	CRGBA BasicRGB[7] = { CRGBA(237, 28, 36), CRGBA(255, 127, 39), CRGBA(255,242,0), CRGBA(34,177,76), CRGBA(0,162,232), CRGBA(63,72,204), CRGBA(163,73,164) };
	CRGBA BasicputRGB[7] = { CRGBA(255, 174, 201), CRGBA(255, 201, 14), CRGBA(239,228,176), CRGBA(181,230,29), CRGBA(153,217,234), CRGBA(112,146,190), CRGBA(200,191,231) };
	CCharacter BasicBoundary("¢Ì", CRGBA(136, 0, 21), CRGBA(195, 195, 195)), BasicBackground("¡¡", BasicBk, BasicBk), BasicInputBackground("¡¡", BasicBk, CRGBA(195, 195, 195, 0.5));

	for (i = 0; i < 7; i++)
	{
		skinBlock[i] = CCharacter("¡á", BasicRGB[i], BasicBk);
		skinPutBlock[i] = CCharacter("¡á", BasicputRGB[i], BasicBk);
		skinShadow[i] = CCharacter("¡à", BasicRGB[i], BasicBk);
		skinItem[i] = CCharacter("¢Ã", BasicputRGB[i], BasicBk);
	}
	skinPanelty = CCharacter("¡á", CRGBA(195,195,195), BasicBk);

	for (i = 0; i <= MapSize.x + 1; i++)
	{
		for (j = 0; j <= MapSize.y + 1; j++)
		{
			if (i == 0 || i == MapSize.x + 1 || j == 0 || j == MapSize.y + 1) skinBackground[i][j] = BasicBoundary;
			else if (i <= 4) skinBackground[i][j] = BasicInputBackground;
			else skinBackground[i][j] = BasicBackground;
		}
	}
	for (i = 0; i <= 5; i++)
	{
		for (j = 0; j <= 5; j++)
		{
			if (i == 0 || i == 5 || j == 0 || j == 5) skinPreview[i][j] = skinHold[i][j] = BasicBoundary;
			else skinPreview[i][j] = skinHold[i][j] = BasicBackground;
		}
	}
	skinPreview[0][1] = CCharacter("= ", CRGBA(136, 0, 21), CRGBA(195, 195, 195));
	skinPreview[0][2] = CCharacter("Ne", CRGBA(136, 0, 21), CRGBA(195, 195, 195));
	skinPreview[0][3] = CCharacter("xt", CRGBA(136, 0, 21), CRGBA(195, 195, 195));
	skinPreview[0][4] = CCharacter(" =", CRGBA(136, 0, 21), CRGBA(195, 195, 195));
	skinHold[0][1] = CCharacter("= ", CRGBA(136, 0, 21), CRGBA(195, 195, 195));
	skinHold[0][2] = CCharacter("Ho", CRGBA(136, 0, 21), CRGBA(195, 195, 195));
	skinHold[0][3] = CCharacter("ld", CRGBA(136, 0, 21), CRGBA(195, 195, 195));
	skinHold[0][4] = CCharacter(" =", CRGBA(136, 0, 21), CRGBA(195, 195, 195));

}
