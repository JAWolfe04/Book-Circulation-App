#include "Library.h"
#include "Book.h"
#include "Employee.h"

#include <string>
#include <list>

void Library::add_book(std::string book_name)
{
    circulated_books.push_back(Book(book_name));
}

void Library::add_employee(std::string employee_name)
{
    employees.push_back(Employee(employee_name));
}

Book* Library::get_book(std::string book_name)
{
    std::list<Book>::iterator itr = find(circulated_books.begin(), circulated_books.end(), book_name);

    if (itr == circulated_books.end())
        throw std::exception("No book of that name found");
    else
        return &(*itr);
}

Employee * Library::get_employee(Employee& employee)
{
    //TODO: Like the get_book function but for the employees list
    return nullptr;
}

void Library::circulate_book(std::string book_name, Date date)
{
    Book* book = get_book(book_name);
    book->set_start_date(date);
    book->set_last_passed_date(date);

    std::list<Employee>::iterator itr = employees.begin();
    for (itr; itr != employees.end(); ++itr)
        book->push_employee(*itr);
}

void Library::pass_on(std::string book_name, Date date)
{
    /*TODO: - Get book from name and set it as a variable, book
            - Use get_employee function with the front of the queue
              and set it as a variable, front_employee

            - Update book retaining time for front_employee by
              setting the retaining time to date - book->last_pass_date

            - Pop off the first item in the book queue using pop
            - Use update_employee for every book in circulated_books
              with front_employee

            - If the queue is now empty, set book->is_archived to true, 
              set book->end_date to date, remove book from circulated_books
              and add to archived_books then return

            - Set the front_employee again using the same method as before
            - Update book waiting time for front_employee by
              setting the waiting time to date - book->start_date
            - Use update_employee for every book in circulated_books
              with front_employee again
    */
}
