#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	int n, k;
	cin >> n;
	k = sqrt(n); //берем квадратный корень от n и передаем его в целое число k 
	for (int i = 0; i < k; i++)
	{
		for (int j = 0; j < k; j++)
		{
			cout << "* ";
		}
		cout << endl;
	}
	return 0;
}
