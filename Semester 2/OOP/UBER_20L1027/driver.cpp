#include "driver.h"
#include "trip.h"

driver::driver(string nam, date DOB, string email, string phone, string license, string vehnum) : licensenum(license), vehiclenum(vehnum), user(nam, DOB, email, phone)
{
	count = 0;
}

void driver::pickARide(trip* t)
{
	if (t != nullptr)
	{
		if (t->getstatus() == 3 && t->getstatus() != 4)//if the trip status is looking for a ride
		{
			currenttrip = t;
			currenttrip->setdriver(this);
			currenttrip->setstatus(1);//the whole trip
			addTrip(currenttrip);
			cout << currenttrip->driverName() << " picked " << currenttrip->passName() << "'s ride." << endl;
		}
		else if (t->getstatus() != 3)
			cout << "This trip doesn't require a driver yet." << endl;
		else if (t->getstatus() == 4)
			cout << "The trip is already completed." << endl;
	}
}

void driver::endARide()
{
	if (currenttrip != nullptr)
	{
		cout << currenttrip->driverName() << " just ended " << currenttrip->passName() << "'s ride." << endl;
		currenttrip->setstatus(4);//the whole trip
		currenttrip->setPassCurrTrip(nullptr);
		currenttrip = nullptr;
	}
	else
		cout << "Cannot end ride because there is no current trip." << endl;
}

void driver::ratePassanger(trip* t, int r)
{
	if (t != nullptr && r > 0 && r < 6)
	{
		if (t->getstatus() == 4)
		{
			t->passengerrating = r;
		}
		else
			cout << "Ride not completed yet, you cannot rate." << endl;
	}
	else
		cout << "Rating can be from 1 to 5 only." << endl;
}

float driver::getAvgRating()
{
	int c = 0;
	for (int i = 0;i < count;i++)
	{
		if (trips[i]->getstatus() != 2)
		{
			rating += trips[i]->driverrating;
			c++;
		}
	}
	rating /= c;
	return rating;
}

ostream& operator<<(ostream& out, driver& d)
{
	if (&d != 0)
	{
		d.print();
		out << "Vehicle # : " << d.vehiclenum << endl;
		out << "License # : " << d.licensenum << endl;
		out << "Total trips : " << d.count << endl;
		if (d.currenttrip != nullptr)
		{
			if (d.currenttrip->getstatus() == 1)
				out << "The driver is driving currently." << endl;
			else if (d.currenttrip->getstatus() == 2)
				out << "The driver is idle." << endl;
			else if (d.currenttrip->getstatus() == 4)
				out << "The ride is completed." << endl;
		}
		else
			out << "The driver is idle." << endl;
	}
	return out;
}
