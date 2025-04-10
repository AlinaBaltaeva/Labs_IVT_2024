#include <iostream>
#include "Time.h"

using namespace std;

Time& Time::operator =(const Time& temp) {
	if (&temp == this) {return *this;}
	min = temp.min;
	sec = temp.sec;
	return *this;
}

Time& Time::operator ++() {
	int temp =min * 60 + sec;
	temp++;
	min = temp / 60;
	sec = temp % 60;
	return *this;
}

Time Time::operator ++(int) {
	int temp = min * 60 + sec;
	temp++;
	Time t1(min, sec);
	min = temp / 60;
	sec = temp % 60;
	return t1;
}

Time Time::operator +(const Time& temp) {
	int t1 = min*60+sec;
	int t2 = temp.min * 60 + temp.sec;
	Time temp2;
	temp2.min = (t1 + t2) / 60;
	temp2.sec = (t1 + t2) % 60;
	return temp2;
}

istream& operator >>(istream& in, Time& temp) {
	cout << "min: ";
	in >> temp.min;
	cout << "sec: ";
	in >> temp.sec;
	return in;
}

ostream& operator <<(ostream& out, const Time& temp) {
	return (out << temp.min << " : " << temp.sec);
}
