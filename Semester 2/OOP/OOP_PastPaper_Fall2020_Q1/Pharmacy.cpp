#include"Pharmacy.h"

Pharmacy::Pharmacy(int s):index(0),size(s)
{
	list = new Items * [size];
}

void Pharmacy::AddItem(Items* item)
{
	if (index < size)
		list[index++] = item;
	else
		cout << "List is full already." << endl;
}

void Pharmacy::DisplayItems()
{
	for (int i = 0;i < index;i++)
	{
		if(list[i] != nullptr)
			list[i]->print();
	}
}
