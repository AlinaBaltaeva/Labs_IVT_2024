#pragma once
#include "Object.h"
#include <iostream>

using namespace std;

class Pair :
	public Object {
public:
	Pair(void);
public:
	virtual ~Pair(void);
	void Show();
	Pair(int, int);
	Pair(const Pair&);

	int getFirst() { return first; }
	int getSecond() { return second; }

	void setFirst(int);
	void setSecond(int);

	Pair& operator =(const Pair&);

	friend istream& operator >>(istream& in, Pair& P);
	friend ostream& operator <<(ostream& out, const Pair& P);

protected:
	int first, second;
};

