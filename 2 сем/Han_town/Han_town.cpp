#include <iostream>
#include <cstdlib>
using namespace std;

void han_town(int n, int start, int temp, int point)
{
	if (n > 0)
	{
		han_town(n - 1, start, temp, point);
		cout << start << "=>" << point;
		han_town(n - 1, temp, point, start);
	}
}
int main()
{
	int n, start, point;
	setlocale(LC_ALL, "rus");
	cout << "ВВедите количество дисков" << endl;
	cin >> n; 
	han_town(n, 1, 3, 2);
	return 0;
}