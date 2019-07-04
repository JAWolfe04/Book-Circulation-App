#pragma once
#include "Date.h"
#include "Book.h"
#include "Employee.h"

#include <list>
#include <string>

// Manages books in circulation, archived books and employees in the system
class Library
{
private:
    std::list<Book> circulatedBooks; // List of books in circulation
    std::list<Book> archivedBooks; // List of archived books
    std::list<Employee> employees; // List of employees in the library system

public:
    //Adds new book to the list of circulated books
    //Efficiency: O(n) (see priority queue)
    void addBook(std::string bookName);

    //Efficiency: O(n) (see priority queue)
    //Adds new employee to the employee list
    void addEmployee(std::string employeeName);

    //Searches the circulated book list for a book and returns a pointer to it if found
    //Efficiency: O(n) (the iterator goes through n books to find the book)
    Book* getBook(std::string bookName);

    //Puts book in circulation by setting the start date and adding all employees to the book's queue
    //Efficiency: O(n)
    void circulateBook(std::string bookName, Date date);

    //Passes book from one employee to the next
    //Efficiency: O(n)
    void passOn(std::string bookName, Date date);
};