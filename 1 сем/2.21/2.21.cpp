#include <iostream>
using namespace std;
int main()
{
	setlocale(LC_ALL, "rus");
	bool flag = true;
	int n, k;
	
	cout << "Введите первое число(0-конец)" << endl;
	cin >> n;
	while (true)
	{
		cout << "Введите следующее число(0-конец)" << endl;
		cin >> k;
		if (k == 0)
		{
			break;
		}
		else
		{
			continue;
		}
		if (k < n)
		{
			flag = false;
			break;
		}
		n = k;
	}
	if (flag)
	{
		cout << "числа расположены по возрастанию" << endl;
	}
	else
	{ 
		cout << "числа не расположены по возрастанию" << endl;
	}
	return 0;
}
