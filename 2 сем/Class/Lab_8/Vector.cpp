#include "Vector.h"
#include <iostream>

Vector::Vector(void)
{
    beg = nullptr;
    size = 0;
    cur = 0;
}
Vector::Vector(int n)
{
    beg = new Object * [n];
    cur = 0;
    size = n;
}
Vector::~Vector(void)
{
    if (beg != 0)
    {
        delete[] beg;
    }
    beg = 0;
}
void Vector::Add()
{
    Object* p;

    std::cout << "1.Person\n";
    std::cout << "2.Employee\n";
    std::cout << "choose (1/2) >> ";
    int y;
    std::cin >> y;

    if (y == 1)
    {
        Person* a = new (Person);
        a->input();
        p = a;
        if (cur < size)
        {
            beg[cur] = p;
            cur++;
        }
    }
    else if (y == 2)
    {
        Employee* b = new (Employee);
        b->input();
        p = b;
        if (cur < size)
        {
            beg[cur] = p;
            cur++;
        }
    }
    else
    {
        return;
    }
}

void Vector::Show()
{
    if (cur == 0)
    {
        std::cout << "\nEmpty\n";
    }
    Object** p = beg;
    for (int i = 0; i < cur; ++i)
    {
        (*p)->show();
        p++;
    }
}

int Vector::operator()()
{
    return cur;
}

void Vector::Del(void)
{
    if (cur == 0)
    {
        return;
    }
    cur--;
}

void Vector::Find(int tmp)
{
    Object** p = beg;
    for (int i = 0; i < cur; ++i)
    {
        if (i == tmp - 1)
        {
            (*p)->show();
        }
        p++;
    }
}
void Vector::HandleEvent(const TEvent& event)
{
    if (event.what == evMessage)
    {
        Object** p = beg;
        for (int i = 0; i < cur; ++i)
        {
            (*p)->show();
            ++p;
        }
    }
}