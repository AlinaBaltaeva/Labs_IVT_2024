#include "Employee.h"
#include <iostream>


Employee::Employee(void) : Person()
{
   zp = 00;
   post = " ";
}

Employee::~Employee()
{
}

void  Employee::show()
{
    std::cout << " Employee :\n";
    std::cout << " name: " << name << "\n";
    std::cout << " age: " << age << "\n";
    std::cout << " zp: " << zp << "\n";
    std::cout << " post: " << post << "\n";
}

void Employee::input()
{
    std::cout << "Student name: ";
    std::cin >> name;
    std::cout << "Student age: ";
    std::cin >> age;
    std::cout << "Student zp: ";
    std::cin >> zp;
    std::cout << "Student post: ";
    std::cin >> post;
}
Employee::Employee(std::string N, int A, float Z, string P) : Person(N, A)
{
    name = N;
    age = A;
    zp = Z;
    post = P;
}

Employee::Employee(const Employee& employee)
{
    name = employee.name;
    age = employee.age;
    zp = employee.zp;
    post = employee.post;

}
Employee& Employee::operator=(const Employee& employee)
{
    if (&employee == this)
    {
        return *this;
    }
    name = employee.name;
    age = employee.age;
    zp = employee.zp;
    post = employee.post;
    return *this;
}

float Employee::getZp()
{
    return zp;
}
string Employee::getPost()
{
    return post;
}

void Employee::setZp(float value)
{
    zp = value;
}
void Employee::setPost(string value)
{
    post = value;
}