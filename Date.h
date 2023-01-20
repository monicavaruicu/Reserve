#pragma once
#include <string>

class Date
{
public:
	Date();
	Date(std::string myDay, std::string myMonth, std::string myYear);
	~Date();
	void printDate();
	bool verifyDayMonth(int, int, int);
	bool isLeapYear(int);

private:
	std::string day;
	std::string month;
	std::string year;
};

