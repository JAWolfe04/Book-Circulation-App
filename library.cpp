#include "library.h"
#include <iterator>
#include <algorithm>


void library::add_book(string bookname)
{
	Circulated_Book.push_back(book(bookname));
}

void library::add_employee(string employeename)
{
	Employees.push_back(Employee(employeename));
}

string library::getBook(string bookname)
{
	/*list<string>::iterator it;                              //i cant figure out how to get this to work

	it = std::find(Circulated_Book.begin(), book.end(), bookname);

	return *it;*/

	std::list<book>::iterator result = Circulated_Book.begin();
	while (true) {
		result = std::find_if(result, Circulated_Book.end(), std::bind2nd(BookNumber(), number));
		if (result == Circulated_Book.end())
			break;

	}
	return *result;
	
}

void library::circulate_book(string bookname, int date)
{
}

void library::pass_on(string bookname, int date)
{
}
