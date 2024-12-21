// 3sin(x^0.5)+0.35x-3.8
// [2; 3]
// f'(x) = (3/(2*pow(x, 0.5)))*cos(pow(x, 0.5)+0.35
// eps=0.000001
// f'(x)>0
// r=max(|f'(a)|, |f'(b)|)
// r=0.52 
//-1/0.52 < L < 0 
// L=-1 берем удобное значение из диапазона

#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    float x, xPrev;
    double eps = 0.000001;
    double L = -1;
    x = 2;
    xPrev = 0;
    
    while (abs(x - xPrev) > eps)
    {
        xPrev = x;
        // F(x)=x+L*f(x)
        x = xPrev + L * (3 * sin(pow(x, 0.5)) + 0.35 * x - 3.8);
    }
    cout << "The root of the equation: " << x << endl;
    return 0;
}
