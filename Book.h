#pragma once
#include "PriorityQueue.h"
#include "Date.h"
#include "Employee.h"

#include <string>

// Manages book name, archive status, circulation start date, circulation end date and employee queue
// All methods O(1) unless specified
class Book
{
private:
    std::string bookName; // Book name
    bool isArchived; // Whether book has been archived
    Date startDate; // Date the book begain circulating
    Date lastPassedDate; // Date the book was last passed to another employee
    Date endDate; // Date book was removed from circulation
    priorityQueue<Employee*> employeeQueue; // Queue of employees waiting for the book

public:
    // Default constructor sets a blank name and sets the book to not archived
    Book() : bookName(""), isArchived(false) { }
    // Creates a book of the given name and sets the book to not archived
    Book(std::string& book_name) : bookName(book_name), isArchived(false) { }

    //Setters for book name, start date, date that the book was last passed, and end date

    inline void setBookName(std::string& bookName) { this->bookName = bookName; }
    inline void setStartDate(Date& startDate) { this->startDate = startDate; }
    inline void setLastPassedDate(Date& passDate) { this->lastPassedDate = passDate; }
    inline void setEndDate(Date& endDate) { this->endDate = endDate; }

    //Used in the process of archiving the book - sets the archive variable to true
    inline void archive() { this->isArchived = true; }

    //Getters for book name, start date, date that the book was last passed, and end date

    inline std::string& getBookName() { return bookName; }
    inline Date& getEndDate() { return endDate; }
    inline Date& getLastPassDate() { return lastPassedDate; }
    inline Date& getStartDate() { return startDate; }

    //Returns whether the book is archived currently
    inline bool isBookArchived() { return isArchived; }

    // Determines whether the book's name is equal to a given string
    inline bool operator==(std::string name) { return bookName == name; }

    // Determines whether 2 Books are the same book by comparing names
    // Assumes every book has a unique name
    friend bool operator==(const Book& lhs, const Book& rhs) { return lhs.bookName == rhs.bookName; }

    // Adds an employee to the book queue
    // O(n) because of priority queue push
    void pushEmployee(Employee& employee) { employeeQueue.push(&employee); }
    // Removes the employee at the front of the book queue
    // O(1) because of priority queue pop
    void popEmployee() { employeeQueue.pop(); }
    // Returns the employee at the front of the book queue
    // O(1)because of priority queue front
    Employee* frontEmployee() { return employeeQueue.front(); }
    // Returns whether the book queue is empty
    //O(1) because of priority queue isEmpty
    bool isEmpty() { return (employeeQueue.isEmpty()); }
};
