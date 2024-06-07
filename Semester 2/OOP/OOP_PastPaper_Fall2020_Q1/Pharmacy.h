#pragma once
#include"Items.h"
#include<iostream>
using namespace std;

class Pharmacy
{
	int size;
	int index;
	Items** list;
public:
	Pharmacy(int s);
	void AddItem(Items* item);
	void DisplayItems();
};
