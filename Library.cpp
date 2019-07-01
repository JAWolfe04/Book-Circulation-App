#include "Library.h"
#include "Book.h"
#include "Employee.h"

#include <string>
#include <list>

//Adds new book to the list of circulated books
//Efficiency: O(n) (see priority queue)
void Library::addBook(std::string bookName)
{
    circulatedBooks.push_back(Book(bookName));
}

//Efficiency: O(n) (see priority queue)
//Adds new employee to the employee list
void Library::addEmployee(std::string employeeName)
{
    employees.push_back(Employee(employeeName));
}

//Searches the circulated book list for a book and returns a pointer to it if found
//Efficiency: O(n) (the iterator goes through n books to find the book)
Book* Library::getBook(std::string bookName)
{
    std::list<Book>::iterator itr = find(circulatedBooks.begin(), circulatedBooks.end(), bookName);

    if (itr == circulatedBooks.end())
        throw std::exception("No book of that name found");
    else
        return &(*itr);
}

//Puts book in circulation by setting the start date and adding all employees to the book's queue
//Efficiency: O(n)
void Library::circulateBook(std::string book_name, Date date)
{
    Book* book = getBook(book_name);
    book->setStartDate(date);
    book->setLastPassedDate(date);

    std::list<Employee>::iterator itr = employees.begin();
    for (itr; itr != employees.end(); ++itr)
        book->pushEmployee(*itr);
}

//Passes book from one employee to the next
//Efficiency: O(n)
void Library::passOn(std::string book_name, Date date)
{
    Book* book = getBook(book_name);
    Employee* front = book->frontEmployee();
    book->popEmployee();

    //update retaining time for employee who last had book
    front->setRetainingTime((date - book->getLastPassDate()) + front->getRetainingTime());
    book->setLastPassedDate(date);

    //if book's queue is empty, archive the book and exit
    if (book->isEmpty()) {
        book->archive();
        book->setEndDate(date);
        archivedBooks.push_back(*book);
        circulatedBooks.remove(*book);
        return;
    }

    //Set new front employee's wait time and update in each book
    front = book->frontEmployee();
    front->setWaitTime((date - book->getStartDate()) + front->getWaitTime());
}
