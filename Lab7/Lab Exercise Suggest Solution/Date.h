#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <sstream>

using namespace std;

class Date {
private:
	int day;
	int month;
	int year;
	string* monthNames;
	int* monthDays;

public:
	void setDay(int dd);		// Set day (min 1, max 28-31, depend on month setting, if input error, default = 1)
	void setMonth(int mm);		// Set month (1-12, if input error, default = 1)
	void setYear(int yyyy);		// Set year (1900-2100, if input error, default = 1900)

	void initialize();			// Initialize the month name and days of month.
	
	bool leapYear();			// Return true if it is leap year.
	int daysInMonth();			// return days of month.
	string toMonthDayYear();	// Convert to MM/DD/YYYY format. (e.g. 3/28/2010)
	string toMonthNameDate();	// Convert to MMMM DD, YYYY format. (e.g. March 28, 2010)

	void convertFromMonthName(string monthName);	// Convert engligh month name to int month number.
};

#endif