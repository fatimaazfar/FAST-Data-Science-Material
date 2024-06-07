#include"BulkItem.h"

BulkItem::BulkItem(string nam, float pric, int day, int month, int year, string descrip, bool set): description(descrip),isPartOfset(set)
{
	name = nam;
	price = pric;
	currentprice = pric;
	entryDate.setday(day);
	entryDate.setmonth(month);
	entryDate.setyear(year);
	if (!isPartOfset)
	{
		Permanent::checkAge(entryDate);
	}
}

void BulkItem::print()
{
	Permanent::print();
	cout << "Description : " << description << endl;
	cout << "It is part of a set : " << isPartOfset << endl;
}
