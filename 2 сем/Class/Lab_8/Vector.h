#pragma once
#include "Object.h"
#include "Person.h"
#include "Employee.h"
#include <iostream>


class Vector
{
protected:
    Object** beg;
    int size;
    int cur;

public:
    Vector(void);
    Vector(int);
    ~Vector(void);
    void Add(void);
    void Del(void);
    void Show(void);
    void Find(int);
    int operator()();
    void HandleEvent(const TEvent& event);
};
