#include "Header.h"
#include <iostream>

Pair::Pair(void) {
	first = 0;
	second = 0;
}
Pair::~Pair(void) {}

Pair::Pair(int F, int S) {
	first = F;
	second = S;
}

Pair::Pair(const Pair& pair) {
	first = pair.first;
	second = pair.second;
}

void Pair::setFirst(int F) {
	first = F;
}
void Pair::setSecond(int S) {
	second = S;
}

Pair& Pair::operator =(const Pair& pair) {
	if (&pair == this) {
		return *this;
	}
	first = pair.first;
	second = pair.second;
	return *this;
}

istream& operator >>(istream& in, Pair& P) {
	cout << "\nFirst: "; in >> P.first;
	cout << "\nSecond: "; in >> P.second;
	return in;
}

ostream& operator <<(ostream& out, const Pair& P) {
	out << "\nFIRST: " << P.first;
	out << "\nSECOND: " << P.second;
	return out;
}
