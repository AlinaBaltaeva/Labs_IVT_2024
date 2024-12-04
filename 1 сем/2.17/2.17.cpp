#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	setlocale(LC_ALL, "rus");
	int n, x;
	cout << "ВВедите длину многочлена" << endl;
	cin >> n;
	cout << "Введите значение переменной х" << endl;
	cin >> x;
	double y = 1;
	int f = 1;
	for (int i = 1; i <= n; i++)
	{
		f *= i;
		y += (pow(x, i)) / f;
	}
	cout << "значение многочлена равно:" << y << endl;
	return 0;
}