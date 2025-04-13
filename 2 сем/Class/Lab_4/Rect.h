#pragma once
#include "Header.h"
class Rect :
    public Pair
{
public:
	Rect(void);
public:
	~Rect(void);
	Rect(int, int);
	Rect(const Rect&);

	int getLenght() { return lenght; }
	int getWidth() { return width; }
	
	void setLenght(int);
	void setWidth(int);
	int Sq();
	int Per();
	
	Rect& operator =(const Rect&);

	friend istream& operator >>(istream& in, Rect& rect);
	friend ostream& operator <<(ostream& out, const Rect& rect);

protected:
	int lenght, width;
};

