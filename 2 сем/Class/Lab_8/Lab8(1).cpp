#include "Dialog.h"
#include "Employee.h"
#include <iostream>


int main()
{
    Person* p = new Person;
    p->input();
    p->show();
    Employee* s = new Employee;
    s->input();
    s->show();
    Vector t(10);
    Object* o = p;
    t.Add();
    o = s;
    t.Show();
    t.Del();
    std::cout << "\nVector: " << t() << '\n';
    Dialog D;
    D.Execute();
    return 0;
}