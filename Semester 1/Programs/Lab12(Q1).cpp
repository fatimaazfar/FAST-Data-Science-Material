#include<iostream>
using namespace std;
struct Date
{
	int day,month,year;
};
int main()
{
struct Date d1,d2;

cout<<"First date : ";
cout<<"\nEnter day : ";
cin>>d1.day;
cout<<"Enter month : ";
cin>>d1.month;
cout<<"Enter year : ";
cin>>d1.year;

cout<<"\nSecond date : ";
cout<<"\nEnter day : ";
cin>>d2.day;
cout<<"Enter month : ";
cin>>d2.month;
cout<<"Enter year : ";
cin>>d2.year;

if((d1.day==d2.day)&&(d1.month==d2.month)&&(d1.year==d2.year))
{
	cout<<"\nDates are equal.\n";
}
else
{
	cout<<"\nDates are not equal.\n";
}
}
