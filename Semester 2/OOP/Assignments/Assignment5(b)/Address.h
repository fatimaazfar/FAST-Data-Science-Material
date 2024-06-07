//Address.h
#include <iostream>
#include <string>
using namespace std;


#ifndef ADDRESS_H
#define ADDRESS_H
class Address
{
	string house_Number;
	string street_Name;
	string city;
	string country;

public:
	Address(string house_Number = "", string street_Name = "", string city = "", string country = "")//overloaded and default constructor
	{
		this->house_Number = house_Number;
		this->street_Name = street_Name;
		this->city = city;
		this->country = country;

	}
	friend ostream& operator<<(ostream& osObject, const Address& A)
	{
		osObject << A.house_Number << ", " << A.street_Name << ", " << A.city << ", " << A.country << ".";
		return osObject;
	}
};
#endif
