#include <iostream>
#include <string>
using namespace std;
class Dummy
{
public:
	int static y;
	int u;
private:
	static string  z; // private static can be read by get function
public:

	Dummy() 
	{ u = 0; }
	static string getz() 
	{ return z; } // static get to read z
	Dummy& incY() 
	{ y++; return *this; }
	Dummy& incU() 
	{ u++; return *this; }
	void appendtoZ(string in) 
	{ z = z.append(in); }

};
string Dummy::z = "";// initialize values
int Dummy::y = 0;


int main()
{


	Dummy D1;
	D1.incY();
	D1.incU().incU();
	D1.appendtoZ("D1");
	Dummy D2;
	D2.incY();
	D2.incU().incY();
	D2.appendtoZ("D2");
	Dummy::y++;
	cout << D1.u << endl;
	cout << D1.y << endl;
	cout << D1.getz() << endl;
	cout << D2.getz() << endl;
	cout << D1.u << endl;
	cout << D1.y << endl;
	// << Dummy::z;
	cout << Dummy::y << endl;
	cout << Dummy::getz() << endl;
}