#include "Time.h"
#include <iostream>
using namespace std;


Time::Time()
{
    min = sec = 0;
}

Time::Time(int m, int s)
{
    min = m;
    sec = s;
    normalize();
}

Time::Time(const Time& m)
{
    min = m.min;
    sec = m.sec;
}

int Time::getMin()
{
    return min;
}

int Time::getSec()
{
    return sec;
}

void Time::setMin(int value)
{
    min = value;
    normalize();

}

void Time::setSec(int value)
{
    sec = value;
    normalize();

}
void Time::normalize()
{
    if (sec >= 60)
    {
        min += sec / 60;
        sec %= 60;
    }
    else if (sec < 0)
    {
        int borrow = (-sec + 59) / 60;
        min -= borrow;
        sec += borrow * 60;
    }

    if (min < 0)
    {
        min = 0;
        sec = 0;
    }
}

std::ostream& operator<<(std::ostream& out, const Time& p)
{
    out << "Time: ";
    out << p.min << ":" << p.sec;
    out << '\n';
    return out;
}

std::istream& operator>>(std::istream& in, Time& t)
{
    char colon;
    in >> t.min >> colon >> t.sec;
    t.normalize();
    return in;
}

bool operator!=(const Time& first, const Time& second)
{
    return (first.min != second.min) || (first.sec != second.sec);
}

Time Time::operator-(const Time& other)const
{
    Time result;
    result.sec = sec - other.sec;
    result.min = min - other.min;
    result.normalize();
    return result;
}

Time& Time::operator=(const Time& m)
{
    if (&m == this)
    {
        return *this;
    }
    min = m.min;
    sec = m.sec;
    return *this;
}

Time& Time::operator--()
{
    min -= 1;
    sec -= 30;
    normalize();
    return *this;
}

Time Time::operator--(int)
{
    Time temp(*this);
    --(*this);
    return temp;
}
