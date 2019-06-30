#pragma once
#include <string>

// Manages employee name, book waiting time and retention time
// All methods are O(1)
class Employee
{
private:
    std::string employeeName; // Name of the employee
    int waitingTime; // Days the employee waited to get a book since circulation began
    int retainingTime; // Days the employee retained books

public:
    // Default constructor sets to empty name and initializes both waiting and retaining times to 0
    Employee() : employeeName(""), waitingTime(0), retainingTime(0) { }

    // Creates a new employee with the given name and initializes both waiting and retaining times to 0
    Employee(std::string employeeName) : employeeName(employeeName), waitingTime(0), retainingTime(0) {}

    // Setters for employee name, wait time, and retaining time

    inline void setName(std::string name) { employeeName = name; }
    inline void setWaitTime(int wTime) { waitingTime = wTime; }
    inline void setRetainingTime(int rTime) { retainingTime = rTime; }

    // Getters for employee name, wait time, and retaining time

    inline std::string getName() { return employeeName; }
    inline int getWaitTime() { return waitingTime; }
    inline int getRetainingTime() { return retainingTime; }

    // Compares 2 employees by comparing the time they have been waiting for a book
    // versus the time they have retained a book
    bool operator<(const Employee& rhs) const {
        return (waitingTime - retainingTime) < (rhs.waitingTime - rhs.retainingTime);
    }

    // Compares 2 employees by comparing the time they have been waiting for a book
    // versus the time they have retained a book
    bool operator>(const Employee& rhs) const {
        return (waitingTime - retainingTime) > (rhs.waitingTime - rhs.retainingTime);
    }

    // Determines whether 2 Employees are the same; assumes every employee has a unique name
    bool operator==(const Employee& rhs) const { return employeeName == rhs.employeeName; }
};
