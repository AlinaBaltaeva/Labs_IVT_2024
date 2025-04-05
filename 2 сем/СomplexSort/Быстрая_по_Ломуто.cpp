//Исходный массив делится на определенные части, каждая из которых
//сортируется независимо.Идея в том, что объединение этих частей не требует
//пересортировки в отличие от сортировки слиянием.
//1. Если диапазон менее 2 - х элементов, сразу же прекращаем действия,
//  т.к.сортировать нечего.
//2. Выбираем точку(pivot, значение), которая встречается в диапазоне.
//  Конкретный принцип выбора такого значения зависит от выбранного извода и
//  может включать элеметы случайности(рандомизации).
//3.Разбиваем диапазон на части : меняем порядок элементов,
//  одновременно определяя точку деления таким образом, чтобы элементы со
//  значением меньшим, чем pivot, шли до точки деления, тогда как элементы с
//  большим значением — после точки деления.Элементы, равные значению
//  pivot, могут записываться в любую часть(зависит от извода).Т.к.минимум
//  одно значение равно pivot, большинство изводов стремятся точку деления
//  приравнять к pivot.
//4. Рекурсивно применяем быструю сортировку к каждой из полученных
//  частей(до и после точки деления), пока алгоритм это позволяет(т.е.пока он не остановится на шаге 1)


#include <iostream>
using namespace std;

void createArray(int arr[], int size) 
{
    srand(time(0));
    if (size >= 2) 
    {
        for (int i = 0; i < size; i++) 
        {
            arr[i] = rand() % 100;
        }
    }
    else 
    {
        cout << "Error (size)" << endl;
        exit(0);
    }

    for (int i = 0; i < size; i++)
    { 
        cout << arr[i] << " "; 
    }
    cout << endl;
}

int quickSort(int arr[], int startElem, int endElem)
{
    int pivot = arr[endElem];
    int pivIndex = startElem;
    for (int i = startElem; i < endElem; i++) 
    {
        if (arr[i] <= pivot) {
            swap(arr[i], arr[pivIndex]);
            pivIndex++;
        }
    }
    swap(arr[pivIndex], arr[endElem]);
    return pivIndex;
}

void LomutoSort(int arr[], int start, int end) 
{
    if (start >= end)  return;
    int pivot = quickSort(arr, start, end);
    LomutoSort(arr, start, pivot - 1);
    LomutoSort(arr, pivot + 1, end);
}

int main()
{
    setlocale(LC_ALL, "ru");
    int const n = 10; 
    int arr[n];
    cout << "Данный массив:" << endl;
    createArray(arr, n);
    cout << "Отсортированный массив:" << endl;
    LomutoSort(arr, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " "; 
    }
    return 0;
}
