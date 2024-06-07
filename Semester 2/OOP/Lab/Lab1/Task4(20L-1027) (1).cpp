#include <iostream>
using namespace std;

int main()
{
	int x, y, z;
	cout << "Please enter the values." << endl;
	cout  << "Please enter the first number." << endl;
	cin >> x;
	
	cout  << "Please enter the second number." << endl;
	cin >> y;
	if (y < x)
	{
		cout << "Second number should be less the first number. ERROR!" << endl;
		system("pause");
		return 0;
	}
	cout  << "Please enter the third number." << endl;
	cin >> z;
	if (z < y)
	{
		cout << "Third term should be less the second one. ERROR!." << endl;
		system("pause");
		return 0;
	}
	int *xptr;
	int *yptr;
	int *zptr;
	xptr = &x;
	yptr = &y;
	zptr = &z;
	cout << "The entered data is:" << endl;
	cout << " " << *xptr << " " << *yptr << " " << *zptr << endl;
	cout << "The median of given numbers is: " << *yptr << endl;
	
	
	system("pause");
	return 0;
}
