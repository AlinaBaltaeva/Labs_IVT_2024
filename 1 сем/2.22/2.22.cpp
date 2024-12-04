#include <iostream>
using namespace std;
int main()
{
    setlocale(LC_ALL, "rus");
    float n, max, a;
    int i = 1;
    int f = 1;
    int l = 1;
    cout << "Введите длину последовательности" << endl;
    cin >> n;
    max = sin(n + i / n);

    while (i <= n)
    {
        a = sin(n = i / n);
        if (a > max)
        {
            max = a;
            f = i;
            l = i;
        }
        else if (a == max)
        {
            l = i;
        }
        i++;
    }
    cout << "Максимальный элемент последовательности равен  " << max << "  его первый максимальный номер равен  " << f << "  его второй максимальный номер равен  " << l << endl;
    return 0;
}