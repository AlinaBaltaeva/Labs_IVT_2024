#include "Time.h"

Time& Time::operator=(const Time& t) {
    if (this != &t) {
        min = t.min;
        sec = t.sec;
    }
    return *this;
}

Time Time::operator+(const Time& t) const {
    int total = min * 60 + sec + t.min * 60 + t.sec;
    return Time(total / 60, total % 60);
}

Time Time::operator/(const Time& t) const {
    int total1 = min * 60 + sec;
    int total2 = t.min * 60 + t.sec;
    return Time(total1 / total2, 0);
}

Time Time::operator/(int n) const {
    int total = min * 60 + sec;
    return Time(total / n / 60, (total / n) % 60);
}

bool Time::operator>(const Time& t) const {
    return (min > t.min) || (min == t.min && sec > t.sec);
}

bool Time::operator<(const Time& t) const {
    return (min < t.min) || (min == t.min && sec < t.sec);
}

bool Time::operator!=(const Time& t) const {
    return (min != t.min) || (sec != t.sec);
}

istream& operator>>(istream& in, Time& t) {
    cout << "min? "; in >> t.min;
    cout << "sec? "; in >> t.sec;
    return in;
}

ostream& operator<<(ostream& out, const Time& t) {
    return out << t.min << ":" << t.sec;
}