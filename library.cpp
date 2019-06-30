#include "Library.h"
#include "Book.h"
#include "Employee.h"

#include <string>
#include <list>

//Adds new book to the list of circulated books
//Efficiency: O(n) (see priority queue)
void Library::add_book(std::string book_name)
{
	circulated_books.push_back(Book(book_name));
}

//Efficiency: O(n) (see priority queue)
//Adds new employee to the employee list
void Library::add_employee(std::string employee_name)
{
	employees.push_back(Employee(employee_name));
}

//Searches the circulated book list for a book and returns a pointer to it if found
//Efficiency: O(n) (the iterator goes through n books to find the book)
Book* Library::get_book(std::string book_name)
{
	std::list<Book>::iterator itr = find(circulated_books.begin(), circulated_books.end(), book_name);

	if (itr == circulated_books.end())
		throw std::exception("No book of that name found");
	else
		return &(*itr);
}

//Searches the employee list for an employee and returns a pointer to it if found
//Efficiency: O(n) (the iterator goes through n employees to find the employee)
Employee* Library::get_employee(Employee& employee)
{
	std::list<Employee>::iterator itr = find(employees.begin(), employees.end(), employee);

	if (itr == employees.end())
		throw std::exception("No employee of that name found");
	else
		return &(*itr);
}

//Puts book in circulation by setting the start date and adding all employees to the book's queue
//Efficiency: O(n)
void Library::circulate_book(std::string book_name, Date date)
{
	Book* book = get_book(book_name);
	book->set_start_date(date);
	book->set_last_passed_date(date);

	std::list<Employee>::iterator itr = employees.begin();
	for (itr; itr != employees.end(); ++itr)
		book->push_employee(*itr);
}

//Passes book from one employee to the next
//Efficiency: O(n)
void Library::pass_on(std::string book_name, Date date)
{

	Book* book = get_book(book_name);
	Employee front = book->front_employee();
	Employee* front_employee = get_employee(front);
	front_employee->setRetainingTime(date - book->get_last_pass_date()); //update retaining time for employee who last had book
	book->pop_employee();

	//update employee's retaining time in each book's queue
	for (std::list<Book>::iterator itr = circulated_books.begin(); itr != circulated_books.end(); itr++) {
		itr->update_employee(*front_employee);
	}

	//if book's queue is empty, archive the book and exit
	if (book->is_empty()) {
		book->archive();
		book->set_end_date(date);
		circulated_books.remove(*book);
		archived_books.push_back(*book);
		return;
	}

	//Set new front employee's wait time and update in each book
	Employee front2 = book->front_employee();
	Employee* front_employee2 = get_employee(front);
	front_employee2->setWaitTime(date - book->get_start_date());
	for (std::list<Book>::iterator itr = circulated_books.begin(); itr != circulated_books.end(); itr++) {
		itr->update_employee(*front_employee2);
	}
}
