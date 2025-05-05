#pragma once
#include "Person.h"
#include <iostream>
#include <string>
using namespace std;



class Employee : public Person
{
protected:
    float zp;
    string post;

public:
    Employee(void);
    Employee(string, int, float, string);
    Employee(const  Employee&);
    ~Employee(void);
    float getZp();
    string getPost();
    void setZp(float);
    void setPost(string);
    void show();
    void input();
    Employee& operator=(const  Employee&);
};