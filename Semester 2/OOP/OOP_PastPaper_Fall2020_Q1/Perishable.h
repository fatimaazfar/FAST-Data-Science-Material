#pragma once
#include"Items.h"
#include"Date.h"

class Perishable: public Items
{
	Date expiry;
	int quantity;
public:
	Perishable(string nam, float pric, int day, int month, int yaer, int quant);
	void print();
	void expired(Date& entry);
};