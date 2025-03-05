﻿//1) Скопировать в файл F2 только те строки из F1,  
// которые начинаются с буквы «А».
//2) Подсчитать количество слов в F2

#include <iostream>
#include <cstdio>
#include <fstream>
#include <string>
#include <string.h>
#include <cstdlib>
using namespace std;

int main()
{
	string str;
	ifstream myf1("F1.txt");
	fstream myf2("F2.txt");
	if (!myf1.is_open())
	{
		cout << "error" << endl;
	}
	if (!myf2.is_open())
	{
		cout << "error" << endl;
	}

	while (getline(myf1, str))
	{
		if (str[0] == 'A')
		{
			myf2 << str << endl;
		}
	}
	myf1.close();
	myf2.close();
	string ch;
	ifstream myf("F2.txt");

	int k = 0;
	while (getline(myf, ch))
	{
		k++;
	}
	myf.close();
	

	cout << k << endl;
	return 0;
}
