#pragma once
#include <iostream>
using namespace std;

const int MAX_SIZE = 30;

class Vector
{
    int size;
    int* last;
public:
    Vector() { size = 0; last = 0; }
    Vector(int s);
    Vector(int s, int* mas);
    Vector(const Vector& v);
    ~Vector();
    const Vector& operator=(const Vector& v);
    int& operator[](int i);
    operator int() const { return size; }
    Vector operator+(int n);
    Vector operator-(int n);
    Vector operator--();

    friend ostream& operator<<(ostream& out, const Vector& v);
    friend istream& operator>>(istream& in, Vector& v);
};
