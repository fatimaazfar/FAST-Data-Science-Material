#include <iostream>
#include <string>
using namespace std;

#ifndef PROJECT_H
#define PROJECT_H
class Project
{
	string name;
	int budget;
	int duration; //estimate duration of project in weeks

public:
	Project(string name = "", int budget = 0, int duration = 0)//overloaded and default constructor
	{
		this->name = name;
		this->budget = budget;
		this->duration = duration;
	}
	Project(const Project& p)//copy constructor
	{
		this->name = p.name;
		this->budget = p.budget;
		this->duration = p.duration;
	}
	bool operator == (const Project* p) const //equals to operator
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
	friend ostream& operator<<(ostream& out, const Project& p)//ostream operator
	{
		out << "Project name : " << p.name << ", Budget : " << p.budget << ", Duration : " << p.duration;
		return out;
	}
	void setBudget(int b)//sets the budget
	{
		budget = b;
	}
};
#endif