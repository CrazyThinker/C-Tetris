#include "Timer.h"
#include<time.h>

CTimer::CTimer(void)
{
}

CTimer::CTimer(long Elapse)
{
	this->Elapse = Elapse;
	SetTime();
}

CTimer::CTimer(const CTimer& Timer)
{
	this->Time = Timer.Time;
	this->Elapse = Timer.Elapse;
}

CTimer::~CTimer(void)
{
}

void CTimer::SetTimer(long nElapse)
{
	this->Elapse = nElapse;
	SetTime();
}

void CTimer::SetTime(long nTime)
{
	this->Time = nTime;
}

bool CTimer::IsElapse(void)
{
	return clock() - Time >= Elapse;
}
