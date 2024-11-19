#include <iostream>
using namespace std;
int main() {
	setlocale(LC_ALL, "rus");
	unsigned int N, c=1;
	unsigned int *f=&c;

	cout << "введите число :" << endl;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		*f *= i;
	}
	cout<<"факториал числа " << N <<" равен "<< *f<<endl;
	return 0;
}