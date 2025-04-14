#include "Object.h"
#include <iostream>
#include "Rect.h"
#include "Vector.h"
#include "Pair.h"

using namespace std;

int main()
{
	Pair example;

	cin >> example;
	cout << example << endl;

	Object* p;
	p = &example;
	p->Show();

	Rect example2;

	cin >> example2;
	cout << example2 << endl;

	p = &example2;
	p->Show();

	Vector v(5);
	Pair  a;
	Rect b;

	cin >> a >> b;
	p = &a;
	v.Add(p);
	p = &b;
	v.Add(p);
	cout << v;
	cout << "Площадь прямоугольника : " << endl;
	cout << example2.Sq() << endl;
	cout << "Периметр прямоугольника : " << endl;
	cout << example2.Per() << endl;
	return 0;
}