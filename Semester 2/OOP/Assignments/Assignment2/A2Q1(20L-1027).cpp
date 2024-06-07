#include<iostream>
using namespace std;
char* getname(int size=20)
{
	size++;
	char* name = new char[size];
	cout << "Enter name (less than " << size-1 << " characters) : ";
	cin.getline(name,size);
	return name;
}
int main()
{
	char* name=getname();
	cout << "The name you enetered is : " << name << endl;
	delete[] name;
	name = getname(50);
	cout << "The name you enetered is : " << name << endl;
	delete[] name;
}