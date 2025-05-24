#include "Time.h"
#include "Vector.h"
#include <iostream>
using namespace std;

int main() {
    try {
        cout << "Введите 3 элемента Time (минуты и секунды):" << endl;
        Vector<Time> v(3);

        cout << "\nИсходный стек:" << endl;
        v.Print();

        Time avg = v.Srednee();
        cout << "\nСреднее значение: " << avg << endl;
        v.AddAverageToAll();
        cout << "После добавления среднего ко всем элементам:" << endl;
        v.Print();

        int pos;
        cout << "Введите позицию для добавления среднего: ";
        cin >> pos;
        v.Add(avg, pos);
        cout << "После добавления среднего в позицию " << pos << ":" << endl;
        v.Print();

        Time max_val = v.Max();
        cout << "\nМаксимальный элемент: " << max_val << endl;
        v.Del();
        cout << "После удаления максимального:" << endl;
        v.Print();

        Time min_val = v.Min();
        cout << "\nМинимальный элемент: " << min_val << endl;
        v.Delenie();
        cout << "После деления на минимальный:" << endl;
        v.Print();
    }
    catch (...) {
        cout << "Ошибка!" << endl;
    }
    return 0;
}