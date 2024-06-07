#pragma once
#include<iostream>
using namespace std;

class date
{
	int day;
	int month;
	int year;
public:
	date(int = 0, int = 0, int = 0);
	date(const date&);
	void setday(int);
	void setmonth(int);
	void setyear(int);
	int getday();
	int getmonth();
	int getyear();
	friend ostream& operator << (ostream&, date&);
};
