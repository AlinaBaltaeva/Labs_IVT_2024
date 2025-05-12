#pragma once
#include <iostream>
#include <fstream>
using namespace std; 

class Time
{
    int min;
    int sec;

public:
    Time();
    Time(int, int);
    Time(const Time& m);

    int getMin();
    int getSec();
    void setMin(int);
    void setSec(int);
    void normalize();

    friend std::ostream& operator<<(std::ostream& out, const Time& p);
    friend std::istream& operator>>(std::istream& in, Time& p);
    friend bool operator!=(const Time& first, const Time& second);
    Time& operator=(const Time&);
    Time operator-(const Time&)const;
    Time& operator--();
    Time operator--(int);
};