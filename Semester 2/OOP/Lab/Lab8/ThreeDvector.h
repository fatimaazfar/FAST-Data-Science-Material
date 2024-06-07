#include <iostream>
#include <cmath>
using namespace std;


class ThreeDvector
	// this class represnet a 3D vector, each 3D vector has three components, x, y, and z
{
	//components of vector 
	double x;
	double y;
	double z;
public:
	ThreeDvector(double a = 0, double b = 0, double c = 0)// constructor with default values of  all x, y, z  0 
	{
		x = a;
		y = b;
		z = c;
	}
	ThreeDvector& setx(double a)
	{
		x = a;
		return *this;
	}

	ThreeDvector& sety(double a)
	{
		y = a;
		return *this;
	}

	ThreeDvector& setz(double a)
	{
		z = a;
		return *this;
	}

		// overloaing operator+ to add two threeDvectors
	ThreeDvector operator+(ThreeDvector const v) const
	{
		ThreeDvector temp;
		temp.x = x + v.x;
		temp.y = y + v.y;
		temp.z = z + v.z;
		return temp;
	}


		// overloaing operator+ to do  threeDvectors+ int
		// it will add the interger in all components of vector. 
	ThreeDvector operator+(int const v) const
	{
		ThreeDvector temp;
		temp.x = x + v;
		temp.y = y + v;
		temp.z = z + v;
		return temp;
	}


		// overloaing operator* to do  threeDvectors * int
		// it will multiply the interger in all components of vector. 
	ThreeDvector operator*(int const v) const
	{
		ThreeDvector temp;
		temp.x = x * v;
		temp.y = y * v;
		temp.z = z * v;
		return temp;
	}


		// overloaing operator* to do take dot product of two vectors
		// for example if one vector is 1,2,3 and other is 4,5,6 there returned value will be  (1*2+5*2+3*6) that is, the dot product 
	double operator*(ThreeDvector const v) const
	{
		return (x * v.x) + (y * v.y) + (z * v.z);
	}


		// return true if all components of 1 vector are equal to the other
	bool operator==(ThreeDvector const v) const
	{
		if ((x == v.x && y == v.y) && (z == v.z))
		{
			return true;
		}
		return false;
	}


		// return false  if all components of 1 vector are equal to the other
	bool operator!=(ThreeDvector const v) const
	{
		if ((x == v.x && y == v.y) && (z == v.z))
		{
			return false;
		}
		return true;
	}

		// returns true of mag of calling vector is > magnitudes of other vector
		// use mag member function to get the value of ThreeDVector object magnitude.
	bool operator>(ThreeDvector const v) const
	{
		if ((x > v.x && y > v.y) && (z > v.z))
		{
			return true;
		}
		return false;
	}


		//overloaded operator=, see the syntax is slides, give in class,  to complete the function 
	const ThreeDvector& operator=(ThreeDvector const v)
	{
		if (this != &v)// a = b = d = d;
		{
			x = v.x;
			y = v.y;
			z = v.z;
		}
		return *this;
	}




		// return x, y, z if index 0, 1, 2 is passed as input respectively. 
		//if any other index  is passed print "index out of range" and return 0
		//hint vector[i] will be called as vector.operator[](i)
		//for example if vector is (10,2.0,3.6)  vector[0] will return 10 vector[1] will return 2.0 and vector[2] will return 3.6
	double operator[](double const i) const
	{
		if (i == 0)
		{
			return x;
		}
		else if (i == 1)
		{
			return y;
		}
		else if (i == 2)
		{
			return z;
		}
		else
		{
			cout << "The index you entered is out of range." << endl;
		}
	}

		// DONOT CHANGE FOLLOWING FUNCTIONS
		// returns sum of square of coordinates,
		double mag() const
	{
		return pow(x, 2) + pow(y, 2) + pow(z, 2);
	}
	// print the vector
	void print()
	{
		cout << "(" << x << ", " << y << ", " << z << ")" << endl;
	}

	friend ostream& operator << (ostream& out, const ThreeDvector& v)
	{
		out << v.x << "," << v.y << "," << v.z << endl;
		return out;
	}

	friend istream& operator >> (istream& in, ThreeDvector& v)
	{
		char comma,comma2;
		in >> v.x >> comma >> v.y >> comma2 >> v.z;
		if (comma != ',' || comma2 != ',')
		{
			cout << "Incorrect format." << endl;
		}
		return in;
	}

	ThreeDvector operator ++ (int)//post increment
	{
		ThreeDvector temp(*this);
		x++;
		y++;
		z++;
		return temp;
	}

	ThreeDvector operator ++ ()//pre increment
	{
		x++;
		y++;
		z++;
		return *this;
	}


};
