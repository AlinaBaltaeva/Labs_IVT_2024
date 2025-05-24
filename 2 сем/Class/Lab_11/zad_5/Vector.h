#pragma once
#include <stack>
#include <vector>
#include <iostream>
using namespace std;

template<class T>
class Vector {
    stack<T> s;
    int len;
public:
    Vector();
    Vector(int n);
    Vector(const Vector<T>&);
    void Print();
    T Srednee();
    void Add(T el, int pos);
    T Max();
    void Del();
    T Min();
    void Delenie();
    void AddAverageToAll();
};

template<class T>
Vector<T>::Vector() : len(0) {}

template<class T>
Vector<T>::Vector(int n) {
    T a;
    for (int i = 0; i < n; i++) {
        cin >> a;
        s.push(a);
    }
    len = s.size();
}

template<class T>
Vector<T>::Vector(const Vector<T>& Vec) : len(Vec.len) {
    vector<T> v;
    stack<T> temp = Vec.s;
    while (!temp.empty()) {
        v.push_back(temp.top());
        temp.pop();
    }
    for (int i = v.size() - 1; i >= 0; i--) {
        s.push(v[i]);
    }
}

template<class T>
void Vector<T>::Print() {
    stack<T> temp = s;
    while (!temp.empty()) {
        cout << temp.top() << " ";
        temp.pop();
    }
    cout << endl;
}

template<class T>
T Vector<T>::Srednee() {
    vector<T> v;
    stack<T> temp = s;
    while (!temp.empty()) {
        v.push_back(temp.top());
        temp.pop();
    }
    T sum = v[0];
    for (size_t i = 1; i < v.size(); i++) {
        sum = sum + v[i];
    }
    return sum / v.size();
}

template<class T>
void Vector<T>::Add(T el, int pos) {
    vector<T> v;
    int i = 1;
    while (!s.empty()) {
        if (i == pos) v.push_back(el);
        v.push_back(s.top());
        s.pop();
        i++;
    }
    for (int i = v.size() - 1; i >= 0; i--) {
        s.push(v[i]);
    }
    len = s.size();
}

template<class T>
T Vector<T>::Max() {
    T m = s.top();
    stack<T> temp = s;
    while (!temp.empty()) {
        if (temp.top() > m) m = temp.top();
        temp.pop();
    }
    return m;
}

template<class T>
void Vector<T>::Del() {
    T m = Max();
    vector<T> v;
    while (!s.empty()) {
        if (s.top() != m) v.push_back(s.top());
        s.pop();
    }
    for (int i = v.size() - 1; i >= 0; i--) {
        s.push(v[i]);
    }
    len = s.size();
}

template<class T>
T Vector<T>::Min() {
    T m = s.top();
    stack<T> temp = s;
    while (!temp.empty()) {
        if (temp.top() < m) m = temp.top();
        temp.pop();
    }
    return m;
}

template<class T>
void Vector<T>::Delenie() {
    T m = Min();
    vector<T> v;
    while (!s.empty()) {
        v.push_back(s.top() / m);
        s.pop();
    }
    for (int i = v.size() - 1; i >= 0; i--) {
        s.push(v[i]);
    }
}

template<class T>
void Vector<T>::AddAverageToAll() {
    T avg = Srednee();
    vector<T> v;
    while (!s.empty()) {
        v.push_back(s.top() + avg);
        s.pop();
    }
    for (int i = v.size() - 1; i >= 0; i--) {
        s.push(v[i]);
    }
}