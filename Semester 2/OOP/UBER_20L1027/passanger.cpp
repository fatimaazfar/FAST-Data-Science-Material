#include"passanger.h"
#include"trip.h"
#include<iostream>
using namespace std;

passanger::passanger()
{
	//default constructor
}

passanger::passanger(string nam, date dat, string em, string phone, payment p) : user(nam, dat, em, phone)
{
	paynum = 0;
	addpaymethod(p);
}

void passanger::addpaymethod(payment& p)
{
	if (paynum == 3)
	{
		cout << "Sorry! You cannot add any more payment methods." << endl;
	}
	else if (paynum < 3)
	{
		int c = 0;
		for (int i = 0;i < 3;i++)
		{
			if (paymethods[i] == pTemp)
			{
				paymethods[i] = p;
				counter++;
				c++;
				break;
			}
		}
		if (c == 0)
		{
			paymethods[paynum++] = p;
			counter++;
		}
	}
}

void passanger::deletepaymethod(payment& p)
{
	for (int i = 0;i < 3;i++)
	{
		if (p == paymethods[i])
		{
			paymethods[i] = pTemp;
			counter--;
		}
	}
}

trip* passanger::bookRide(string pick, string drop)
{
	if (currenttrip == nullptr)
	{
		currenttrip = new trip;
		addTrip(currenttrip);
		currenttrip->setpassenger(this);
		currenttrip->setstatus(3);//3 means looking for driver
		currenttrip->setpickup(pick);
		currenttrip->setdropoff(drop);
		cout << currenttrip->passName() << " booked a ride." << endl;
	}
	else
	{
		cout << "You cannot book two rides at one time." << endl;
	}
	return currenttrip;
}

void passanger::cancelRide()
{
	if (currenttrip != nullptr)
	{
		cout << currenttrip->passName() << " cancelled the ride." << endl;
		currenttrip->setstatus(2);//2 means that the ride was cancelled
		if (currenttrip->getstatus() == 1)
			currenttrip->setDriverCurrTrip(nullptr);//in case the driver was alloted
		currenttrip = nullptr;
	}
	else if (currenttrip == nullptr)
		cout << "Cannot cancel ride as you are currently in no trip." << endl;
}

void passanger::rateDriver(trip* t, int r)
{
	if (t != nullptr && r > 0 && r < 6)
	{
		if (t->getstatus() == 4)
		{
			t->driverrating = r;
		}
		else
			cout << "Ride not completed yet, you cannot rate." << endl;
	}
	else
		cout << "Rating can be from 1 to 5 only." << endl;
}

float passanger::getAvgRating()
{
	int c = 0;
	for (int i = 0;i < count;i++)
	{
		if (trips[i]->getstatus() != 2)
		{
			rating += trips[i]->passengerrating;
			c++;
		}
	}
	rating /= c;
	return rating;
}

ostream& operator<<(ostream& out, passanger& p)
{
	if (&p != 0)
	{
		p.print();
		out << "Total trips : " << p.count << endl;
		out << "Payment method/s : " << endl;
		for (int i = 0;i < p.counter;i++)
		{
			out << p.paymethods[i];
		}
		if (p.currenttrip != nullptr)
		{
			if (p.currenttrip->getstatus() == 0)
				out << "The passenger is idle." << endl;
			if (p.currenttrip->getstatus() == 1)
				out << "The passenger is in an ongoing ride." << endl;
			else if (p.currenttrip->getstatus() == 2)
				out << "The passenger cancelled the ride." << endl;
			else if (p.currenttrip->getstatus() == 3)
				out << "The passenger is looking for a ride." << endl;
			else if (p.currenttrip->getstatus() == 4)
				out << "The ride was completed." << endl;
		}
		else
			out << "The passenger is idle." << endl;
	}
	return out;
}
