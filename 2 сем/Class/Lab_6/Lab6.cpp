#include <iostream>
#include "Vector.h"

using namespace std;

int main()
{
	Vector a(5);
	Vector b(5);
	cin >> a;
	cin>> b;
	Vector sum = a + b;
	cout << "\nSum: " << sum << endl;

	cout << "First element: " << *a.first() << endl;

	Iterator i = a.first();
	i=i+1;
	cout << "Second element: " << *i << endl;
	for (i = a.first(); i != a.last();++i)cout << *i <<" ";
	cout << endl;
	return 0;
}
