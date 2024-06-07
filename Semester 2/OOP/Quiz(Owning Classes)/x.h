#include <iostream>
using namespace std;
#ifndef X_H
#define X_H
class X
{
	int a;
	int b;
public:
	int getA()// will return the value of a
	{
		return a;
	}
	int getB() // will return the values of b
	{
		return b;
	}

	X& setA(int a)// will be the value of a
	{
		this->a; return *this;
	}
	X& setB(int b)// will set the value of b
	{
		this->b; return *this;
	};

	X() :a(0), b(0)// default constructor, will set the values of a and b to 0
	{
		cout << "X DC for " << this << endl;
	}
	X(int a, int b) :a(a), b(b)// constructor, will set the value of a and b with given input resp. 
	{
		cout << "X OC for " << this << endl;
	}
	X(X& other) :a(other.a), b(other.b) // copy constructor
	{
		cout << "X CC for " << this << endl;
	}

	friend ostream& operator<<(ostream& osObject, const X& x)// overloaded insertion operator
	{
		osObject << "x=" << x.a << "," << x.b; return osObject;
	}

	~X() { cout << "X DS for " << this << endl; }
};
#endif
