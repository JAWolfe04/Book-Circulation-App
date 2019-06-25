#pragma once

#include <string>
using namespace std;

class book
{
private:
	string BookName;
	bool is_archived;
	string StartDate;
	string EndDate;

public:
	book() : BookName(""), is_archived(true), StartDate(""), EndDate("") { }

	inline void setBookName(string bookname) { BookName = BookName;  }
	inline void setStartDate(string sDate) { StartDate = sDate; }
	inline void setEndDate(string eDate) { EndDate = eDate; }

	//bool Is_Archived(string book);

	inline string getBookName() { return BookName; }
	inline string getEndDate() { return EndDate; }
	inline string getStartDate() { return StartDate; }
	inline bool Is_Archived(string book) { return is_archived; }

};

