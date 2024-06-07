#include"Permanent.h"

Permanent::Permanent(string nam, float pric, int day, int month, int year): age(0)
{
	entryDate.setday(day);
	entryDate.setmonth(month);
	entryDate.setyear(year);
	name = nam;
	price = pric;
	currentprice = pric;
	checkAge(entryDate);
}

void Permanent::print()
{
	Items::print();
	cout << "Age : " << age << " days" << endl;
}

void Permanent::checkAge(Date& entry)
{
	//check age
	Date temp;
	int daysPassed = 0;
	temp = Items::getcurrentdate();
	if (entry.getyear() < temp.getyear())
		daysPassed += ((temp.getyear() - entry.getyear()) * 12 * 30);
	else if (entry.getmonth() < temp.getmonth())
		daysPassed += ((temp.getmonth() - entry.getmonth()) * 30);
	else if (entry.getday() < temp.getday())
		daysPassed += temp.getday() - entry.getday();
	age = daysPassed;
	for (int i = 0; i < age; i++)
	{
		currentprice -= (currentprice * (2 / 100));
	}
}
