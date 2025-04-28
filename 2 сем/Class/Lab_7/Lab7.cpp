#include <iostream>
#include "Time.h"
#include "Vector.h"
using namespace std;

int  main()
{
	setlocale(LC_ALL, "rus");
	system("chcp 1251");
	system("cls");
	Vector<int> A(5, 1);
	cout << "ВВедите 5 элементов первого вектора: " << endl;
	cin >> A;
	
	Vector<int> B(5, 1);
	cout << "ВВедите 5 элементов второго вектора: " << endl;
	cin >> B;
	
	Vector<int> sum = A + B;
	cout << "Sum: " << sum << endl;

	Time t;
	cout << "Time:  ";
	cin >> t;
	cout << t;
	
	int k;
	cout << " dop secunds: ";
	cin >> k;
	Time p;
	p = t + k;
	cout << p;
	return 0;
}