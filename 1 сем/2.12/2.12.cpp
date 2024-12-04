#include <iostream>
using namespace std;
int main()
{
	int n, k, max, min;
	cout << "" << endl;
	cin >> n;
	cout << "" << endl;
	cin >> k;
	max = k;
	min = k;
	for (int i = 2; i <= n; i++)
	{
		cout << "" << endl;
		cin >> k;
		if (max < k)
		{
			max = k;
		}
		else if (min > k)
		{
			min = k;
		}
	}
	cout <<"Сумма максимального и минисального элемнтов:"<<(max+min)<< endl;
	return 0;
}
