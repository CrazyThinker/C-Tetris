#pragma once
class CPoint
{
public:
	int x, y;

public:
	CPoint(void);
	CPoint(int x, int y);
	CPoint(const CPoint& Point);
	~CPoint(void);
	bool operator == (CPoint d) const;
	bool operator != (CPoint d) const;
	CPoint operator + (const CPoint& d);
	CPoint operator - (const CPoint& d);
	CPoint& operator += (const CPoint& d);
	CPoint& operator -= (const CPoint& d);

};
