#pragma once

#include <string>
using namespace std;

class book
{
private:
	bool is_archived;
	string StartDate;
	string EndDate;

public:
	book() : is_archived(true), StartDate(""), EndDate("") { }

	inline void setStartDate(string sDate) { StartDate = sDate; }
	inline void setEndDate(string eDate) { EndDate = eDate; }

	//bool Is_Archived(string book);

	inline string getEndDate() { return EndDate; }
	inline string getStartDate() { return StartDate; }
	inline bool Is_Archived(string book) { return is_archived; }

};


