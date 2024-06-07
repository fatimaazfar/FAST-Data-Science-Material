#include<iostream>
using namespace std;
struct info  
{
	long accountn,balance;
	char name[10];
};
void lessthantwo(struct info a[])
{
	for(int i=0;i<10;i++)
	{
	if(a[i].balance<200)
	{
		cout<<"Name : "<<a[i].name<<endl;
	}
    }
}
void morethanten(struct info a[])
{
	for(int i=0;i<10;i++)
	{
	if(a[i].balance>1000)
	{
	    a[i].balance+=100;
		cout<<"Name : "<<a[i].name<<endl;
		cout<<"New Balance : "<<a[i].balance<<endl;	
	}
    }
}
int main()
{
struct info a[10];

for(int i=0;i<10;i++)
{
	cout<<"Enter name : ";
	cin>>a[i].name;
	cout<<"Enter account number : ";
	cin>>a[i].accountn;
	cout<<"Enter balance: ";
	cin>>a[i].balance;
	cout<<endl;
}
lessthantwo(a);
cout<<endl;
morethanten(a);
}
