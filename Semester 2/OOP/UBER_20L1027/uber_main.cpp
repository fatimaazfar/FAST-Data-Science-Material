#include <iostream>
#include<memory>
#include<fstream>
#include<assert.h>
#include "payment.h"
#include "driver.h"
#include "date.h"
#include "passanger.h"
#include "trip.h"
using namespace std;

const int SIZE = 20;

//an array of trips to keep pointers of all the trips of uber application
//This array will keep data of all the trips ever created. 
trip** uberTrips = new trip * [SIZE];
int n = 0;

void addToUberTrips(trip* t)// function to add new trips to uberTrips
{
	if (n < SIZE - 1 && t != nullptr)
	{
		uberTrips[n++] = t;
	}
}
void printUberTrips() //function to print uberTrips
{
	for (int i = 0; i < n; i++)
	{
		cout << i << " " << *uberTrips[i] << endl;
	}
}

//USER ARRAY FUNCTIONS

user** userArray = new user * [SIZE];//using the same gloabal size
int userindex = 0;

void addToUserArray(user* u)
{
	if (userindex < SIZE - 1 && u != nullptr)
	{
		userArray[userindex++] = u;
	}
}

void fileInput(string s)//global function for file inputs
{
	char type, comma;
	char* temp = new char[50];
	string name, email, phone;
	int day, mon, year;
	ifstream fin;
	fin.open(s, ios::in);
	assert(!fin.fail());
	while (!fin.eof())
	{
		fin.getline(temp, 50, ',');//stops taking input at ,
		type = temp[0];//first element was type
		fin.getline(temp, 50, ',');
		name = temp;//second element was name
		fin.getline(temp, 50, '-');
		day = stoi(temp);//"stoi()" converts string of numbers into integer
		fin.getline(temp, 50, '-');
		mon = stoi(temp);
		fin.getline(temp, 50, ',');
		year = stoi(temp);
		fin.getline(temp, 50, ',');
		email = temp;
		fin.getline(temp, 50, '\n');
		phone = temp;
		if (type == 'p')
		{
			passanger* p = new passanger(name, date(day, mon, year), email, phone);
			addToUserArray(p);
		}
		else if (type == 'd')
		{
			driver* d = new driver(name, date(day, mon, year), email, phone);
			addToUserArray(d);
		}
	}
	fin.close();
	assert(!fin.fail());
	delete[] temp;
}

void printUserArray()
{
	for (int i = 0; i < userindex; i++)
	{
		userArray[i]->print();
	}
}

user* highestRating()
{
	float largest = 0.0;
	user* u = nullptr;
	for (int i = 0; i < userindex; i++)
	{
		if (userArray[i]->getAvgRating() > largest)
		{
			largest = userArray[i]->getAvgRating();
			u = userArray[i];
		}
	}
	return u;
}

user* highestRatedDriver()
{
	float largest = 0.0;
	user* u = nullptr;
	driver* ptr;
	for (int i = 0; i < userindex; i++)
	{
		ptr = dynamic_cast<driver*> (userArray[i]);
		if (ptr != nullptr)
		{
			if (userArray[i]->getAvgRating() > largest)
			{
				largest = userArray[i]->getAvgRating();
				u = userArray[i];
			}
		}
	}
	return u;
}

user* highestRatedPassenger()
{
	float largest = 0.0;
	passanger* ptr;
	user* u = nullptr;
	for (int i = 0; i < userindex; i++)
	{
		ptr = dynamic_cast<passanger*> (userArray[i]);
		if (ptr != nullptr)
		{
			if (userArray[i]->getAvgRating() > largest)
			{
				largest = userArray[i]->getAvgRating();
				u = userArray[i];
			}
		}
	}
	return u;
}

