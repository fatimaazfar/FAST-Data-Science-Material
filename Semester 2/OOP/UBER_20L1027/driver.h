#pragma once
class trip;//driver knows his trip but does not own it
#include "user.h"//driver inherits from user
#include<iostream>
using namespace std;

class driver : public user
{
	string licensenum;
	string vehiclenum;
public:
	friend class trip;
	driver(string nam, date DOB, string email, string phone, string license = "", string vehnum = "");
	void pickARide(trip*);
	void endARide();
	void ratePassanger(trip* t, int rate);
	float getAvgRating();
	friend ostream& operator << (ostream& out, driver& d);
};