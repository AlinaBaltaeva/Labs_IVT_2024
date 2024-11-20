#include <iostream>
using namespace std;
int main()
{
	int n, a;
	cout << "1-A  2-B  3-C  " << endl;
	cin >> a;
	switch (a)
	{
	case 1:
		cout << "enter a number";
		cin >> n;
		if (n >= 0 && (sqrt(n) == floor(sqrt(n))))
		{
			int p = sqrt(n);
			for (int i = 0; i < sqrt(n); i++)
			{
				for (int j = 0; j < p; j++)
				{
					cout << "*";
				}
				cout << endl;

			}
		}
		else
		{
			cout << "enter another number" << endl;
		}
		break;

	
	case 2:
		cout << "enter a number";
		cin >> n;
		if (n > 1)
		{
			int p = n;
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < p; j++)
				{
					cout << "*";
				}
				cout << endl;
			}
		}
		else
		{
			cout << "enter another number" << endl;
		}
		break;

	case 3:
		cout << "enter a number";
		cin >> n;
		if (n > 1)
		{
			for (int i = 1; i <= n; i++)
			{
				for (int j = 1; j <= n; j++)
				{
					if (i == 1 || i == n || j == 1 || j == n)
					{
						cout << "*";
					}
					else
					{
						cout << " ";
					}
				}
				cout << endl;
			}
		}
		else
		{
			cout << "enter another number" << endl;
		}
	}
	return 0;
}