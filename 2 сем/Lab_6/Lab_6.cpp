//. Сформировать одномерный массив. Удалить из него элемент
//с заданным ключом, добавить элемент с заданным ключом;

#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	srand(time(0));
	int range_min, range_max;
	range_min = 2;
	range_max = 280000;
	int size;
	cout << "Размер массива:";
	cin >> size;

	int* arr = new int[size];
	for (int i = 0; i < size; i++)
	{
		arr[i] =((double)rand() / RAND_MAX) * (range_max -
			range_min) + range_min;
		cout << arr[i] << endl;
	}
	int k;
	cout << "Введите элемент: " << endl;
	cin >> k;

	int newsize = size + 1;
	int* mas = new int[newsize];

	for (int i = 0; i < newsize; i++)
	{
		mas[i] = arr[i];
	}
	mas[size] = k;
	cout << "Новый массивы: " << endl;
	for (int i = 0; i < newsize; i++)
	{
		cout << mas[i] << endl;
	}

	cout << "Введите элемент, который хотите удалить: " << endl;
	int b;
	cin >> b;
	int delsize = size - 1;

	for (int i = 0; i < newsize; i++)
	{
		if (mas[i] == b)
		{
			newsize = newsize - 1;
			for (int j = i; j < newsize; j++)
				mas[j] = mas[j + 1];
		}
	}
	cout << "Новый массивы: " << endl;
	for (int i = 0; i < newsize; i++)
	{
		cout << mas[i] << endl;
	}
	delete[] mas;

	return 0;
}


