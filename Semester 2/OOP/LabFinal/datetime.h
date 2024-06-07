#pragma once
#include<time.h>
#include<iostream>
using namespace std;
class myDate
{
	int d;
	int m;
	int y;

public:
	myDate(int d = 0, int m = 0, int y = 0)
	{
		this->d = d;
		this->m = m;
		this->y = y;
	}

	int operator-(const myDate& d1)
	{
		int diff = 0;
		diff = (y - d1.y) * 365;
		diff = diff + (m - d1.m) * 30;
		diff = diff + (d - d1.d);
		return diff;
	}

	friend ostream& operator <<(ostream& out, const myDate& d)
	{
		out << d.d << "-" << d.m << "-" << d.y;
		return out;
	}

	void setDate(int d, int m, int y)
	{
		this->d = d;
		this->m = m;
		this->y = y;
	}

	int getday()
	{
		return d;
	}

	int getmonth()
	{
		return m;
	}

	int getyear()
	{
		return y;
	}
};



class MyTime
{
private:
	int hour;
	int minute;
	int second;
public:
	//constructor with default value 0
	MyTime(int h = 0, int m = 0, int s = 0);
	//setter function 
	void setTime(int h, int m, int s);
	//print description of object in hh:mm:ss
	friend ostream& operator <<(ostream& out, const MyTime& t);
	//compare two time object
	bool operator == (const MyTime);
	int gethour();
	int getminute();
	int getsecond();
};

MyTime::MyTime(int h, int m, int s)
{
	hour = h;
	minute = m;
	second = s;
}

void MyTime::setTime(int h, int m, int s)
{
	hour = h;
	minute = m;
	second = s;
}

ostream& operator <<(ostream& out, const MyTime& t)
{
	cout << t.hour << ":" << t.minute << ":" << t.second << "\n";
	return out;
}

bool MyTime :: operator == (const MyTime otherTime)
{
	if (hour == otherTime.hour &&
		minute == otherTime.minute &&
		second == otherTime.second)
		return true;
	else
		return false;
}

int MyTime::gethour()
{
	return hour;
}
int MyTime::getminute()
{
	return minute;
}
int MyTime::getsecond()
{
	return second;
}




//Global Date Function 
myDate CurrentDate()
{
	//If Function localtime() gives error, comment option 1 and use option 2

//-------------------------------Option 1 -------------------------------------------
	time_t now = time(0);
	struct tm* newtime = localtime(&now);
	int curry = newtime->tm_year + 1900;
	int currm = newtime->tm_mon + 1;
	int currd = newtime->tm_mday;
	myDate d(currd, currm, curry);
	return d;

	//-------------------------------Option 2 -------------------------------------------
		//time_t now = time(0);
		//struct tm newtime;
		//localtime_s(&newtime,&now);
		//int curry = newtime.tm_year + 1900; 
		//int currm = newtime.tm_mon + 1;
		//int currd = newtime.tm_mday; 
		//myDate d(currd, currm, curry); 
		//return d;
}

