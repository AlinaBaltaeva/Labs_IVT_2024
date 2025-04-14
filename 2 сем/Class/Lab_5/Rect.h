#pragma once
#include "Pair.h"
class Rect :
	public Pair
{
public:
	Rect();
public:
	~Rect();
	void Show() ;
	Rect(int, int);
	Rect(const Rect&);

	int getLen() { return len; }
	int getWidth() { return width; }

	void setLen(int);
	void setWidth(int);
	int Sq();
	int Per();

	Rect& operator =(const Rect&);

	friend istream& operator >>(istream& in, Rect& rect);
	friend ostream& operator <<(ostream& out, const Rect& rect);

protected:
	int len, width;
};

