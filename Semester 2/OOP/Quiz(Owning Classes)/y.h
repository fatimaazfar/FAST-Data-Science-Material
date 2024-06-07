#include <iostream>
using namespace std;
#include "X.h"
#ifndef Y_H
#define Y_H
class Y
{
	int c;
	X xobject;
public:
	int getC()// will return the value of a
	{
		return c;
	}
	X getXobject() // will return the xobject
	{
		return xobject;
	}

	Y& setC(int c)// will be the value of a
	{
		this->c = c; return *this;
	}
	Y& setXobject(X& other)// will set the value of b
	{
		this->xobject = other; 
		return *this;
	}

	Y() :c(0) //default constructor, will set the values of c  default constructor if X to initialize xobject
	{
		cout << "Y DC for " << this << endl;
	}
	Y(int c, X other) :c(c), xobject(other) // constructor, will copy the value of c and X with given input resp.
	{
		cout << "Y OC for " << this << endl;
	}
	Y(Y& other) :c(other.c), xobject(other.xobject)// copy constructor
	{
		cout << "Y CC for " << this << endl;
	}

	friend ostream& operator<<(ostream& os, Y& y) // overloaded insertion operator
	{
		os << y.xobject << " y=" << y.c;
		return os;
	}

	~Y()
	{
		cout << "Y DS for " << this << endl;
	}
};
#endif