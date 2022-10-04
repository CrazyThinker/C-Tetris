#include "Point.h"

CPoint::CPoint(void)
{
}

CPoint::CPoint(int x, int y)
{
	this->x = x, this->y = y;
}

CPoint::CPoint(const CPoint& Point)
{
	this->x = Point.x, this->y = Point.y;
}

CPoint::~CPoint(void)
{
}

bool CPoint::operator == (CPoint d) const
{
	return this->x == d.x && this->y == d.y;
}

bool CPoint::operator != (CPoint d) const
{
	return this->x != d.x ||this->y != d.y;
}

CPoint CPoint::operator + (const CPoint& d)
{
	return CPoint(this->x + d.x, this->y + d.y);
}

CPoint CPoint::operator - (const CPoint& d)
{
	return CPoint(this->x - d.x, this->y - d.y);
}

CPoint& CPoint::operator += (const CPoint& d)
{
	this->x += d.x, this->y += d.y;
	return *this;
}
CPoint& CPoint::operator -= (const CPoint& d)
{
	this->x -= d.x, this->y -= d.y;
	return *this;
}