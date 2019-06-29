#pragma once
#include <string>

// Manages employee name, book waiting time and retention time
class Employee
{
private:
	std::string EmployeeName; // Name of the employee
	int WaitingTime; // Days the employee waited to get a book since circulation began
	int RetainingTime; // Days the employee retained books

public:
	// Default constructor sets to empty name and 
	// both waiting and retaining times to 0
	Employee() : EmployeeName(""), WaitingTime(0), RetainingTime(0) { }
	Employee(string employeename) : EmployeeName(employeename), WaitingTime(0), RetainingTime(0) {}

	//setters for employee name, wait time, and retaining time
	inline void setName(string name) { EmployeeName = name; }
	inline void setWaitTime(int wtime) { WaitingTime = wtime; }
	inline void setRetainingTime(int rtime) { RetainingTime = rtime; }

	//getters for employee name, wait time, and retaining time
	inline string getName() { return EmployeeName; }
	inline int getWaitTime() { return WaitingTime; }
	inline int getRetainingTime() { return RetainingTime; }

	//Overloaded less than and greater than operators, compare wait and retention times to determine priority
	bool operator<(const Employee& rhs) const {
		return (WaitingTime - RetainingTime) < (rhs.WaitingTime - rhs.RetainingTime);
	}
	bool operator>(const Employee& rhs) const {
		return (WaitingTime - RetainingTime) > (rhs.WaitingTime - rhs.RetainingTime);
	}

	//overloaded equality operator, determines whether the 2 employee names are the same
	bool operator==(const Employee& rhs) const {
		return EmployeeName == rhs.EmployeeName;
	}
};
