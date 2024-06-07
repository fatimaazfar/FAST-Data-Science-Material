#pragma once
class trip;//passenger knows his trip but does not own it
#include "payment.h"//passenger owns payment
#include "user.h"//passenger inherits from user
#include<iostream>
using namespace std;

class passanger : public user
{
	payment paymethods[3];
	int paynum = 0;
	int counter = 0;
	payment pTemp;
public:
	friend class trip;
	passanger();
	passanger(string nam, date dat, string em, string phone, payment p = payment("", ""));
	void addpaymethod(payment&);
	void deletepaymethod(payment&);
	trip* bookRide(string pick, string drop);
	void cancelRide();
	void rateDriver(trip*, int);
	float getAvgRating();
	friend ostream& operator << (ostream& out, passanger& p);
};