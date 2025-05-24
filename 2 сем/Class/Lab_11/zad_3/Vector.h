#pragma once
#include <vector>
#include <iostream>
using namespace std;

template<class T>
class Vector {
    vector<T> v;
    int len;
public:
    Vector();
    Vector(int n);
    void Print();
    T Srednee();
    void Add(T el, int pos);
    int Max();
    void Del(int pos);
    int Min();
    void Delenie();
    void AddMax();
    ~Vector();
};

template<class T>
Vector<T>::Vector() {
    len = 0;
}

template<class T>
Vector<T>::Vector(int n) {
    T a;
    for (int i = 0; i < n; i++) {
        cin >> a;
        v.push_back(a);
    }
    len = v.size();
}

template<class T>
void Vector<T>::Print() {
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
    cout << endl;
}

template<class T>
T Vector<T>::Srednee() {
    T s = v[0];
    for (int i = 1; i < v.size(); i++)
        s = s + v[i];
    return s / v.size();
}

template<class T>
void Vector<T>::Add(T el, int pos) {
    v.insert(v.begin() + pos, el);
}

template<class T>
int Vector<T>::Max() {
    T m = v[0];
    int n = 0;
    for (int i = 1; i < v.size(); i++)
        if (v[i] > m) {
            m = v[i];
            n = i;
        }
    return n;
}

template<class T>
void Vector<T>::Del(int pos) {
    v.erase(v.begin() + pos);
}

template<class T>
int Vector<T>::Min() {
    T m = v[0];
    int n = 0;
    for (int i = 1; i < v.size(); i++)
        if (v[i] < m) {
            m = v[i];
            n = i;
        }
    return n;
}

template<class T>
void Vector<T>::Delenie() {
    int m = Min();
    T min = v[m];
    if (min.get_min() == 0 && min.get_sec() == 0)
        throw "Division by zero!";
    for (int i = 0; i < v.size(); i++)
        v[i] = v[i] / min;
}

template<class T>
void Vector<T>::AddMax() {
    if (v.empty()) return;
    int max_pos = Max();
    T max_val = v[max_pos];
    v.insert(v.begin(), max_val);
}

template<class T>
Vector<T>::~Vector() {}