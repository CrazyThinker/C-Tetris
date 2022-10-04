#pragma once
#include "PlayerInfo.h"
#include "Point.h"
#include "Timer.h"
#include "DoubleScreen.h"
#include "Block.h"
#include "UserKeyboard.h"
#include "Resource.h"

class CPlayer : public CPlayerInfo
{
public:
	CBlock Map[MAP_SIZE + 2][MAP_SIZE + 2];
	int Score, brCursorType, brCursorDirection;
	CPoint pShadow, pbrCursor;
	CPoint MapSize;
	int brPreviewType[MAX_PREVIEW + 1], brPreviewDirection[MAX_PREVIEW + 1], brHoldType, brHoldDirection;
	CPoint pPreview[MAX_PREVIEW + 1], pHold;
	CUserKeyboard UserKeyboard;
	bool Die, HoldCheck, Enable, EnableCursor, EnableShadow;
	CTimer tDrop, tLineClear;

public:
	CPlayer(void);
	~CPlayer(void);

public: // 화면 출력
	void PrintMap(CDoubleScreen& Screen);
	void PrintPreviewBlock(CDoubleScreen& Screen, int Preview);
	void PrintHoldBlock(CDoubleScreen& Screen);
	void PrintCursorBlock(CDoubleScreen &Screen);
	void PrintShadow(CDoubleScreen& Screen);

public: // 키보드 입력
	bool SpinBlock(void);
	void LeftBlock(void);
	void RightBlock(void);
	int DownBlock(void);
	int CommandBlock(void);
	int HoldBlock(void);

public:
	void NewBlock(void);
	bool MoveCheck(CPoint Point, int brCursorDirection);
	bool IsInside(CPoint Point);
	CPoint GetShadowPoint(void);
	void PutBlock(void);
	int LineUpCheck(void);
	bool LineUp(void);
	bool CheckDie(void);

};

