#include<iostream>
using namespace std;
int main ()
{
	int n=0, a=1, b=0, l=0, s=1;
	cout<<"Enter number of elements: ";
	cin>>n;
	while(a<=n)
	{
		do
		{
		cout<<"Enter element: ";
		cin>>b;
		if(b>l)
		{
		   l=b;
		}
		else
		{
			s=b;
		}
    	}
    	while(10%2); //10%2 is used for falsifying the loop
        a++;
	}
	if(n>0)
	{
	cout<<"Largest value: "<<l<<endl;
	cout<<"Smallest value: "<<s<<endl;
    }
	else{
	cout<<"Invalid input."; }
}

