#include <iostream>
#include <vector>
#include <cstdlib>
#include "Time.h"
using namespace std;

typedef vector<Time> Vec; // определяем тип для работы с вектором

// функция для формирования вектора
Vec make_vector(int n) {
    Vec v; // пустой вектор
    for (int i = 0; i < n; i++) {
        int m = rand() % 60; // случайные минуты (0-59)
        int s = rand() % 60; // случайные секунды (0-59)
        v.push_back(Time(m, s)); // добавляем Time в конец вектора
    }
    return v;
}

// функция для печати вектора
void print_vector(Vec v) {
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
    cout << endl;
}

// вычисление среднего арифметического
Time srednee(Vec v) {
    Time sum;
    for (int i = 0; i < v.size(); i++) {
        sum = sum + v[i];
    }
    return sum / v.size();
}

// добавление элемента в вектор
void add_vector(Vec& v, Time el, int pos) {
    v.insert(v.begin() + pos, el);
}

// поиск максимального элемента
int max(Vec v) {
    int m = 0; // номер максимального элемента
    for (int i = 1; i < v.size(); i++) {
        if (v[i] > v[m]) {
            m = i;
        }
    }
    return m;
}

// удаление элемента из вектора
void del_vector(Vec& v, int pos) {
    v.erase(v.begin() + pos);
}

// поиск минимального элемента
int min(Vec v) {
    int m = 0; // номер минимального элемента
    for (int i = 1; i < v.size(); i++) {
        if (v[i] < v[m]) {
            m = i;
        }
    }
    return m;
}

// деление каждого элемента на минимальное значение
void delenie(Vec& v) {
    int m = min(v);
    Time min_val = v[m];
    if (min_val.get_min() == 0 && min_val.get_sec() == 0) {
        throw 2; // обработка деления на ноль
    }
    for (int i = 0; i < v.size(); i++) {
        v[i] = v[i] / min_val;
    }
}

int main() {
    try {
        Vec v;
        int n;
        cout << "N? ";
        cin >> n;
        v = make_vector(n);
        print_vector(v);

        // Задание 3: Добавление среднего арифметического
        Time avg = srednee(v);
        cout << "Average: " << avg << endl;
        cout << "Position to insert? ";
        int pos;
        cin >> pos;
        if (pos > v.size()) throw 1;
        add_vector(v, avg, pos);
        print_vector(v);

        // Задание 4: Удаление максимального элемента
        int n_max = max(v);
        del_vector(v, n_max);
        cout << "After removing max: ";
        print_vector(v);

        // Задание 5: Деление на минимальный элемент
        delenie(v);
        cout << "After division by min: ";
        print_vector(v);
    }
    catch (int e) {
        if (e == 1) {
            cout << "Error: Invalid position!";
        }
        else if (e == 2) {
            cout << "Error: Division by zero!";
        }
        else {
            cout << "Unknown error!";
        }
    }
    return 0;
}