#include "Main.h"
#include "Point.h"
#include "Character.h"
#include "Block.h"
#include "Turboc.h"
#include "Timer.h"
#include "Keyboard.h"
#include "DoubleScreen.h"
#include "Player.h"
#include "Resource.h"
#include "RGBA.h"
#include "cful.h"

using namespace std;

// 전역 변수
int nUser;
CPlayer User[MAX_USER + 1];
CDoubleScreen Screen[MAX_USER + 1];

int Opening(void)
{
	int Cursor = 1;
	CCharacter cCursor("▶", CRGBA(255, 0, 0), CRGBA(242, 242, 242));
	CKeyboard Key;

	printf(RESET);
	printf("테트리스\n");
	printf("   게임 시작\n");
	printf("   게임 방법\n");
	printf("   게임 설정\n");

	while (1)
	{
		gotoxy(0, Cursor);
		cCursor.PrintScreen();
		printf(RESET);

		Key.GetKey();

		if (Key == KB_EXITGAME) return 0;
		else if (Key == KB_RETURN) return Cursor;
		else if (Key == KB_ARROW_UP)
		{
			if (Cursor == 1) continue;
			gotoxy(0, Cursor);
			printf("  ");
			Cursor--;
		}
		else if (Key == KB_ARROW_DOWN)
		{
			if (Cursor == 3) continue;
			gotoxy(0, Cursor);
			printf("  ");
			Cursor++;
		}
	}

	return 0;
}

void Help(void)
{
}

void Setting(void)
{
}

int Initialize(void)
{
	delay(0);
	clock();
	_kbhit();
	randomize();
	setcursortype(NOCURSOR);
	system("color F0");

//	MapSize = CPoint(20, 50);
//	setwindowsize(MapSize.y * 2 + 6, MapSize.x + 10);

	return 1;
}

void SampleUser(void)
{
	int i, j;

	nUser = 1;
	User[1].MapSize = CPoint(24, 10);
	User[1].pHold = CPoint(3, 16);
	User[1].pPreview[1] = CPoint(10, 16);
	User[1].tDrop.SetTimer(1000);
	User[1].brHoldType = -1;
	User[1].nPreview = 1;
	User[1].LineClearElapse = 500;
	for (i = 1; i <= User[1].nPreview; i++) User[1].brPreviewType[i] = -1;

	User[1].Skin.BasicSkin(User[1].MapSize);
	for (i = 0; i <= User[1].MapSize.x + 1; i++) for (j = 0; j <= User[1].MapSize.y + 1; j++) User[1].Map[i][j] = CBlock(0, User[1].Skin.skinBackground[i][j]);

	User[1].UserKeyboard = UserKey1;


	User[2].MapSize = CPoint(24, 10);
	User[2].pHold = CPoint(3, 16);
	User[2].pPreview[1] = CPoint(10, 16);
	User[2].tDrop.SetTimer(1000);
	User[2].brHoldType = -1;
	User[2].nPreview = 1;
	User[2].LineClearElapse = 500;
	for (i = 1; i <= User[2].nPreview; i++) User[2].brPreviewType[i] = -1;

	User[2].Skin.BasicSkin(User[2].MapSize);
	for (i = 0; i <= User[2].MapSize.x + 1; i++) for (j = 0; j <= User[2].MapSize.y + 1; j++) User[2].Map[i][j] = CBlock(0, User[2].Skin.skinBackground[i][j]);

	User[2].UserKeyboard = UserKey2;
}

void Game(void)
{
	int i, j, Line;

	clrscr();
	SampleUser();
	Screen[1].MapSize = CPoint(24, 20);
	Screen[2].MapSize = CPoint(24, 20);
	Screen[1].pStarting = CPoint(2, 2);
	Screen[2].pStarting = CPoint(2, 52);

	User[1].NewBlock();
	User[2].NewBlock();
	while (1)
	{
		if (GetAsyncKeyState(27) == -32767) return;

		for (i = 1; i <= nUser; i++)
		{
			if (User[i].Die == true) continue;
			//화면 출력
			User[i].PrintMap(Screen[i]);
			User[i].PrintHoldBlock(Screen[i]);
			for (j = 1; j <= User[i].nPreview;j++) User[i].PrintPreviewBlock(Screen[i], j);

			if (User[i].EnableShadow)
			{
				User[i].pShadow = User[i].GetShadowPoint();
				User[i].PrintShadow(Screen[i]);
			}
			if (User[i].EnableCursor) User[i].PrintCursorBlock(Screen[i]);

			Screen[i].ShowScreen();

			if (User[i].Enable)
			{
				// 키보드 입력
				if (GetAsyncKeyState(User[i].UserKeyboard.Up) == -32767) User[i].SpinBlock();
				if (GetAsyncKeyState(User[i].UserKeyboard.Left) == -32767) User[i].LeftBlock();
				if (GetAsyncKeyState(User[i].UserKeyboard.Right) == -32767) User[i].RightBlock();
				if (GetAsyncKeyState(User[i].UserKeyboard.Down) == -32767) User[i].DownBlock();
				if (GetAsyncKeyState(User[i].UserKeyboard.Command) == -32767) User[i].CommandBlock();
				if (GetAsyncKeyState(User[i].UserKeyboard.Hold) == -32767) User[i].HoldBlock();

				// 타이머
				if (User[i].tDrop.IsElapse()) User[i].DownBlock();
			}
			// 라인클리어 타이머
			else if (!User[i].Enable && User[i].tLineClear.IsElapse())
			{
				Line = User[i].LineUpCheck();
				if (Line == -1)
				{
					User[i].Enable = User[i].EnableCursor = User[i].EnableShadow = true;
					User[i].NewBlock();
				}
				else
				{
					User[i].LineUp();
					User[i].tLineClear.SetTime();
				}
			}
		}
	}
}

int main(void)
{
	int Result;

	if (Initialize() == 0)
	{
		printf("게임 초기화 실패!");
		getchar();
		return 0;
	}

	while (1)
	{
		clrscr();
		Result = Opening();
		if (Result == 1) { Game(); return 0; }
		else if (Result == 2) Help();
		else if (Result == 3) Setting();
		else break;
	}

	return 0;
}