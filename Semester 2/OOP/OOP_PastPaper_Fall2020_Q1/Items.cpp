#include"Items.h"
#include "Date.h"

void Items::print()
{
	cout << "Name : " << name << endl;
	cout << "Actual Price : " << price << endl;
	cout << "Current Price : " << currentprice << endl;
}

Date& Items::getcurrentdate()
{
	Date dat;
	struct tm newtime;
	time_t now = time(0);
	localtime_s(&newtime, &now);
	dat.setday(newtime.tm_mday);
	dat.setmonth(1 + newtime.tm_mon);
	dat.setyear(1900 + newtime.tm_year);
	return dat;
}
