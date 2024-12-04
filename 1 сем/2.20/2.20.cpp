#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	setlocale(LC_ALL, "rus");
	bool flag = false;
	int n, s;
	cin >> n>>s;
	double a = 0;
	for (int i = 1; i <= n; i++)
	{
		
		a = sin(n + (i / n));
		cout << a;
	}
	if (s == a && !flag)
	{
		flag = true;
		cout << "Число найдено!" << endl;
	}
	else 
	{
		cout << "Число не найдено!" << endl;
	}
	cout<<endl;
	return 0;
}