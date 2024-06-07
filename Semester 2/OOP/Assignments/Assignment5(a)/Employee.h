#include <iostream>
#include <string>
#include "Address.h"
class Project;//because employee doesn't own project, he/she just knows them

using namespace std;

#ifndef EMPLOYEE_H
#define EMPLOYEE_H
class Employee
{
	string emp_name;
	Address address;
	Project* p1, * p2;//hardcoded 2 projects only (can also use an array but the data isn't too much to store)
	int projectcount = 0;//counts the number of projects

public:
	Employee(string n, Address& a)//overloaded constructor
	{
		emp_name = n;
		address = a;
		p1 = nullptr;
		p2 = nullptr;
	}
	Employee(const Employee& e)//copy constructor
	{
		emp_name = e.emp_name;
		address = e.address;
		p1 = e.p1;
		p2 = e.p2;
	}
	const Employee& operator = (const Employee& e)//assignment operator
	{
		if (this != &e)//in case same object is being assigned e.g e = e;
		{
			emp_name = e.emp_name;
			address = e.address;
			p1 = e.p1;
			p2 = e.p2;
		}
		return *this;
	}
	friend ostream& operator<<(ostream& out, const Employee& e)//overloaded insertion operator
	{
		out << "\nEmployee name : " << e.emp_name << endl;
		out << "Address : " << e.address << endl;
		out << "Is working on : " << endl;
		out << *e.p1 << endl;
		out << *e.p2 << endl;
		return out;
	}
	void addProject(Project* p)
	{
		if (projectcount > 1)
		{
			cout << emp_name << " is already working on 2 projects." << endl;
		}
		else if (p1 != nullptr && *p == p1)//i have made a == operator in project.h to thoroughly check the similarity of both projects data
		{
			cout << "This project has already been added to " << emp_name << "'s project list." << endl;
		}
		else if (p2 != nullptr && *p == p2)
		{
			cout << "This project has already been added to " << emp_name << "'s project list." << endl;
		}
		else
		{
			if (p1 == nullptr)
			{
				p1 = p;
				projectcount++;
				cout << "Project was successfully added." << endl;
			}
			else if (p2 == nullptr)
			{
				p2 = p;
				projectcount++;
				cout << "Project was successfully added." << endl;
			}
		}
	}
	void removeProject(Project* p)// specify inputs and return types
	{
		if (*p == p1)
		{
			p1 = nullptr;//we don't delete the project but just remove its address from the employee
			projectcount--;
			cout << "Project was successfully removed." << endl;
		}
		else if (*p == p2)
		{
			p2 = nullptr;
			projectcount--;
			cout << "Project was successfully removed." << endl;
		}
		else//in case an un-known project is entered
		{
			cout << "This project doesn't exist." << endl;
		}
	}
	~Employee()//destructor
	{
		
	}

};
#endif
