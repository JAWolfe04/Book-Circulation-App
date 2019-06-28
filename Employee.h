#pragma once
#include <string>

using namespace std;

// Manages employee name, book waiting time and retention time
class Employee
{
private:
    string EmployeeName; // Name of the employee
    int WaitingTime; // Days the employee waited to get a book since circulation began
    int RetainingTime; // Days the employee retained books

public:
    // Default constructor sets to empty name and 
    // both waiting and retaining times to 0
    Employee() : EmployeeName(""), WaitingTime(0), RetainingTime(0) { }

    inline void setName(string name) { EmployeeName = name; }
    inline void setWaitTime(int wtime) { WaitingTime = wtime; }
    inline void setRetainingTime(int rtime) { RetainingTime = rtime; }

    inline string getName() { return EmployeeName; }
    inline int getWaitTime() { return WaitingTime; }
    inline int getRetainingTime() { return RetainingTime; }
    
    bool operator<(const Employee& lhs, const Employee& rhs)
	{
		return lhs.WaitingTime < rhs.WaitingTime;
	}
	bool operator>(const Employee& lhs, const Employee& rhs)
	{
		return lhs.WaitingTime > rhs.WaitingTime;
	}
	bool operator>=(const Employee& lhs, const Employee& rhs)
	{
		return lhs.WaitingTime >= rhs.WaitingTime;
	}
	bool operator<=(const Employee& lhs, const Employee& rhs)
	{
		return lhs.WaitingTime <= rhs.WaitingTime;
	}
    
};
