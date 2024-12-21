// 3sin(x^0.5)+035.x-3.8
// [2;3]
// eps=0.000001
// f'(x)=(3/(2*pow(x, 0.5)))*cos(x^0.5)+0.35
// f''(x)=-1.5*sin(x^0.5)

#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	float x, xPrev;
	// f(b)*f''(b)>0 
	// (3*sin(2.98 +1,05-3,8)*0.21>0
	x = 3;
	xPrev = 0;
	double eps = 0.000001;
	while (abs(x - xPrev) > eps)
	{
		xPrev = x;
		//xPrev-f(xPrev)/f'(xPrev)
		x = xPrev - (3 * sin(pow(xPrev, 0.5)) + 0.35 * xPrev - 3.8) / ((3 / (2 * pow(xPrev, 0.5))) * cos(pow(xPrev, 0.5)) + 0.35);
	}
	cout << "The root of the equayion:  " << x << endl;
	return 0;
}