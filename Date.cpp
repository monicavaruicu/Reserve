#include "Date.h"
#include <iostream>
#include <chrono>

Date::Date()
{
	day = "00";
	month = "00";
	year = "0000";
}

Date::Date(std::string myDay, std::string myMonth, std::string myYear)
{
	time_t now = time(0);
	int thisYear = 1970 + now / 31556926;

	int iDay = stoi(myDay);
	int iMonth = stoi(myMonth);
	int iYear = stoi(myYear);

	if (myDay.size() == 0 || myMonth.size() == 0 || myYear.size() == 0)
	{
		std::cout << "Incorrect date!";
		exit(1);
	}

	if (iYear > thisYear)
	{
		std::cout << "Incorrect date!";
		exit(1);
	}

	if ((iDay < 1 || iDay > 31))
	{
		std::cout << "Incorrect date!";
		exit(1);
	}

	if (iMonth < 1 || iMonth > 12)
	{
		std::cout << "Incorrect date!";
		exit(1);
	}

	if (verifyDayMonth(iDay, iMonth, iYear) == false)
	{
		std::cout << "Incorrect date!";
		exit(1);
	}

	if (stoi(myDay) < 10 && myDay.size() == 1)
		day = "0" + myDay;
	else
		day = myDay;

	if (stoi(myMonth) < 10 && myMonth.size() == 1)
		month = "0" + myMonth;
	else
		month = myMonth;

	year = myYear;
}

Date::~Date()
{
}

void Date::printDate()
{
	std::cout << day << "/" << month << "/" << year << "\n";
}

bool Date::verifyDayMonth(int myDay, int myMonth, int myYear)
{
	if (myMonth == 4 || myMonth == 6 || myMonth == 9 || myMonth == 11)
		return (myDay <= 30);

	if (myMonth == 2 && !isLeapYear(myYear))
		return (myDay <= 28);

	if (myMonth == 2 && isLeapYear(myYear))
		return (myDay <= 29);
}

bool Date::isLeapYear(int myYear)
{
	if (!(myYear % 4) && myYear % 100 || myYear % 400 == 0)
		return true;

	return false;
}