#include <iostream>
using namespace std;
int main()
{
	setlocale(LC_ALL, "rus");
	int n, k;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> k;
		if (k != 0)
		{
			if (k > 0)
			{
				cout << "положительное число раньше отрицательного";
				break;
			}
			else
			{
				cout << "отрицательное число раньше положительного"<< endl;
				break;
			}
		}
	}
	return 0;
}

