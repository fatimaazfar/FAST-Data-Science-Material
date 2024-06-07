#pragma once
#include"Permanent.h"

class BulkItem: public Permanent
{
	string description;
	bool isPartOfset;
public:
	BulkItem(string nam, float pric, int day, int month, int year, string descrip, bool set);
	void print();
};