#pragma once

#include <list>
#include "book.h"
#include "Employee.h"
class library
{
private:
	list<book> Circulated_Book;
	list<book> Archived_Books;
	list<Employee> Employees;

public:
	void add_book(string bookname);
	void add_employee(string employeename);

	string getBook(string bookname);
	void circulate_book(string bookname, int date);
	void pass_on(string bookname, int date);
	
};

