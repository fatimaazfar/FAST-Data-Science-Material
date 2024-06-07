#include"trip.h"
#include"driver.h"
#include"passanger.h"
#include<iostream>
using namespace std;

void setcurrenttime(date& dat)
{
	struct tm newtime;
	time_t now = time(0);
	localtime_s(&newtime, &now);
	dat.setday(newtime.tm_mday);
	dat.setmonth(1 + newtime.tm_mon);
	dat.setyear(1900 + newtime.tm_year);
}

trip::trip() : driverrating(0), passengerrating(0), status(0), drive(nullptr), passenger(nullptr)
{
	//default constructor
	setcurrenttime(dat);
}

trip::trip(const trip& t)
{
	dat = t.dat;
	drive = t.drive;
	driverrating = t.driverrating;
	dropoff = t.dropoff;
	passenger = t.passenger;
	passengerrating = t.passengerrating;
	pickup = t.pickup;
	status = t.status;
}

trip::trip(driver* d, passanger* p, date da, string pick, string drop) : drive(d), passenger(p), dat(da), pickup(pick), dropoff(drop), driverrating(0), passengerrating(0), status(0)
{
	//overload constructor
	setcurrenttime(dat);
}

void trip::setstatus(int s)
{
	if (this != nullptr)
		status = s;//1 means the ride is ongoing, 0 means the ride is idle, 2 means the ride was cancelled, 3 means looking for driver, 4 means the ride is completed
}

int trip::getstatus()
{
	return status;
}

void trip::setDriverCurrTrip(trip* t)
{
	drive->currenttrip = t;
}

void trip::setPassCurrTrip(trip* t)
{
	passenger->currenttrip = t;
}

string trip::passName()
{
	return passenger->name;
}

string trip::driverName()
{
	return drive->name;
}

void trip::setpickup(string p)
{
	pickup = p;
}

void trip::setdropoff(string d)
{
	dropoff = d;
}

void trip::setdriver(driver* d)
{
	drive = d;
}

void trip::setpassenger(passanger* p)
{
	passenger = p;
}

ostream& operator<<(ostream& out, trip& t)
{
	if (&t != 0)
	{
		if (t.passenger != nullptr)
			out << "Passenger Name : " << t.passenger->name << endl;
		if (t.drive != nullptr)
			out << "Driver Name : " << t.drive->name << endl;
		out << "Date : " << t.dat;
		out << "Status : ";
		if (t.getstatus() == 0)
		{
			cout << "The trip hasn't started." << endl;
		}
		else if (t.getstatus() == 1)
		{
			out << "The trip is ongoing." << endl;
		}
		else if (t.getstatus() == 2)
		{
			out << "The trip was cancelled." << endl;
		}
		else if (t.getstatus() == 3)
		{
			out << "Passenger is looking for a driver." << endl;
		}
		else if (t.getstatus() == 4)
		{
			out << "The trip was completed." << endl;
			out << "Passenger was rated : " << t.passengerrating << endl;
			out << "Driver was rated : " << t.driverrating << endl;
		}
		out << "Pick up location : " << t.pickup << endl;
		out << "Drop off location : " << t.dropoff << endl;
	}
	return out;
}

trip::~trip()
{
	if (this != nullptr)
	{
		if (passenger != nullptr)
		{
			passenger->deleteAtrip(this);
		}
		if (drive != nullptr)
		{
			drive->deleteAtrip(this);
		}
	}
}
