#include <iostream>
using namespace std;
int main() {
	int a, b, c;
	int* aptr;
	int* bptr;

	cin >> a;
	aptr=&a;
	c=*aptr;
	
	cin >> b;
	bptr=&b;
	
	*aptr=*bptr;
	*bptr=c;
	cout<< *aptr <<endl;
	cout<< *bptr <<endl;
	return 0;

}
