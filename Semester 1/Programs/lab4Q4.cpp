#include<iostream>
using namespace std;
int main()
{   int marks=0;
	cout<<"Enter the marks : ";
	cin>>marks;
	if(marks>=90&&marks<=100)
	{
		cout<<"A+ grade"<<endl;
	}
    	if(marks>=80&&marks<90)
	{
		cout<<"A grade"<<endl;
	}
		if(marks>=70&&marks<80)
	{
		cout<<"B+ grade"<<endl;
	}
		if(marks>=60&&marks<70)
	{
		cout<<"B grade"<<endl;
	}
		if(marks>=50&&marks<60)
	{
		cout<<"B- grade"<<endl;
	}
		if(marks<50)
	{
		cout<<"F grade"<<endl;
	}
}
