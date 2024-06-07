#include<iostream>
using namespace std;
int main()
{
	char input;
	int speed,ticket;
	cout<<"Is it your birthday? (Enter Y for yes and N for no) ";
	cin>>input;
	if(input=='N'||input=='n')
	{
	cout<<"Enter the speed : ";
	cin>>speed;
	if(speed<=60)
	{
		ticket=0;
	}
	else if(speed>60&&speed<=80)
	{
		ticket=1;
	}
	else
	{
		ticket=2;
	}
    }
    else if(input=='Y'||input=='y')
    {
    	cout<<"Enter the speed : ";
	cin>>speed;
	if(speed<=65)
	{
		ticket=0;
	}
	else if(speed>65&&speed<=85)
	{
		ticket=1;
	}
	else
	{
		ticket=2;
	}
	}
	if(ticket==0)
	{
		cout<<"No ticket";
	}
		if(ticket==1)
	{
		cout<<"1 ticket";
	}
		if(ticket==2)
	{
		cout<<"2 tickets";
	}
}
