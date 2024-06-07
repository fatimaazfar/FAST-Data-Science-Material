#include"Perishable.h"

Perishable::Perishable(string nam, float pric, int day, int month, int year, int quant) :quantity(quant)
{
	name = nam;
	price = pric;
	currentprice = pric;
	expiry.setday(day);
	expiry.setmonth(month);
	expiry.setyear(year);
	expired(expiry);
}

void Perishable::print()
{
	Items::print();
	cout << "Expiry date : " << expiry << endl;
	cout << "Quantity : " << quantity << endl;
}

void Perishable::expired(Date& expiry)
{
	//check expiry
	Date temp;
	temp = Items::getcurrentdate();
	if (expiry.getyear() < temp.getyear())
		currentprice = 0;
	else if (expiry.getmonth() < temp.getmonth())
		currentprice = 0;
	else if (expiry.getday() < temp.getday())
		currentprice = 0;
}
