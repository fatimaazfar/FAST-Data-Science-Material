#include<iostream>
using namespace std;
main()
{
	int nominator,denominator,small;
	cout<<"Enter the nominator :    ";
	cin>>nominator;
	cout<<"		        ----"<<endl;
	cout<<"Enter the denominator :  ";
	cin>>denominator;
	if(nominator<denominator)
	{small=nominator;}
	else
	{small=denominator;}
	for(int i=2;i<=small;i++)
	{
		if(nominator%i==0 && denominator%i==0)
		{
			nominator=nominator/i;
			denominator=denominator/i;
		}
	}
	cout<<"\nNominator :    "<<nominator<<endl;
	cout<<"              ----"<<endl;
	cout<<"Denominator :  "<<denominator;
}
