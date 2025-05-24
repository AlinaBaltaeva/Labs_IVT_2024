#include <iostream>
#include <list>
#include <cstdlib>
#include <algorithm>
#include <numeric>
using namespace std;

typedef list<float> List; 


List make_list(int n) {
    List lst;
    for (int i = 0; i < n; i++) {
        float a = (rand() % 100 - 50) / 10.0f; 
        lst.push_back(a);
    }
    return lst;
}
void print_list(const List& lst) {
    for (float val : lst) {
        cout << val << " ";
    }
    cout << endl;
}
float srednee(const List& lst) {
    float sum = accumulate(lst.begin(), lst.end(), 0.0f); //сумма всех элементов 
    return sum / lst.size();
}

void add_element(List& lst, float el, int pos) {
    if (pos < 0 || pos > lst.size()) throw 1;
    auto it = lst.begin();
    advance(it, pos);
    lst.insert(it, el);
}

auto find_max(const List& lst) {
    return max_element(lst.begin(), lst.end());
}

void remove_max(List& lst) {
    auto max_it = find_max(lst);
    if (max_it != lst.end()) {
        lst.erase(max_it);
    }
}

void divide_by_min(List& lst) {
    if (lst.empty()) throw 3;
    float min_val = *min_element(lst.begin(), lst.end());
    if (min_val == 0.0f) throw 2;

    for (float& val : lst) {
        val /= min_val;
    }
}

int main() {
    setlocale(LC_ALL, "ru");
    try {
        List lst;
        int n;
        cout << "Сколько значений выводить ? ";
        cin >> n;
        lst = make_list(n);
        print_list(lst);

        float avg = srednee(lst);
        cout << "Среднее значение: " << avg << endl;
        cout << "Положение для вставки? ";
        int pos;
        cin >> pos;
        add_element(lst, avg, pos);
        print_list(lst);

        
        remove_max(lst);
        cout << "После удаления максимального элемента: ";
        print_list(lst);

        divide_by_min(lst);
        cout << "После деления на минимум: ";
        print_list(lst);
    }
    catch (int e) {
        if (e == 1) {
            cout << "Ошибка: Неверная позиция!" << endl;
        }
        else if (e == 2) {
            cout << "Ошибка: Деление на ноль!" << endl;
        }
        else if (e == 3) {
            cout << "Ошибка: Пустой список!" << endl;
        }
    }
    return 0;
}