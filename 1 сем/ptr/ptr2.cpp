#include <iostream>
using namespace std;
int main() {
	int a, b, c;
	int* aptr;
	int* bptr;
	cin >> a;
	aptr = &a;

	cin >> b;
	bptr = &b;
	c = *aptr + *bptr;
	cout << c << endl;
	return 0;
}