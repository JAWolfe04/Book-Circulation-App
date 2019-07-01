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
    void addBook(std::string bookName);
    void addEmployee(std::string employeeName);

    Book* getBook(std::string bookName);
    Employee* getEmployee(Employee& employee);
    void circulateBook(std::string bookName, Date date);
    void passOn(std::string bookName, Date date);
};