#include "date.h"
#include<iostream>
using namespace std;

date::date(int d, int m, int y) : day(d), month(m), year(y)
{
	if (d < 0 && d > 31 && m < 0 && m > 12 && y < 1900)
	{
		cout << "Invalid date enetered." << endl;
	}
	//overload constructor
}

date::date(const date& d)
{
	day = d.day;
	month = d.month;
	year = d.year;
}

void date::setday(int d)
{
	day = d;
}

void date::setmonth(int m)
{
	month = m;
}

void date::setyear(int y)
{
	year = y;
}

int date::getday()
{
	return day;
}

int date::getmonth()
{
	return month;
}

int date::getyear()
{
	return year;
}

ostream& operator << (ostream& out, date& d)
{
	out << d.getday() << "/" << d.getmonth() << "/" << d.getyear() << endl;
	return out;
}