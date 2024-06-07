#include "Project.h"
#include "Employee.h"

	Project::Project(string name, int budget, int duration)//overloaded and default constructor
	{
		this->name = name;
		this->budget = budget;
		this->duration = duration;
		maxEmp = 5;
		emp = new Employee * [maxEmp];
		empNum = 0;
	}
	Project::Project(const Project& p)//copy constructor
	{
		this->name = p.name;
		this->budget = p.budget;
		this->duration = p.duration;
		emp = p.emp;
		sizeEmp = p.sizeEmp;
		maxEmp = p.maxEmp;
	}
	bool Project::operator == (const Project* p) const //equals to operator
	{
		if (this == p)
		{
			return true;
		}
		else if ((name == p->name && budget == p->budget) && duration == p->duration)
		{
			return true;
		}
		return false;
	}
	ostream& operator<<(ostream& out, const Project& p)//ostream operator
	{
		if (&p != nullptr)
		{
			out << "Project name : " << p.name << ", Budget : " << p.budget << ", Duration : " << p.duration << ", Number of employees : " << p.empNum;
		}
		return out;
	}
	void Project::setBudget(int b)//sets the budget
	{
		budget = b;
	}
	Employee** Project::reallocate()
	{
		Employee** e = new Employee * [maxEmp];
		for (int i = 0;i < maxEmp;i++)
		{
			e[i] = emp[i];
		}
		emp = e;
		return emp;
	}
	void Project::printEmployees()
	{
		for (int i = 0;i < sizeEmp;i++)
		{
			if (emp[i] != nullptr)
			{
				cout << emp[i]->getName() << endl;
			}
		}
	}