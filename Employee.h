#pragma once
#include <iostream>
#include <string>

using namespace std;
class Employee
{
private:
	string EmployeeName;
	int WaitingTime;
	int RetainingTime;

public:
	Employee();

	void setName(string name){ EmployeeName = name; }      //inline getters and setters
	void setWaitTime(int wtime) {	WaitingTime = wtime;}
	void setRetainingTime(int rtime) { RetainingTime = rtime; }

	string getName() { return EmployeeName; }
	int getWaitTime() { return WaitingTime; }
	int getRetainingTime() { return RetainingTime; }

	~Employee();

};
