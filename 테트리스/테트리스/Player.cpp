#include "Player.h"
#include "Turboc.h"
#include "Resource.h"

CPlayer::CPlayer(void)
{
	Score = 0;
	Die = HoldCheck = false;
	Enable = EnableCursor = EnableShadow = true;
}

CPlayer::~CPlayer(void)
{
}

void CPlayer::PrintMap(CDoubleScreen& Screen)
{
	int i, j;

	for (i = 0; i <= MapSize.x + 1; i++) for (j = 0; j <= MapSize.y + 1; j++) Screen.Print(i, j, CCharacter(Map[i][j].Character, Map[i][j].FGColor, Skin.skinBackground[i][j].BGColor));
}

void CPlayer::PrintCursorBlock(CDoubleScreen& Screen)
{
	int i, j;

	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 4; j++)
		{
			if (Blocks[brCursorType][brCursorDirection][i][j] && IsInside(pbrCursor + CPoint(i, j))) Screen.Print(pbrCursor.x + i, pbrCursor.y + j, CCharacter(Skin.skinBlock[brCursorType].Character, Skin.skinBlock[brCursorType].FGColor, Skin.skinBackground[pbrCursor.x + i][pbrCursor.y + j].BGColor));
		}
	}
}

void CPlayer::PrintShadow(CDoubleScreen& Screen)
{
	int i, j;

	for (i = 0; i < 4; i++) for (j = 0; j < 4; j++) if (Blocks[brCursorType][brCursorDirection][i][j] && IsInside(pShadow + CPoint(i, j))) Screen.Print(pShadow.x + i, pShadow.y + j, CCharacter(Skin.skinShadow[brCursorType].Character, Skin.skinShadow[brCursorType].FGColor, Skin.skinBackground[pShadow.x + i][pShadow.y + j].BGColor));
}

void CPlayer::PrintPreviewBlock(CDoubleScreen& Screen, int Preview)
{
	int i, j;

	for (i = 0; i <= 5; i++)
	{
		for (j = 0; j <= 5; j++)
		{
			if (i == 0 || i == 5 || j == 0 || j == 5) Screen.Print(pPreview[Preview].x + i, pPreview[Preview].y + j, Skin.skinPreview[i][j]);
			else if (brPreviewType[Preview] == -1) continue;
			else if (Blocks[brPreviewType[Preview]][brPreviewDirection[Preview]][i - 1][j - 1]) Screen.Print(pPreview[Preview].x + i, pPreview[Preview].y + j, CCharacter(Skin.skinBlock[brPreviewType[Preview]].Character, Skin.skinBlock[brPreviewType[Preview]].FGColor, Skin.skinPreview[i][j].BGColor));
			else Screen.Print(pPreview[Preview].x + i, pPreview[Preview].y + j, CCharacter("¡¡", Skin.skinPreview[i][j].FGColor, Skin.skinPreview[i][j].BGColor));
		}
	}
}

void CPlayer::PrintHoldBlock(CDoubleScreen& Screen)
{
	int i, j;

	for (i = 0; i <= 5; i++)
	{
		for (j = 0; j <= 5; j++)
		{
			if (i == 0 || i == 5 || j == 0 || j == 5) Screen.Print(pHold.x + i, pHold.y + j, Skin.skinHold[i][j]);
			else if (brHoldType == -1) continue;
			else if (Blocks[brHoldType][brHoldDirection][i - 1][j - 1]) Screen.Print(pHold.x + i, pHold.y + j, CCharacter(Skin.skinBlock[brHoldType].Character, Skin.skinBlock[brHoldType].FGColor, Skin.skinHold[i][j].BGColor));
			else Screen.Print(pHold.x + i, pHold.y + j, CCharacter("¡¡", Skin.skinHold[i][j].FGColor, Skin.skinHold[i][j].BGColor));
		}
	}
}

void CPlayer::NewBlock(void)
{
	int i;

	pbrCursor = CPoint(1, MapSize.y / 2 - 2);
	if (brPreviewType[1] + 1) brCursorType = brPreviewType[1], brCursorDirection = brPreviewDirection[1];
	else brCursorType = random(7), brCursorDirection = random(4);
	for (i = 1; i <= nPreview - 1; i++)
	{
		if (brPreviewType[i + 1] + 1) brPreviewType[i] = brPreviewType[i + 1], brPreviewDirection[i] = brPreviewDirection[i + 1];
		else brPreviewType[i] = random(7), brPreviewDirection[i] = random(4);
	}
	brPreviewType[i] = random(7), brPreviewDirection[i] = random(4);

	HoldCheck = false;
}

