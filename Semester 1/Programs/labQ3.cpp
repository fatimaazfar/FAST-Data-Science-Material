#include<iostream>
using namespace std;
int main()
{
	int a,b,c,d;
	    cout<<"Enter marks of first student : ";
	cin>>a;
		cout<<"Enter marks of second student : ";
	cin>>b;
		cout<<"Enter marks of third student : ";
	cin>>c;
		cout<<"Enter marks of fourth student : ";
	cin>>d;
	int largest=0;
	if(a>largest)
	{
		largest=a;
	}
		if(b>largest)
	{
		largest=b;
	}
		if(c>largest)
	{
		largest=c;
	}
		if(d>largest)
	{
		largest=d;
	}
	cout<<"The highest marks are : "<<largest;
}
