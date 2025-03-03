// сумма вещественных чисел
// умножение обыкновенных дробей

#include <iostream>
#include <cstdlib>
using namespace std;

float sum( int n, float a[])
{
	float summ{};
	for (int i = 0; i < n; i++)
	{
		summ += a[i];
	}
	return summ;
}

float drob(double chislitelA, double znamenatelA, double chislitelB, double znamenatelB)
{
	if (znamenatelA!=0 && znamenatelB!=0)
	{
		return (chislitelA * chislitelB) / (znamenatelA * znamenatelB);
	}
}

void main()
{
	setlocale(LC_ALL, "rus");
	float x[] = { 30.5, 45.6, 78.9, 23.5, 12.7, 98.4, 64.9, 32.54, 65.3 };
	float s = sum(7, x);
	float s1 = sum(9, x);
	cout<<"Сумма семи чисел равна :" << s << endl;
	cout<<"Сумма девяти чисел равна :" << s1 << endl;

	double cA, zA, cB, zB;
	cout << "Введите числа для умножения дробей:" << endl;
	cin >> cA >> zA >> cB >> zB;
	double dr = drob(cA, zA, cB, zB);
	cout << "Произведение обыкновенных дробей равно:" << dr << endl;
}
