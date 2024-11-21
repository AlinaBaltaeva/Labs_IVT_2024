#include <iostream>
using namespace std;
int main()
{
	int n;
	int sum;
	cin >> n;
	if (n <= 0)
	{
		cout << "enter another number" << endl;
	}
	else
	{
		for (int i = 1; i <= n; i++)
		{
			sum += 1;
		}
		cout << sum << endl;
	}
	return 0;
}