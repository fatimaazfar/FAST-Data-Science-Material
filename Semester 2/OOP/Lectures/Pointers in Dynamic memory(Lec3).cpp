#include <iostream>
using namespace std;

int x = 6;

int main()
{
	int y = 7;
	int x = 5;
	cout << ::x << endl;
	//new char;
	float *fptr = new float;
	int *iptr = new int;
	*iptr = 50;
	*fptr = *iptr + 0.7;
	cout << *fptr << endl;
	cout << fptr << endl;
	delete fptr;
	delete 	iptr;
	iptr = NULL;
	fptr = NULL;
}
