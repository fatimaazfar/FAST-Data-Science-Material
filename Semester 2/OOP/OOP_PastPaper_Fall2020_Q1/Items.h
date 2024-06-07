#pragma once
#include"Date.h"
#include<iostream>
using namespace std;

class Items
{
protected:
	string name;
	float price;
	float currentprice;
public:
	virtual void print();
	Date& getcurrentdate();
};
