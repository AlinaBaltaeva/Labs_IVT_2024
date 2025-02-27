#include <iostream>
#include <cstdlib>
using namespace std;

float sum( int n, float a[])
{
	float summ{};
	for (int i = 0; i < n; i++)
	{
		summ += a[i];
	}
	return summ;
}

void main()
{
	float x[] = { 30.5, 45.6, 78.9, 23.5, 12.7, 98.4, 64.9, 32.54 };
	float s = sum(8, x);
	cout << s << endl;
}


