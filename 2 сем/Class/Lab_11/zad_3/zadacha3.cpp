#include "Time.h"
#include "Vector.h"
#include <iostream>
using namespace std;

int main() {
    try {
        cout << "Введите 5 элементов Time (минуты и секунды):" << endl;
        Vector<Time> vec(5);

        cout << "Исходный вектор:" << endl;
        vec.Print();

        vec.AddMax();
        cout << "После добавления максимального элемента в начало:" << endl;
        vec.Print();

        Time avg = vec.Srednee();
        cout << "Среднее арифметическое: " << avg << endl;

        int pos;
        cout << "Введите позицию для добавления среднего: ";
        cin >> pos;
        vec.Add(avg, pos);
        cout << "После добавления среднего:" << endl;
        vec.Print();

        int max_pos = vec.Max();
        vec.Del(max_pos);
        cout << "\nПосле удаления максимального элемента:" << endl;
        vec.Print();
        vec.Delenie();
        cout << "После деления на минимальный элемент:" << endl;
        vec.Print();
    }
    catch (const char* msg) {
        cerr << "Ошибка: " << msg << endl;
    }
    catch (...) {
        cerr << "Неизвестная ошибка!" << endl;
    }
    return 0;
}