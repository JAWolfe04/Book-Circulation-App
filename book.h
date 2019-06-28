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

    inline void set_book_name(std::string& book_name) { this->book_name = book_name;  }
    inline void set_start_date(Date& start_date) { this->start_date = start_date; }
    inline void set_last_passed_date(Date& pass_date) { this->last_passed_date = pass_date; }
    inline void set_end_date(Date& end_date) { this->end_date = end_date; }

    inline std::string& get_book_name() { return book_name; }
    inline Date& get_end_date() { return end_date; }
    inline Date& get_last_pass_date() { return last_passed_date; }
    inline Date& get_start_date() { return start_date; }
    inline bool is_book_archived() { return is_archived; }
    inline bool operator==(std::string name) { return book_name == name; }
    void push_employee(Employee& employee) { employee_queue.push(employee); }
    void pop_employee() { employee_queue.pop(); }
    void update_employee(Employee& employee) { employee_queue.update_item(employee); }
};

