#pragma once
#include"Items.h"
#include"Date.h"

class Permanent: public Items
{
protected:
	int age;
	Date entryDate;
public:
	Permanent(string nam = "", float pric = 0.0, int day = 0, int month = 0, int year = 0);
	void print();
	void checkAge(Date& entry);
};