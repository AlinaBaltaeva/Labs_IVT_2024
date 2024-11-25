#include <iostream>
using namespace std;
int main()
{
	int n;
	cin >> n;
	if (n < 2)
	{
		cout << "error" << endl;
	}
	else {
		int p = n;
		int t = 1;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < t; j++)
			{
				cout << "* ";
			}
			for (int j = 0; j < p; j++)
			{
				cout << "  ";
			}
			p--;
			t++;
			cout << endl;
		}
	}
	return 0;
}