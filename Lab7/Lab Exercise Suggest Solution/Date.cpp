#include "Date.h"

using namespace std;

void Date::initialize() {
	// initialze month name.
	monthNames = new string[12];
	string Months[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
	for (int i = 0; i < 12; i++)
		monthNames[i] = Months[i];

	// initialze month day.
	monthDays = new int[12];
	int Days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	for (int i = 0; i < 12; i++)
		monthDays[i] = Days[i];
}

bool Date::leapYear() {
	// check leap year.
	if ((year % 400 == 0) || ((year % 4 == 0) && (year % 100 != 0)))
		return true;
	else
		return false;
}

int Date::daysInMonth() {
	// if month = 2, check leapyear.
	if (month == 2)
		if (leapYear())
			return (monthDays[month-1]) + 1;
	// if month != 2, return days.
	return monthDays[month-1];
}

void Date::setDay(int dd) {
	// Set day.
	day = ((dd > 0 ) && (dd <= daysInMonth()))?dd:1;
}
void Date::setMonth(int mm) {
	// Set month.
	month = ((mm > 0) && (mm < 13))?mm:1;
}
void Date::setYear(int yyyy) {
	// Set year.
	year = ((yyyy >= 1900) && (yyyy <= 2100))?yyyy:1900;
}
string Date::toMonthDayYear() {
	stringstream result;
	result << month << "/" << day << "/" << year;
	return result.str();
}
string Date::toMonthNameDate() {
	stringstream result;
	result << monthNames[month-1] << " " << day << ", " << year;
	return result.str();
}
void Date::convertFromMonthName(string monthName) {
	//default month = 1.
	month = 1;
	//check if any match.
	for(int i = 0; i < 12; i++)
		if (monthNames[i] == monthName)
			month = i+1;
}