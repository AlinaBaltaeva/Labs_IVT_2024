#pragma once
#include <iostream>
#include <string>
using namespace std;

class Book
{
	string nameBook;
	string author;
	unsigned int year;
public:
	Book();
	Book(string, string, int);
	Book(const Book&);
	~Book();
	string get_nameBook();
	void set_nameBook(string);
	string get_author();
	void set_author(string);
	int get_year();
	void set_year(int);
	void show();
};