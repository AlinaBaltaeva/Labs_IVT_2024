#include "Rect.h"
#include <iostream>

using namespace std;

Rect::Rect(void) :Pair() {
	lenght = 0;
	width = 0;
}

Rect::~Rect(void) {}

Rect::Rect(int L, int W): Pair(L, W) {
	lenght = L;
	width = W;
}

Rect::Rect(const Rect& rect) {
	lenght = rect.lenght;
	width = rect.width;
}

void Rect::setLenght(int L) {
	lenght = L;
}
void Rect::setWidth(int W) {
	width = W;;
}

Rect& Rect::operator =(const Rect& rect) {
	if (&rect == this) {
		return *this;
	}

	lenght = rect.lenght;
	width = rect.width;
	
	return *this;
}
int Rect::Per()
{
	return 2*(lenght + width);
}
int Rect::Sq()
{

	return lenght * width;
}

istream& operator >>(istream& in, Rect& rect) {
	
	cout << "\nLenght: "; in >> rect.lenght;
	cout << "\nWidth: ";in >> rect.width;
	return in;
}

ostream& operator <<(ostream& out, const Rect& rect) {

	out << "\nLenght: " << rect.lenght;
	out << "\nWidth: " << rect.width;
	return out;
}

