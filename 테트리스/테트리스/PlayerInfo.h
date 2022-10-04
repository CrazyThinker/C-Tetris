#pragma once
#include "Resource.h"
#include "BlockSkin.h"

class CPlayerInfo
{
private:
	int Level, NowExp, MaxExp, Money;
	char ID[MAX_ID + 1], Password[MAX_ID + 1];

public:
	int nPreview;
	CBlockSkin Skin;
	long LineClearElapse;

public:
	CPlayerInfo(void);
	//CPlayerInfo(CPlayerInfo &PlayerInfo);
	~CPlayerInfo(void);

public:
	bool LoadInformation(const char* strFile);
	void SaveInformation(const char* strFile);

};
