#include <iostream>
using namespace std;
int main()
{
	setlocale(LC_ALL, "rus");
	int n, max, k;
	cin >> n;
	cout << "введите первое число последовательности:" << endl;
	cin >> max;
	for (int i = 2; i <= n; i++)
	{
		cout << "введите следующее число: " << endl;
		cin >> k;

		if (k > max)
		{
			max = k;
		}
	}
	cout <<"максимальный элемент :" << max << endl;
	return 0;
}
