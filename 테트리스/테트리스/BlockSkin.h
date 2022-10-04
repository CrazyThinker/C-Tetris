#pragma once
#include "Block.h"
#include "Resource.h"

class CBlockSkin
{
public:
	CCharacter skinBlock[7], skinPutBlock[7];
	CCharacter skinBackground[MAP_SIZE + 2][MAP_SIZE + 2];
	CCharacter skinShadow[7];
	CCharacter skinItem[7];
	CCharacter skinPanelty;
	CCharacter skinPreview[6][6], skinHold[6][6];

public:
	CBlockSkin(void);
	~CBlockSkin(void);

public:
	bool LoadSkin(const char* strFile);
	void SaveSkin(const char* strFile);
	void BasicSkin(CPoint MapSize);

};
