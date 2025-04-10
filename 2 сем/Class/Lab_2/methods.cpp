#include <iostream>
#include <string>
#include "Book.h"

using namespace std;

Book::Book() {
	nameBook = "";
	author = "";
	year = 0;

	cout << "Parameterless constructor" << this << endl;
}

Book::Book(string name, string Author, int Year) {
	nameBook = name;
	author = Author;
	year = Year;

	cout << "Constructor with parameters" << this << endl;
}

Book::Book(const Book& temp) {
	nameBook= temp.nameBook;
	author = temp.author;
	year = temp.year;

	cout << "Copy constructor" << this << endl;
}

Book::~Book() {
	cout << "Destructor" << this << endl;
}

string Book::get_nameBook() {
	return nameBook;
}

string Book::get_author() {
	return author;
}

int Book::get_year() {
	return year;
}

void Book::set_nameBook(string name) {
	nameBook = name;
}

void Book::set_author(string Author) {
	author = Author;
}

void Book::set_year(int Year) {
	year = Year;
}

void Book::show() {
	cout << "Name book: " << nameBook << endl;
	cout << "The book author: " << author << endl;
	cout << "The boot year: " << year << endl;
}
