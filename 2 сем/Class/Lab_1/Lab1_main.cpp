#include <iostream>
#include "Header.h"
using namespace std;
Money make_money(int F, int S)
{
	Money temp;
	temp.Init(F, S);
    return temp;
}
int main() {
    Money M;
    M.Init(1, 1);
    M.Read();
    M.Show();
    cout << M.sum();

    return 0;
}