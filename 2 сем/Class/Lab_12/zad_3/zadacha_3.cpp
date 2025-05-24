#include "Container.h"
#include "Money.h"
#include <iostream>
using namespace std;


int main()
{
	int n;
	cout << "N: "; cin >> n;
	Container<Money> v(n);
	v.Print();
	cout << "Min: " << v.Min() << endl;
	cout << "Position: ";
	int pos; cin >> pos;
	v.Add_map(pos, v.Min());
	v.Print();
	cout << "Srednee: " << v.Srednee() << endl;
	v.Del();
	v.Print();
	cout << "Max: " << v.Max() << endl;
	v.Umn();
	v.Print();
	return 0;
}