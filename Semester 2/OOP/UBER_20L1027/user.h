#pragma once
#include"date.h"//user owns date, if user destroyed, destroy date
class trip;//user knows its trips
#include<iostream>
#include<vector>
using namespace std;

class user
{
	date dob;
	string email;
	string phonenum;
protected:
	int size = 20;
	trip** trips = new trip * [size];
	trip* currenttrip;
	int count = 0;
	float rating;
public:
	string name;
	user(string, date, string, string);
	user();
	user(const user&);
	void setname(string);
	void setdob(date&);
	void setphonenum(string);
	void setemail(string);
	void addTrip(trip*);
	void deleteAtrip(trip* t);
	virtual trip* bookRide(string pick, string drop);
	virtual void cancelRide();
	virtual void rateDriver(trip*, int);
	virtual void pickARide(trip*);
	virtual void endARide();
	virtual void ratePassanger(trip* t, int rate);
	virtual void print();
	virtual void printTrips();
	virtual float getAvgRating() = 0;
	~user();
};
