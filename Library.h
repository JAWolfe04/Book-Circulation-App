#pragma once

#include "Date.h"
#include "Book.h"
#include "Employee.h"

#include <list>
#include <string>

class Library
{
private:
    std::list<Book> circulated_books;
    std::list<Book> archived_books;
    std::list<Employee> employees;

public:
    void add_book(std::string book_name);
    void add_employee(std::string employee_name);

    Book* get_book(std::string book_name);
    Employee* get_employee(Employee& employee);
    void circulate_book(std::string book_name, Date date);
    void pass_on(std::string book_name, Date date);
};

