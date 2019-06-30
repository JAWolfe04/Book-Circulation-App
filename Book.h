#pragma once

#include "PriorityQueue.h"
#include "Date.h"
#include "Employee.h"

#include <string>

class Book
{
private:
    std::string book_name;
    bool is_archived;
    Date start_date;
    Date last_passed_date;
    Date end_date;
    priority_queue<Employee> employee_queue;

public:
    Book() : book_name(""), is_archived(false) { }
    Book(string& book_name) : book_name(book_name), is_archived(false) { }

    //Setters for book name, start date, date that the book was last passed, and end date
    inline void set_book_name(std::string& book_name) { this->book_name = book_name; }
    inline void set_start_date(Date& start_date) { this->start_date = start_date; }
    inline void set_last_passed_date(Date& pass_date) { this->last_passed_date = pass_date; }
    inline void set_end_date(Date& end_date) { this->end_date = end_date; }

    //Used in the process of archiving the book - sets the archive variable to true
    inline void archive() { this->is_archived = true; }

    //Getters for book name, start date, date that the book was last passed, and end date
    inline std::string& get_book_name() { return book_name; }
    inline Date& get_end_date() { return end_date; }
    inline Date& get_last_pass_date() { return last_passed_date; }
    inline Date& get_start_date() { return start_date; }

    //Returns whether the book is archived currently
    inline bool is_book_archived() { return is_archived; }

    //overloaded equality operator, determines whether the book's name is equal to a given string
    inline bool operator==(std::string name) { return book_name == name; }
    friend bool operator==(const Book& lhs, const Book& rhs) { return lhs.book_name == rhs.book_name; }

    //Priority queue functions used on the employee queue
    void push_employee(Employee& employee) { employee_queue.push(employee); }
    void pop_employee() { employee_queue.pop(); }
    void update_employee(Employee& employee) { employee_queue.update_item(employee); }
    Employee front_employee() { return employee_queue.front(); }
    bool is_empty() { return (employee_queue.isEmpty()); }

};
