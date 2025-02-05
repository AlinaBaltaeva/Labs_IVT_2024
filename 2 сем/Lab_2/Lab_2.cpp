#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;
int main()
{
	int range_min, range_max, tmp;
	srand(time(0));
	const int n = 3;
	const int m = 4;
	int arr[n][m];
	range_min = 2;
	range_max = 280000;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			arr[i][j] = ((double)rand() / RAND_MAX) * (range_max - range_min) + range_min;
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;


	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (arr[i][2] > arr[j][2])
			{
				for (int k = 0; k < m; k++)
				{
					tmp = arr[i][k];
					arr[i][k] = arr[j][k];
					arr[j][k] = tmp;
				}
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	return 0;
}
