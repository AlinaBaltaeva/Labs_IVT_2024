#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
int main()
{
    int n = 30;
    int* arr;
    int a;
    arr = new int[n * 3];
    srand(time(0));
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % 100 - 50;
    }
    cout << "Initial array: " << endl;

    for (int k = 0; k < n; k++)
    {
        cout << arr[k] << " ";
    }
    cout << endl;

    int len = sizeof(arr) / sizeof(arr[0]);
    int key = 0; // элемент, который необходимо удалить

    for (int i = 0; i < n; i++)  // поиск значения в массиве 
    {
        if (arr[i] == key)
        {
            len = len - 1;  // уменьшаем размер на один
            for (int j = i; j < n; j++)
            {
                arr[j] = arr[j + 1]; // перемещаем все элементы массива влево на один пробел
            }
            break;
        }
        cout << endl;
    }

    // после каждого четного элемента добавляем элемент со значение arr[i-1]+2
    for (int i = 0; i < n; i++)
    {
        if (arr[i] % 2 == 0)
        {
            a = arr[i - 1] + 2;
            for (int j = i + 1; j < n; j++)
            {
                arr[n - (j - (i + 1))] = arr[n - (j - i)];
            }
            arr[i + 1] = a;
            n++;
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}