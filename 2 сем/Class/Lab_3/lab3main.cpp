#include <iostream>
#include "Time.h"

using namespace std;

int main() {
	Time A, B, C;
	cin >> A >> B;
	++A;

	cout << A << endl;
	C = (A++) + B;

	cout << "A = " << A << endl;
	cout << "B = " << B << endl;
	cout << "C = " << C << endl;
	return 0;
}
