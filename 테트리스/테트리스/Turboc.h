#pragma once
// ȥ�� �����ϴ� C/C++�� ����� ��� ����
// ���־� C++ ȯ�濡�� �ͺ� C ��Ÿ���� �Լ��� �����Ѵ�.

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <windows.h>
#include <io.h>

typedef enum { NOCURSOR, SOLIDCURSOR, NORMALCURSOR } CURSOR_TYPE;
void gotoxy(int x, int y);							// Ŀ���� x,y��ǥ�� �̵���Ų��.
int wherex();										// Ŀ���� x ��ǥ�� �����Ѵ�.
int wherey();										// Ŀ���� y ��ǥ�� �����Ѵ�.
void setcursortype(CURSOR_TYPE c);					// Ŀ���� ����ų� �ٽ� ǥ���Ѵ�.
void settextcolor(const char color[3]);			// ������ �Էµ� ���ڵ��� ���� �ٲߴϴ�.
void setwindowsize(int con, int line);				// �ܼ�â�� ũ�⸦ �����Ѵ�

#define delay(n) Sleep(n)							// n/1000�ʸ�ŭ �ð� ����
#define randomize() srand((unsigned)time(NULL))		// ���� �߻��� �ʱ�ȭ
#define random(n) (rand() % (n))					//0~n������ ���� �߻�
#define clrscr() system("cls")						// ȭ���� ��� �����.
