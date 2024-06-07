#pragma once
#include "date.h"//trip owns date
class driver;
class passanger;//trip knows both driver and passenger but doesn't own them
#include<iostream>
#include<string>
#include<ctime>
using namespace std;

class trip
{
	int status;
	driver* drive;
	passanger* passenger;
	date dat;
	string pickup;
	string dropoff;
public:
	int driverrating;
	int passengerrating;
	trip();
	trip(driver*, passanger*, date, string = "", string = "");
	trip(const trip&);
	void setstatus(int);
	int getstatus();
	void setpickup(string);
	void setdropoff(string);
	void setdriver(driver*);
	void setpassenger(passanger*);
	void setDriverCurrTrip(trip*);
	void setPassCurrTrip(trip*);
	string passName();
	string driverName();
	friend ostream& operator << (ostream& out, trip& trip);
	~trip();
};
