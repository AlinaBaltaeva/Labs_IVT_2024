#include <iostream>
using namespace std;
int main()
{
	setlocale(LC_ALL, "rus");
	int n, k;
	cout << "ВВедите натуральное число" << endl;
	cin >> n;
	if (n < 10)
	{
		cout << "ВВедите другое число" << endl;
	}
	while (n > 0)
	{
		k = n % 10;  //получаем последнюю цифру из числа
		cout << k;
		n = n / 10;
	}
	cout << endl;
	return 0;
}