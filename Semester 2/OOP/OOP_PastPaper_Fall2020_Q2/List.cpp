#include"List.h"

List::List()//default constructor
{
}

List& List::operator+(float num)
{
	list.push_back(num);
	return *this;
}

List& List::operator+(List& l)
{
	for (unsigned int i = 0; i < l.list.size(); i++)
	{
		list.push_back(l.list[i]);
	}
	return *this;
}

int List::length()
{
	return list.size();
}

float List::operator-()
{
	list.erase(list.cbegin());
	return list[0];
}

bool List::operator[](float num)
{
	for (unsigned int i = 0;i < list.size(); i++)
	{
		if (list[i] == num)
		{
			return true;
		}
	}
	return false;
}

void List::reverse()
{
	std::reverse(list.begin(), list.end());
}

ostream& operator<<(ostream& out, List& l)
{
	out << "[ ";
	for (unsigned int i = 0;i < l.list.size()-1;i++)
	{
		out << l.list[i] << " , ";
	}
	out << l.list[l.list.size()-1];
	out << " ]";
	return out;
}