void main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	{

		unique_ptr<passanger> p1(new passanger("P1", date(10, 10, 1990), "ali@yahoo.com", "0334564334", payment("111-222-333-333", "card")));//unique pointer deleted the memory automatically when it goes out of scope
		unique_ptr<driver> d1(new driver("D1", date(16, 1, 1990), "ayesha@yahoo.com", "0357757585", "Lin1197717", "VIN9817917"));

		//////Test Case 1, user books, driver picks, driver ends (rating can be given only in this case)
		cout << "-------------------TEST CASE 1-------------------" << endl;

		cout << *p1 << endl;
		cout << *d1 << endl;

		addToUberTrips(p1->bookRide("A", "B"));// will create a new trip and add it to uberTrips array
		cout << *uberTrips[n - 1];// will print this trip
		addToUberTrips(p1->bookRide("C", "D"));//prints error as p1 has already booked a ride
		d1->pickARide(uberTrips[n - 1]); //will assign  d1 to uberTrip[0], the status of this ride will also change to InProgress
		d1->ratePassanger(uberTrips[n - 1], 5); //error as the trip is not complete
		p1->rateDriver(uberTrips[n - 1], 4); //error as the trip is not complete

		cout << *p1 << endl;
		cout << *d1 << endl;

		d1->endARide(); //will change the status of uberTrip[0] to Complete

		d1->ratePassanger(uberTrips[n - 1], 5); //error as the trip is not complete
		p1->rateDriver(uberTrips[n - 1], 4); //error as the trip is not complete
		cout << *uberTrips[n - 1] << endl;
		cout << *p1 << endl;
		cout << *d1 << endl;
		d1->pickARide(uberTrips[n - 1]);//prints error as the ride is completed

		cout << "\n\n-------------------TEST CASE 2-------------------\n" << endl;

		//////Test case 2: User books, driver picks, user cancels, ratings are not applicable to cancelled ride
		addToUberTrips(p1->bookRide("C", "D"));
		d1->pickARide(uberTrips[n - 1]);
		cout << *p1 << endl;
		cout << *d1 << endl;
		p1->cancelRide();
		p1->cancelRide();//error as there is no current ride
		cout << *p1 << endl;
		cout << *d1 << endl;
		d1->ratePassanger(uberTrips[n - 1], 5); //error as the ride was not complete
		p1->rateDriver(uberTrips[n - 1], 5); //error as the ride was not complete

		cout << "\n\n-------------------TEST CASE 3-------------------\n" << endl;

		////Test Case 3: User Books, user Cancels, driver cannot pick this ride now, ratings are not applicable to this ride
		addToUberTrips(p1->bookRide("D", "E"));
		p1->cancelRide();
		d1->pickARide(uberTrips[n - 1]); //error as this ride is not looking for driver
		d1->ratePassanger(uberTrips[n - 1], 5); //error as the ride was not complete
		p1->rateDriver(uberTrips[n - 1], 5); //error as the ride was not complete

		cout << "\n\n-------------------TEST CASE 4-------------------\n" << endl;

		////Test Case 4: getting avg ratings adn print trip funnction
		//Adding some more test data
		addToUberTrips(p1->bookRide("X", "Y"));
		d1->pickARide(uberTrips[n - 1]);
		d1->endARide();
		d1->ratePassanger(uberTrips[n - 1], 3);
		p1->rateDriver(uberTrips[n - 1], 5);

		addToUberTrips(p1->bookRide("X", "Y"));
		d1->pickARide(uberTrips[n - 1]);
		d1->endARide();
		d1->ratePassanger(uberTrips[n - 1], 6);//error as the rating is not between 1 and 5 
		d1->ratePassanger(uberTrips[n - 1], 4);
		d1->ratePassanger(uberTrips[n - 1], 3);// will upate the passanging rating from 4 to 3
		p1->rateDriver(uberTrips[n - 1], 1);

		p1->printTrips();
		d1->printTrips();

		cout << "Passenger average rating : " << p1->getAvgRating() << endl;
		cout << "Driver average rating : " << d1->getAvgRating() << endl;

		cout << "\n\n--------------------MODULE 3--------------------\n" << endl;
		fileInput("userdata.txt");//point 3 of module 3
		printUserArray();//point 4 of module 3
		//point 8 of module 3
		//sequence of names in file
		/*
		index 0 : shahmeer
		index 1 : meher
		index 2 : ibrahim
		index 3 : mustafa
		index 4 : ali
		index 5 : sana
		index 6 : noor
		*/
		cout << "\n\n--------------------Part 8 of MODULE 3--------------------\n" << endl;
		trip* t;
		t = userArray[0]->bookRide("Here", "There");//shahmeer books a ride
		addToUberTrips(t);
		userArray[1]->pickARide(t);//meher picks shahmeer's ride
		userArray[1]->endARide();//meher ends shahmeer's ride
		userArray[0]->rateDriver(t, 5);//shahmeer rates meher 5
		userArray[1]->ratePassanger(t, 4);//meher rates shahmeer 4
		t = userArray[2]->bookRide("FAST", "UOL");//ibrahim books a ride
		addToUberTrips(t);
		userArray[1]->pickARide(t);//meher picks ibrahim's ride
		userArray[1]->endARide();//meher ends ibrahim's ride  
		userArray[1]->ratePassanger(t, 3);//meher rates Ibrahim
		userArray[2]->rateDriver(t, 4);//ibrahim rates meher
		t = userArray[5]->bookRide("Lahore", "Multan");//sana books a ride
		addToUberTrips(t);
		userArray[1]->pickARide(t);//meher picks sana's ride
		userArray[1]->endARide();//meher ends sana's ride
		userArray[1]->ratePassanger(t, 4);//meher rates sana
		userArray[5]->rateDriver(t, 5);//sana rates meher
		cout << "\nHighest Ranked user is : " << endl;
		highestRating()->print();//point 5 of module 3
		cout << "\nHighest ranked driver is : " << endl;
		highestRatedDriver()->print();//point 6 of module 3
		cout << "\nHighest ranked passenger is : " << endl;
		highestRatedPassenger()->print();//point 7 of module 3

		cout << "\n\n----------------------EXTRA TEST CASES-------------------------\n" << endl;
		//TEST CASES TO UNDERSTAND THE WORKING OF POLYMORPHISM DONE IN USER CLASS
		/*
		1. Driver cannot book a ride, cancel a ride, or rate him/herself.
		2. Passenger cannot pick a ride, end a ride, or rate him/herself.
		Following are some test cases to make sure the code is printing proper error messages for such cases.
		*/

		t = userArray[1]->bookRide("a", "b");//meher(driver) tries to book a ride
		userArray[1]->rateDriver(t, 5);//meher cannot rate herself
		userArray[1]->cancelRide();//meher cannot cancel a ride
		userArray[0]->pickARide(t);//shahmeer(passenger) tries to pick a ride
		userArray[0]->endARide();//shahmeer cannot end a ride

		/*Now checking some add payment and deleted payment functions*/

		cout << "\n\n----CHECKING ADD PAYMENT AND DELETE PAYMENT FUNCTIONS----\n\n";

		payment p("", "cash");
		p1->addpaymethod(p);
		cout << "A payment is added : " << endl;
		cout << *p1 << endl;
		p1->deletepaymethod(p);
		cout << "A payment is deleted : " << endl;
		cout << *p1 << endl;
		payment pay("12345678", "card");
		p1->addpaymethod(pay);
		cout << "A payment was added again : " << endl;
		cout << *p1 << endl;
		//point 9 of module 3 (deallocation of all the pointers)

		delete t;
		delete[] uberTrips;
		delete[] userArray;
	}
}
