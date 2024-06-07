#include<iostream>
using namespace std;
int main()
{
	int size,a[size];
	char ch;
	cout<<"Enter the hex number digit by digit : ";
	for(int i=0;a[i]!=-1;i++)
	{
		cin>>ch;
		if(a[i]=='A'||a[i]=='a')
		{
			a[i]=10;
		}
		if(a[i]=='B'||a[i]=='b')
		{
			a[i]=11;
		}
		if(a[i]=='C'||a[i]=='c')
		{
			a[i]=12;
		}
		if(a[i]=='D'||a[i]=='d')
		{
			a[i]=13;
		}
		if(a[i]=='E'||a[i]=='e')
		{
			a[i]=14;
		}
		if(a[i]=='F'||a[i]=='f')
		{
			a[i]=15;
		}
		else
		{
			a[i]=ch;
		}
		size++;
	}
}
