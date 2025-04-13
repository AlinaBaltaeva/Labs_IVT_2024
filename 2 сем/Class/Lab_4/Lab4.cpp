#include <iostream>
#include "Header.h"
#include "Rect.h"

using namespace std;


int main() {
	setlocale(LC_ALL, "rus");
	Pair num0;
	cin >> num0;
	cout << num0;
	Pair num1(1, 4);
	cout << num1;

	num0 = num1;
	cout << num0;

	Rect rect;
	cin >> rect;
	cout << rect << endl;
	cout << "Площадь прямоугольника равна: " << endl;
	cout << rect.Sq() << endl;
	cout << "периметр прямоугольника равна: " << endl;
	cout << rect.Per() << endl;
	return 0;
}
