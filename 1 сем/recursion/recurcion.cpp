// написать программу, где выведет цифры  исходного числа в обратном порядке

#include <iostream>
#include <cmath>
using namespace std;

void Number(unsigned int n)
{
	if (n < 10)
	{
		cout << n << endl;
	}
	else 
	{
		cout << n % 10;
		Number(n / 10);
	}
}
int main()
{
	int n;
	cin >> n;
	cout << endl;
	Number(n);
}