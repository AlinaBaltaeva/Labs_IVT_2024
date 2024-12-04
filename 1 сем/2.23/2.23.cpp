#include <iostream>
using namespace std;
int main()
{
	setlocale(LC_ALL, "rus");
	float n, max, a;

	cout << "Введите длину последовательности" << endl;
	cin >> n;
	int k = 1;
	int i = 1;
	max = sin(n + i / n);
	while (i <= n)
	{
		a = sin(n + i / n);
		if (a > max)
		{
			max = a;
			k = 1;
		}
		else if (a == max)
		{
			k++;
		}
		i++;
	}
	cout << "Максимальный эелемент: "<<max<<" Количество максимальных элементов: "<< k << endl;
	return 0;
}