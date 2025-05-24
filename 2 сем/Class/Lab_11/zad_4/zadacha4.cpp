#include <D:\2 сем\zadacha2\Time.h>
#include <D:\2 сем\zadacha2\Time.cpp>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

typedef stack<Time> St;
typedef vector<Time> Vec;

St make_stack(int n) {
    St s;
    Time t;
    for (int i = 0; i < n; i++) {
        cin >> t;
        s.push(t);
    }
    return s;
}

Vec copy_stack_to_vector(St s) {
    Vec v;
    while (!s.empty()) {
        v.push_back(s.top());
        s.pop();
    }
    return v;
}

St copy_vector_to_stack(Vec v) {
    St s;
    for (int i = 0; i < v.size(); i++) {
        s.push(v[i]);
    }
    return s;
}

void print_stack(St s) {
    Vec v = copy_stack_to_vector(s);
    for (Time t : v) {
        cout << t << " ";
    }
    cout << endl;
}

Time Min(St s) {
    Vec v = copy_stack_to_vector(s);
    Time m = v[0];
    for (Time t : v) {
        if (t < m) m = t;
    }
    return m;
}

void DeleteMin_from_stack(St& s) {
    Time min_val = Min(s);
    Vec v;
    while (!s.empty()) {
        Time t = s.top();
        if (t != min_val) v.push_back(t);
        s.pop();
    }
    s = copy_vector_to_stack(v);
}

int main() {
    try {
        St s;
        int n;

        cout << "Введите количество элементов: ";
        cin >> n;
        cout << "Введите элементы (минуты и секунды):" << endl;
        s = make_stack(n);

        cout << "\nИсходный стек:" << endl;
        print_stack(s);

        cout << "\nМинимальный элемент: " << Min(s) << endl;

        DeleteMin_from_stack(s);
        cout << "После удаления минимального элемента:" << endl;
        print_stack(s);
    }
    catch (...) {
        cout << "Ошибка!" << endl;
    }
    return 0;
}

