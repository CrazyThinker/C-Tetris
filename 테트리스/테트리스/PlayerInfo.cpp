#include "PlayerInfo.h"
#include "Turboc.h"

CPlayerInfo::CPlayerInfo(void)
{
}

CPlayerInfo::~CPlayerInfo(void)
{
}

bool CPlayerInfo::LoadInformation(const char* strFile)
{
	FILE* fi = fopen(strFile, "r");
	if (fi == NULL) return false;

	fscanf(fi, "%s", this->ID);
	fscanf(fi, "%s", this->Password);
	fscanf(fi, "%d%d%d%d", &this->Level, &this->NowExp, &this->MaxExp, &this->Money);
	fscanf(fi, "%d", &this->nPreview);
	fclose(fi);

	return true;
}

void CPlayerInfo::SaveInformation(const char* strFile)
{
	FILE* fo = fopen(strFile, "w");
	fprintf(fo, "%s\n", this->ID);
	fprintf(fo, "%s\n", this->Password);
	fprintf(fo, "%d %d %d %d\n", this->Level, this->NowExp, this->MaxExp, this->Money);
	fprintf(fo, "%d\n", this->nPreview);
	fclose(fo);
}
