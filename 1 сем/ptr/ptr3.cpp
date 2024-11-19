#include <iostream>
using namespace std;
int main() {
	float a, b, c;
	float* aptr;
	float* bptr;
	cin >> a;
	aptr = &a;

	cin >> b;
	bptr = &b;
	c = *aptr + *bptr;
	cout << c << endl;
	return 0;
}