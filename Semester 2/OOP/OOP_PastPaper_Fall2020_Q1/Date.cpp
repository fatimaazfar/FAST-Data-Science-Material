#include "Date.h"
#include<iostream>
using namespace std;

Date::Date(int d, int m, int y) : day(d), month(m), year(y)
{
	if (d < 0 && d > 31 && m < 0 && m > 12 && y < 1900)
	{
		cout << "Invalid date enetered." << endl;
	}
	//overload constructor
}

Date::Date(const Date& d)
{
	day = d.day;
	month = d.month;
	year = d.year;
}

void Date::setday(int d)
{
	day = d;
}

void Date::setmonth(int m)
{
	month = m;
}

void Date::setyear(int y)
{
	year = y;
}

int Date::getday()
{
	return day;
}

int Date::getmonth()
{
	return month;
}

int Date::getyear()
{
	return year;
}

ostream& operator << (ostream& out, Date& d)
{
	out << d.getday() << "/" << d.getmonth() << "/" << d.getyear();
	return out;
}