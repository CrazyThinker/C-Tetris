#include "DoubleScreen.h"
#include "Turboc.h"
#include "cful.h"

CDoubleScreen::CDoubleScreen(void)
{
}

CDoubleScreen::CDoubleScreen(const CDoubleScreen& DoubleScreen)
{
	int i, j;

	this->MapSize = DoubleScreen.MapSize,this->pStarting = DoubleScreen.pStarting;
	for (i = 0; i <= DoubleScreen.MapSize.x + 1; i++) for (j = 0; j <= DoubleScreen.MapSize.y + 1; j++) this->VirtualScreen[i][j] = DoubleScreen.VirtualScreen[i][j], this->RealScreen[i][j] = DoubleScreen.RealScreen[i][j];
}

CDoubleScreen::~CDoubleScreen(void)
{
}

void CDoubleScreen::ShowScreen(void)
{
	int i, j;

	for (i = 0; i <= this->MapSize.x + 1; i++)
	{
		for (j = 0; j <= this->MapSize.y + 1; j++)
		{
			if (this->VirtualScreen[i][j] != this->RealScreen[i][j])
			{
				gotoxy(pStarting.y + j * 2, pStarting.x + i);
				this->VirtualScreen[i][j].PrintScreen();
				this->RealScreen[i][j] = this->VirtualScreen[i][j];
			}
		}
	}

}

void CDoubleScreen::Print(int x, int y, CCharacter Character)
{
	this->VirtualScreen[x][y] = Character;
}
