#include "Rect.h"
#include <iostream>

using namespace std;

Rect::Rect(void) :Pair() {
	len = 0;
	width = 0;
}

Rect::~Rect(void) {}

Rect::Rect(int L, int W): Pair(L, W) {
	this->len = L;
	this->width = W;
}

Rect::Rect(const Rect& rect) {
	len = rect.len;
	width = rect.width;
}

void Rect::setLen(int L) {
	len = L;
}
void Rect::setWidth(int W) {
	width = W;;
}

Rect& Rect::operator =(const Rect& rect) {
	if (&rect == this) {
		return *this;
	}

	len = rect.len;
	width = rect.width;

	return *this;
}
int Rect::Per()
{
	return 2*(len + width);
}
int Rect::Sq()
{

	return len * width;
}


istream& operator >>(istream& in, Rect& rect) {

	cout << "\nLen: "; in >> rect.len;
	cout << "\nWidth: "; in >> rect.width;
	return in;
}

ostream& operator <<(ostream& out, const Rect& rect) {

	out << "\nLen: " << rect.len;
	out << "\nWidth: " << rect.width;
	return out;
}
void Rect::Show()
{
	cout << "\nLEN : " << len;
	cout << "\nWIDTH : " << width;
	cout << "\n";
}
