#include<iostream>
using namespace std;
add(int one,int two)
{
	cout<<one+two;
}
sub(int one,int two)
{
	cout<<one-two;
}
mul(int one,int two)
{
	cout<<one*two;
}
div(int one,int two)
{
	cout<<one/two;
}
sqr(int one)
{
	cout<<one*one;
}
con(int one)
{
	cout<<one/12;
}
int main()
{
	int choice,one,two;
	start:
	cout<<"***************Wecome To Fatima's Calulator!!!!******************\n\nEnter the number to perform any of the following operations\n1. Add\n2. Subtract\n3. Divide\n4. Multiply\n5. Square\n6. Convert\n7. Exit\n";
	cin>>choice;
	if(choice>=1&&choice<=4)
	{
		cout<<"Enter 1st value : ";
		cin>>one;
		cout<<"Enter 2nd value : ";
		cin>>two;
	}
	else if(choice==6||choice==5)
	{
		cout<<"Enter value : ";
		cin>>one;
	}
	else if(choice==7)
	{
		return 0;
	}
	else
	{
		cout<<"Invalid Input, Please Enter Again!\n";
		goto start;
	}
	switch(choice)
	{
		case 1:
			add(one,two);
			break;
		case 2:
			sub(one,two);
			break;
		case 3:
			div(one,two);
			break;
		case 4:
			mul(one,two);
			break;
		case 5:
			sqr(one);
			break;
		case 6:
			con(one);
			break;					
	}
	cout<<"\nEnter 1 if you want to go to menu or any other key if you want to exit : ";
	cin>>choice;
	if(choice==1)
	{
		goto start;
	}
	else
	{
		return 0;
	}
}
