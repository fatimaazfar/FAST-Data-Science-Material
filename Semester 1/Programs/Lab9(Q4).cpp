#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
int a[3][3],trace=0;
for(int i=0;i<3;i++)
{
	for(int j=0;j<3;j++)
	{
		cout<<"Enter element : ";
		cin>>a[i][j];
		if(i==j)
		{
			trace+=a[i][j];
		}
	}
}
cout<<"\nThe array you entered is\n"<<endl;
for(int i=0;i<3;i++)
{
	for(int j=0;j<3;j++)
	{
		cout<<a[i][j]<<" ";
	}
	cout<<endl;
}
cout<<"\nThe trace is "<<trace;
}
