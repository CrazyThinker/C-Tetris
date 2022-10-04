#include "Turboc.h"

// 혼자 연구하는 C/C++의 도우미 소스 파일
// 비주얼 C++ 환경에서 터보 C 스타일의 함수를 정의한다.

// 커서를 x,y좌표로 이동시킨다.
void gotoxy(int x, int y)
{
	COORD Cur;
	Cur.X = x;
	Cur.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
}

// 커서의 x 좌표를 조사한다.
int wherex()
{
	CONSOLE_SCREEN_BUFFER_INFO BufInfo;

	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &BufInfo);
	return BufInfo.dwCursorPosition.X;
}

// 커서의 y좌표를 조사한다.
int wherey()
{
	CONSOLE_SCREEN_BUFFER_INFO BufInfo;

	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &BufInfo);
	return BufInfo.dwCursorPosition.Y;
}

// 커서를 숨기거나 다시 표시한다.
void setcursortype(CURSOR_TYPE c)
{
	CONSOLE_CURSOR_INFO CurInfo;

	switch (c) {
	case NOCURSOR:
		CurInfo.dwSize = 1;
		CurInfo.bVisible = FALSE;
		break;
	case SOLIDCURSOR:
		CurInfo.dwSize = 100;
		CurInfo.bVisible = TRUE;
		break;
	case NORMALCURSOR:
		CurInfo.dwSize = 20;
		CurInfo.bVisible = TRUE;
		break;
	}
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &CurInfo);
}

// 다음에 입력될 문자들의 색을 바꿉니다.
void settextcolor(const char color[3])
{
	WORD attr, previous_background_color;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(hConsole, &csbi);
	previous_background_color = csbi.wAttributes >> 0x4;
	previous_background_color = previous_background_color << 0x4;
	// Foreground Color
	switch (color[0])
	{
	case '0': // Black
		attr = 0;
		break;
	case '1': // Blue
		attr = FOREGROUND_BLUE;
		break;
	case '2': // Green
		attr = FOREGROUND_GREEN;
		break;
	case '3': // Aqua (Cyan)
		attr = FOREGROUND_GREEN | FOREGROUND_BLUE;
		break;
	case '4': // Red
		attr = FOREGROUND_RED;
		break;
	case '5': // Purple (Magenta)
		attr = FOREGROUND_RED | FOREGROUND_BLUE;
		break;
	case '6': // Yellow
		attr = FOREGROUND_RED | FOREGROUND_GREEN;
		break;
	case '7': // White (Gray: System Default)
		attr = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE;
		break;
	case '8': // Gray (Light Black)
		attr = FOREGROUND_INTENSITY;
		break;
	case '9': // Light Blue
		attr = FOREGROUND_BLUE | FOREGROUND_INTENSITY;
		break;
	case 'A': // Light Green
		attr = FOREGROUND_GREEN | FOREGROUND_INTENSITY;
		break;
	case 'B': // Light Aqua (Cyan)
		attr = FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY;
		break;
	case 'C': // Light Red
		attr = FOREGROUND_RED | FOREGROUND_INTENSITY;
		break;
	case 'D': // Light Purple (Magenta)
		attr = FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY;
		break;
	case 'E': // Light Yellow
		attr = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY;
		break;
	case 'F': // Bright White
		attr = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY;
		break;
	}
	// Background Color
	switch (color[1])
	{
	case '\0': // 배경색이 지정돼 있지 않으면 기존의 배경색을 사용.
		// 전경색만 지정하면 배경색이 항상 검정으로 되어 버림.
		attr = attr | previous_background_color;
		break;
	case '0': // Black
		attr = attr | 0;
		break;
	case '1': // Blue
		attr = attr | BACKGROUND_BLUE;
		break;
	case '2': // Green
		attr = attr | BACKGROUND_GREEN;
		break;
	case '3': // Aqua (Cyan)
		attr = attr | BACKGROUND_GREEN | BACKGROUND_BLUE;
		break;
	case '4': // Red
		attr = attr | BACKGROUND_RED;
		break;
	case '5': // Purple (Magenta)
		attr = attr | BACKGROUND_RED | BACKGROUND_BLUE;
		break;
	case '6': // Yellow
		attr = attr | BACKGROUND_RED | BACKGROUND_GREEN;
		break;
	case '7': // White (Gray: System Default)
		attr = attr | BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE;
		break;
	case '8': // Gray (Light Black)
		attr = attr | BACKGROUND_INTENSITY;
		break;
	case '9': // Light Blue
		attr = attr | BACKGROUND_BLUE | BACKGROUND_INTENSITY;
		break;
	case 'A': // Light Green
		attr = attr | BACKGROUND_GREEN | BACKGROUND_INTENSITY;
		break;
	case 'B': // Light Aqua (Cyan)
		attr = attr | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY;
		break;
	case 'C': // Light Red
		attr = attr | BACKGROUND_RED | BACKGROUND_INTENSITY;
		break;
	case 'D': // Light Purple (Magenta)
		attr = attr | BACKGROUND_RED | BACKGROUND_BLUE | BACKGROUND_INTENSITY;
		break;
	case 'E': // Light Yellow
		attr = attr | BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_INTENSITY;
		break;
	case 'F': // Bright White
		attr = attr | BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY;
		break;
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), attr);
}

// 콘솔창의 크기를 설정한다
void setwindowsize(int con, int line)
{
	char szText[100];
	sprintf(szText, "mode con cols=%d lines=%d", con, line);
	system(szText);
}
