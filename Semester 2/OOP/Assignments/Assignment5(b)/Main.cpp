#include "Address.h"
#include "Project.h"
#include "Employee.h";

void main()
{
	//creating 2 projects 
	Project* P1 = new Project("Database Project 1", 15000, 10);
	Project* P2 = new Project("Database Project 2", 100000, 18);

	//creating 3  employee
	Employee* E1 = new Employee("Sam", Address("19B", "Foggy Street", "London", "UK"));
	Employee* E2 = new Employee("Ali", Address("19C", "Foggy Street", "London", "UK"));
	Employee* E3 = new Employee("Sara", Address("19C", "Foggy Street", "London", "UK"));

	//testing addition and removal of projects in employee E1
	E1->addProject(P1);
	E1->addProject(P2);
	E2->addProject(P2);
	E3->addProject(P1);
	E3->addProject(P2);
	//print E1 using overloaded insertion operator
	cout << *E1 << endl;
	cout << *E2 << endl;
	cout << *E3 << endl;
	cout << *P1 << endl;
	cout << *P2 << endl;
	P1->printEmployees();// will print names of employees 
	P2->printEmployees();
	E1->removeProject(P1);
	cout << *P1 << endl;
	P1->printEmployees();
}