CPoint CPlayer::GetShadowPoint(void)
{
	CPoint Point = this->pbrCursor;

	while(MoveCheck(Point, this->brCursorDirection)) Point += CPoint(1, 0);

	return Point - CPoint(1,0);
}

bool CPlayer::IsInside(CPoint Point)
{
	return 1 <= Point.x && Point.x <= MapSize.x && 1 <= Point.y && Point.y <= MapSize.y;
}

bool CPlayer::MoveCheck(CPoint Point, int brCursorDirection)
{
	int i, j;

	for (i = 0; i < 4; i++) for (j = 0; j < 4; j++) if (Blocks[brCursorType][brCursorDirection][i][j] && (!IsInside(Point + CPoint(i, j)) || Map[Point.x + i][Point.y + j].Type)) return false;
	return true;
}

void CPlayer::PutBlock(void)
{
	int i, j, Line;
	CPoint Point;

	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 4; j++)
		{
			if (Blocks[brCursorType][brCursorDirection][i][j] && IsInside(pShadow + CPoint(i, j)))
			{
				Point = pShadow + CPoint(i, j);
				Map[Point.x][Point.y] = CBlock(1, Skin.skinBlock[brCursorType]);
			}
		}
	}

	Line = LineUpCheck();
	if (Line + 1)
	{
		LineUp();
		tLineClear.SetTimer(LineClearElapse);
		Enable = EnableCursor = EnableShadow = false;
	}
	else NewBlock();
}

bool CPlayer::SpinBlock(void)
{
	int Origin = brCursorDirection;

	while (1)
	{
		brCursorDirection = (brCursorDirection + 1) % 4;
		if (brCursorDirection == Origin) return false;
		if (MoveCheck(pbrCursor, brCursorDirection)) break;
	}

	return true;
}

void CPlayer::LeftBlock(void)
{
	if(MoveCheck(pbrCursor - CPoint(0, 1), brCursorDirection)) pbrCursor -= CPoint(0, 1);
}

void CPlayer::RightBlock(void)
{
	if (MoveCheck(pbrCursor + CPoint(0, 1), brCursorDirection)) pbrCursor += CPoint(0, 1);
}

int CPlayer::DownBlock(void) // -1 : Die, 0 : NewBlock, 1 : Down
{
	tDrop.SetTime();

	int Result = MoveCheck(pbrCursor + CPoint(1, 0), brCursorDirection);
	if (Result) pbrCursor += CPoint(1, 0);
	else
	{
		PutBlock();
		if (CheckDie())
		{
			Die = true;
			return -1;
		}
		else NewBlock();
		return 0;
	}

	return 1;
}

int CPlayer::CommandBlock(void) // -1 : Die, 0 : NewBlock
{
	tDrop.SetTime();

	PutBlock();
	if (CheckDie()) Die = true;
	return !Die - 1;
}

int CPlayer::HoldBlock(void)
{
	if (HoldCheck == true) return false;

	if (brHoldType == -1)
	{
		brHoldType = brCursorType, brHoldDirection = brCursorDirection;
		NewBlock();
	}
	else
	{
		int tmpbrHoldType, tmpbrHoldDirection;

		tmpbrHoldType = brHoldType, tmpbrHoldDirection = brHoldDirection;
		brHoldType = brCursorType, brHoldDirection = brCursorDirection;
		brCursorType = tmpbrHoldType, brCursorDirection = tmpbrHoldDirection;
	}
	pbrCursor = CPoint(1, MapSize.y / 2 - 2);
	HoldCheck = true;
	tDrop.SetTime();

	return true;
}

int CPlayer::LineUpCheck(void)
{
	int i, j;

	for (i = MapSize.x; i >= 1; i--)
	{
		for (j = 1; j <= MapSize.y; j++) if (!Map[i][j].Type) break;
		if (j == MapSize.y + 1) break;
	}
	if (i == 0) return -1;
	else return i;
}

bool CPlayer::LineUp(void)
{
	int i, j, Line;

	Line = LineUpCheck();
	if (Line == -1) return false;

	for (i = Line - 1; i >= 1; i--) for (j = 1; j <= MapSize.y; j++) Map[i + 1][j] = Map[i][j];
	return true;
}

bool CPlayer::CheckDie(void)
{
	int i, j;
	for (i = 1; i <= 4; i++) for (j = 1; j <= MapSize.y; j++) if (Map[i][j].Type) return true;
	return false;
}
