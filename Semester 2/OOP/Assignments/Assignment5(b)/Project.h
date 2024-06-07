#include <iostream>
#include <string>
class Employee;

using namespace std;

#ifndef PROJECT_H
#define PROJECT_H
class Project
{
	friend class Employee;
	string name;
	int budget;
	int duration; //estimate duration of project in weeks
	Employee** emp;
	int sizeEmp;
	int maxEmp;
	int empNum;
	int noEmp;
	void addEmp(Employee& e)
	{
		if (sizeEmp == maxEmp)
		{
			maxEmp += 3;
			emp = reallocate();//to increase the size
		}
		int count = 0;
		for (int i = 0;i < sizeEmp;i++)
		{
			if (emp[i] == nullptr)
			{
				emp[i] = &e;
				count++;
				cout << "Employee added to project." << endl;
				break;
			}
		}
		if (count == 0)
		{
			emp[sizeEmp++] = &e;
			cout << "Employee added to project." << endl;
		}
		empNum++;
	}
	void removeEmp(Employee& e)
	{
		for (int i = 0;i <= sizeEmp;i++)
		{
			if (emp[i] == &e)
			{
				emp[i] = nullptr;
				break;
			}
		}
		empNum--;
		cout << "Employee removed from project." << endl;
	}

public:
	Project(string name = "", int budget = 0, int duration = 0);//overloaded and default constructor
	Project(const Project& p);//copy constructor
	bool operator == (const Project* p) const;//equals to operator
	friend ostream& operator<<(ostream& out, const Project& p);//ostream operator
	void setBudget(int b);//sets the budget
	Employee** reallocate();
	void printEmployees();
};
#endif