#include<iostream>
using namespace std;
struct wpd //work per day 
{
	int salary,hours;
	char name[10];
};
int main()
{
struct wpd a[10];

for(int i=0;i<10;i++)
{
	cout<<"Enter name : ";
	cin>>a[i].name;
	cout<<"Enter salary : ";
	cin>>a[i].salary;
	cout<<"Enter work hours per day : ";
	cin>>a[i].hours;
	cout<<endl;
}
for(int i=0;i<10;i++)
{
	if(a[i].hours>=8 && a[i].hours<10)
	{
		a[i].salary+=50;
	}
	else if(a[i].hours>=10 && a[i].hours<12)
	{
		a[i].salary+=100;
	}
	else if(a[i].hours>=12)
	{
		a[i].salary+=150;
	}
}
cout<<"New Salaries : \n"<<endl;
for(int i=0;i<10;i++)
{
	cout<<"Name : "<<a[i].name<<endl;
	cout<<"Salary : "<<a[i].salary<<endl;
	cout<<"Work hours per day : "<<a[i].hours<<endl<<endl;
}
}
