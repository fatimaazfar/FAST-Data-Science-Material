#pragma once
#include<iostream>
using namespace std;

class payment
{
	string paymenttype;//c for cash, d for card
	string cardnum;
public:
	payment(string num = "", string type = "");
	void setcardnum(string);
	string getcardnum();
	bool operator == (const payment&);
	friend ostream& operator << (ostream& out, payment& p);
};
