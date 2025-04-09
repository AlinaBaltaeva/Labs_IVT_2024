#include <iostream>
#include "Header.h"

using namespace std;

void Money::Init(int F, int S) 
{
	first = F;
	second = S;
}

void Money::Read()
{
	cout << "The bill(1, 2, 5, 10 ,50 , 100, 500, 1000, 5000):  ";
	cin >> first;
	cout << "Count the bill: ";
	cin >> second;
}
void Money::Show()
{
	cout << "The bill = " << first << endl;
	cout << "Summa the bill = " << second << endl;

}
int Money::sum() {
	return (first * second);
 }



