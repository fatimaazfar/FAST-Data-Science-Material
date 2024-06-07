#pragma once
#include<iostream>
using namespace std;

class Date
{
	int day;
	int month;
	int year;
public:
	Date(int = 0, int = 0, int = 0);
	Date(const Date&);
	void setday(int);
	void setmonth(int);
	void setyear(int);
	int getday();
	int getmonth();
	int getyear();
	friend ostream& operator << (ostream&, Date&);
};

