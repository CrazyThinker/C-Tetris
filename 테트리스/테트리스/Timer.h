#pragma once
#include<time.h>

class CTimer
{
public:
	long Time, Elapse;

public:
	CTimer(void);
	CTimer(long Elapse);
	CTimer(const CTimer& Timer);
	~CTimer(void);

	void SetTimer(long nElapse);
	void SetTime(long nTime = clock());
	bool IsElapse(void);

};
