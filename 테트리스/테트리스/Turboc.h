#pragma once
// 혼자 연구하는 C/C++의 도우미 헤더 파일
// 비주얼 C++ 환경에서 터보 C 스타일의 함수를 정의한다.

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <windows.h>
#include <io.h>

typedef enum { NOCURSOR, SOLIDCURSOR, NORMALCURSOR } CURSOR_TYPE;
void gotoxy(int x, int y);							// 커서를 x,y좌표로 이동시킨다.
int wherex();										// 커서의 x 좌표를 조사한다.
int wherey();										// 커서의 y 좌표를 조사한다.
void setcursortype(CURSOR_TYPE c);					// 커서를 숨기거나 다시 표시한다.
void settextcolor(const char color[3]);			// 다음에 입력될 문자들의 색을 바꿉니다.
void setwindowsize(int con, int line);				// 콘솔창의 크기를 설정한다

#define delay(n) Sleep(n)							// n/1000초만큼 시간 지연
#define randomize() srand((unsigned)time(NULL))		// 난수 발생기 초기화
#define random(n) (rand() % (n))					//0~n까지의 난수 발생
#define clrscr() system("cls")						// 화면을 모두 지운다.
