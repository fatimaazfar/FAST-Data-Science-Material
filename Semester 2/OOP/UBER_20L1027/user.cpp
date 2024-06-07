#include"user.h"
#include"trip.h"//uni-directional non-owning relation with trip

user::user(string nam, date date, string em, string phone) : name(nam), dob(date), email(em), phonenum(phone), rating(0)
{
	//overload constructor
	currenttrip = nullptr;
}

user::user(const user& u)
{
	name = u.name;
	dob = u.dob;
	email = u.email;
	phonenum = u.phonenum;
	trips = u.trips;
	currenttrip = u.currenttrip;
}

user::user() : name(""), email(""), phonenum(""), currenttrip(nullptr), rating(0)
{
	//default constructor
}

void user::setname(string n)
{
	name = n;
}

void user::setdob(date& d)
{
	dob = d;
}

void user::setphonenum(string p)
{
	phonenum = p;
}

void user::setemail(string e)
{
	email = e;
}

void user::addTrip(trip* t)
{
	if (count >= size)
	{
		size = size * 2;
		trip** temp = new trip * [size];
		for (int i = 0;i < count;i++)
		{
			temp[i] = trips[i];
		}
		delete[] trips;
		trips = temp;
	}
	else
	{
		trips[count++] = t;
	}
}

void user::deleteAtrip(trip* t)
{
	if (this != nullptr)
	{
		for (int i = 0;i < count;i++)
		{
			if (trips[i] != nullptr && trips[i] == t)
			{
				//delete trips[i];
				trips[i] = nullptr;
			}
		}
	}
}

//all these virtual funcs will only be called when the sibling tries to access them and the error message will be printed
trip* user::bookRide(string pick, string drop)
{
	cout << "Driver cannot book a ride." << endl;
	return nullptr;
}

void user::cancelRide()
{
	cout << "Driver cannot cancel a ride." << endl;
}

void user::rateDriver(trip*, int)
{
	cout << "Driver cannot rate him/her self." << endl;
}

void user::pickARide(trip*)
{
	cout << "Passenger cannot pick a ride." << endl;
}

void user::endARide()
{
	cout << "Passenger cannot end a ride." << endl;
}

void user::ratePassanger(trip* t, int rate)
{
	cout << "Passenger cannot rate him/her self." << endl;
}

void user::print()
{
	cout << "Name : " << name << endl;
	cout << "DOB : " << dob;
	cout << "Email : " << email << endl;
	cout << "Phone# : " << phonenum << endl;
}

void user::printTrips()
{
	for (int i = 0;i < count;i++)
	{
		cout << *trips[i] << endl;
	}
}

user::~user()
{
	trips = nullptr;
	currenttrip = nullptr;
}
