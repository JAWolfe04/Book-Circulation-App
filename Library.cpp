#include "Library.h"
#include "Book.h"
#include "Employee.h"

#include <string>
#include <list>

void Library::addBook(std::string bookName)
{
    circulatedBooks.push_back(Book(bookName));
}

void Library::addEmployee(std::string employeeName)
{
    employees.push_back(Employee(employeeName));
}

Book* Library::getBook(std::string bookName)
{
    // Searches through books in the library to find the first book with the matching name
    std::list<Book>::iterator itr = find(circulatedBooks.begin(), circulatedBooks.end(), bookName);

    // In the event, no book was found return an error
    if (itr == circulatedBooks.end())
        throw std::exception("No book of that name found");
    // Otherwise return the found book
    else
        return &(*itr);
}

void Library::circulateBook(std::string book_name, Date date)
{
    // Get book with given name and set its circulation
    // start date and last passed on date to the given date
    Book* book = getBook(book_name);
    book->setStartDate(date);
    book->setLastPassedDate(date);

    // Add all employees in the library system to the book queue
    std::list<Employee>::iterator itr = employees.begin();
    for (itr; itr != employees.end(); ++itr)
        book->pushEmployee(*itr);
}

void Library::passOn(std::string book_name, Date date)
{
    // Get book with given name
    Book* book = getBook(book_name);

    // Get employee in the front of the queue and remove them from the queue
    Employee* front = book->frontEmployee();
    book->popEmployee();

    // Update retaining time for employee who last had book
    front->setRetainingTime((date - book->getLastPassDate()) + front->getRetainingTime());
    book->setLastPassedDate(date);

    // If book's queue is empty, archive the book and exit
    if (book->isEmpty()) {
        book->archive();
        book->setEndDate(date);
        archivedBooks.push_back(*book);
        circulatedBooks.remove(*book);
        return;
    }

    // Update next front employee's wait time
    front = book->frontEmployee();
    front->setWaitTime((date - book->getStartDate()) + front->getWaitTime());
}
