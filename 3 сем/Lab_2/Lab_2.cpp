#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
	setlocale(LC_ALL, "ru");
	const int n = 6;
	int a1[n][n] = {
		{1, 0, 1, 0, 0, 1},
		{0, 1, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 1},
		{0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0}
	};
	int a2[n][n] = {
		{1, 0, 1, 0, 0, 1},
		{0, 1, 0, 0, 0, 0},
		{1, 0, 1, 0, 0, 1},
		{0, 0, 0, 1, 0, 0},
		{0, 0, 0, 0, 1, 0},
		{1, 0, 1, 0, 0, 1}
	};
	int a3[n][n] = {
		{0, 0, 1, 0, 0, 1},
		{1, 0, 0, 0, 0, 0},
		{0, 1, 0, 0, 0, 1},
		{1, 1, 1, 0, 0, 0},
		{1, 1, 1, 1, 0, 0},
		{0, 1, 0, 1, 1, 0}
	};
	int a4[n][n] = {
		{0, 1, 1, 1, 1, 0},
		{0, 1, 1, 1, 1, 0},
		{0, 1, 1, 1, 1, 0},
		{0, 1, 1, 1, 1, 0},
		{0, 1, 1, 1, 1, 0},
		{0, 1, 1, 1, 1, 0}
	};
	int a5[n][n] = {
		{0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0},
		{1, 1, 1, 1, 1, 1},
		{1, 1, 1, 1, 1, 1},
		{0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0}
	};
	
	int a7[n][n] = {
		{1, 0, 1, 1, 1, 0},
		{1, 1, 1, 1, 1, 1},
		{0, 0, 1, 1, 1, 1},
		{0, 0, 0, 1, 1, 1},
		{0, 0, 0, 0, 1, 1},
		{1, 0, 0, 0, 0, 1}
	};
	int a8[n][n] = {
		{0, 1, 1, 1, 1, 1},
		{1, 0, 1, 1, 1, 1},
		{1, 1, 0, 1, 1, 1},
		{1, 1, 1, 0, 1, 1},
		{1, 1, 1, 1, 0, 1},
		{1, 1, 1, 1, 1, 0}
	};




	

	bool reflex = true;
	bool antireflex = true;
	bool symmet = true;
	bool antisymmet = true;
	bool asymmet = true;
	bool transit = true;
	bool connect = true;



	for (int i = 0; i < n; i++) {
		if (a[i][i] != 1) {
			reflex = false;
		}
		if (a[i][i] != 0) {
			antireflex = false;
		}
	}
	for (int i = 0; i < n; i++) {
		if (a[i][i] != 1) {
			reflex = false;
		}
		if (a[i][i] != 0) {
			antireflex = false;
		}
	}

	cout << "Свойства отношения:" << endl;
	if (reflex)
	{
		cout << "рефлексивность - да" << endl;
		cout << "антирефлексивность - нет" << endl;
	}
	else
	{
		cout << "антирефлексивность - да" << endl;
		cout << "рефлексивность - нет" << endl;
	}


	return 0;
}
