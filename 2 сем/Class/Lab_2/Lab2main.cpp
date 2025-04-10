#include <iostream>
#include <string>
#include "Book.h"

using namespace std;

Book make_Book() {
	string Name;
	string Author;
	unsigned int Year;

	cout << "What name?";
	cin >> Name;

	cout << "Who author?";
	cin >> Author;

	cout << "What year?";
	cin >> Year;

	Book temp(Name, Author, Year);
	return temp;
}

void showBook(Book temp) {
	temp.show();
}

int main() {
	Book t1;
	t1.show();

	Book t2("Summer", "Elin X", 2022);
	t2.show();

	Book t3 = t2;
	t3.set_nameBook("Winter");
	t3.set_author("Hangry");
	t3.set_year(2000);

	showBook(t3);

	t1 = make_Book();
	t1.show();

	return 0;
}
