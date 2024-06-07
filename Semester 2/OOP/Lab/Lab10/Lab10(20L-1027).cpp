#include<iostream>
using namespace std;

class Person
{
	string firstname;
	string lastname;
protected:
	int age;
public:
	Person(string fn = "", string ln = "", int a = 0) :firstname(fn), lastname(ln), age(a)
	{
		cout << "Person overload constructor called for " << fn << endl;
	}
	string getfirstname()
	{
		return firstname;
	}
	string getlastname()
	{
		return lastname;
	}
	int getage()
	{
		return age;
	}
	void setfirstname(string n)
	{
		firstname = n;
	}
	void setlastname(string n)
	{
		lastname = n;
	}
	void setage(int a)
	{
		age = a;
	}
	void print()
	{
		cout << endl << firstname << " " << lastname << " is " << age << " years old";
	}
	~Person()
	{
		cout << "Person destructor called for " << firstname << endl;
	}
};
class Student : public Person
{
	float cgpa;
public:
	Student(string fn = "", string ln = "", int a = 0, float cg = 0) :cgpa(cg)
	{
		setfirstname(fn);
		setlastname(ln);
		setage(a);
		cout << "Student overload constructor called for " << fn << endl;
	}
	void setcgpa(float c)
	{
		cgpa = c;
	}
	float getcgpa()
	{
		return cgpa;
	}
	void print()
	{
		Person::print();
		cout << ", his gpa is " << cgpa;
	}
	~Student()
	{
		cout << "Student destructor called for " << getfirstname() << endl;
	}
};
class undergraduate : public Student
{
	string fyp;
public:
	undergraduate(string fn = "", string ln = "", int a = 0, float cg = 0, string f = "") : fyp(f)
	{
		cout << "Undergraduate overload constructor called for " << getfirstname() << endl;
		setfirstname(fn);
		setlastname(ln);
		setage(a);
		setcgpa(cg);
	}
	void setfyp(string f)
	{
		fyp = f;
	}
	void print()
	{
		Student::print();
		cout << ", he is an undergraduate ,his final year project is " << fyp << endl;
	}
	~undergraduate()
	{
		cout << "Undergraduate destructor called for " << getfirstname() << endl;
	}
};
class graduate : public Student
{
	string thesis;
public:
	graduate(string fn = "", string ln = "", int a = 0, float cg = 0, string t = "") : thesis(t)
	{
		setfirstname(fn);
		setlastname(ln);
		setage(a);
		setcgpa(cg);
		cout << "Graduate overload constructor called for " << getfirstname() << endl;
	}
	void print()
	{
		Student::print();
		cout << ", he is a graduate ,his thesis is " << thesis << endl;
	}
	~graduate()
	{
		cout << "Graduate destructor called for " << getfirstname() << endl;
	}
};
class Faculty : public Person
{
	int numofcourse;
	int callextension;
public:
	Faculty(string fn = "", string ln = "", int a = 0, int n = 0, int e = 0) : numofcourse(n), callextension(e)
	{
		setfirstname(fn);
		setlastname(ln);
		setage(a);
		cout << "Faculty overload constructor called for " << getfirstname() << endl;
	}
	void print()
	{
		Person::print();
		cout << ", his Number of courses are " << numofcourse;
		cout << ", his Telephone extension " << callextension;
	}
	~Faculty()
	{
		cout << "Faculty destructor called for " << getfirstname() << endl;
	}
};

int main()
{
	Student s("Ted", "Thompson", 22, 3.91);
	Faculty f("Richard", "Karp", 45, 2, 420);
	//here the number of courses is 2
	//and the extension number is 420	
	undergraduate u("Ted", "Thompson", 22, 3.91, "The Event Locator");
	graduate g("Arnold", "Gates", 25, 3.01, "Distributed Algorithms");
	s.print();
	f.print();
	u.print();
	g.print();
	return 0;
}