#include<iostream>
using namespace std;
const int floor=8;
const int room=6;
int main()
{
char roomtype,zone;
int f=0,r=0,fe=2,fes=5,re=0,res=0;
char arr[floor][room]={};
for(int i=0;i<floor;i++)
{
	for(int j=0;j<room;j++)
	{
		arr[i][j]='X';
	}
}
while(1)
{
system("cls");
	for(int i=0;i<floor;i++)
	{
		for(int j=0;j<room;j++)
		{
			cout<<arr[i][j]<<"	";
		}
		cout<<endl;
	}	
cout<<"\nSelect the room type :\nFirst Class (Enter F)\nEconomy Class (Enter E)\n";
cin>>roomtype;
if(roomtype=='E' || roomtype=='e')
{
cout<<"\nSelect prefered zone :\nNon-Smoking (Enter N)\nSmoking (Enter S)\n";
cin>>zone;
}
if(roomtype=='F' || roomtype=='f')
{
	if(r>6)
	{
		f=1;
		r=0;
	}
	arr[f][r]='*';
	r++;
}
else if(roomtype=='E' || roomtype=='e')
{
	if(zone=='N' || zone=='n')
	{
		arr[fe][re]='*';
		re++;
		if(re>6)
		{
			fe++;
			re=0;
		}
	}
	else if(zone=='S' || zone=='s')
	{
		arr[fes][res]='*';
		res++;
		if(res>6)
		{
			fes++;
			res=0;
		}
	}
}
}
}
