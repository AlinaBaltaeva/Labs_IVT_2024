#include "Time.h"
#include <iostream>
using namespace std;

Time::Time(void)
{
	min = sec = 0;
}
Time::Time(int M, int S)
{
	min = M;
	sec = S;
}
Time::Time(const Time& t)
{
	min = t.min;
	sec = t.sec;
}
Time& Time::operator=(const Time& t)
{
	min = t.min;
	sec = t.sec;
	return *this;
}
Time Time::operator+(Time k)
{
	int t = min * 60 + sec;
	int kt = k.min * 60 + k.sec;
	t += kt;
	Time temp(t / 60, t % 60);
	return temp;
}
Time Time::operator+(int seconds) const {
	int total_sec = min * 60 + sec + seconds;
	Time result(total_sec / 60, total_sec % 60);
	result.norm();
	return result;
}
ostream& operator<<(ostream& out, const Time& t)
{
	out << t.min << " : " << t.sec;
	return out;
}
void Time::norm() {
	if (sec >= 60) {
		min += sec / 60;
		sec %= 60;
	}
}
istream& operator>>(istream& in,Time& t)
{

	t.norm();
	cout << "\nmin?  "; 
	in >> t.min;
	cout << "\nsec?  "; in >> t.sec;
	t.norm();
	return in;
}