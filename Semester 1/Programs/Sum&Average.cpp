#include<iostream>
using namespace std;
int main ()
{
	int n=0, a=1;
	float b=0, l=0, s=1, sum=0;
	cout<<"Enter number of elements: ";
	cin>>n;
	while(a<=n)
	{
		do
		{
		cout<<"Enter element: ";
		cin>>b;
		if(b>0){
		sum=sum+b;
		if(b>l)
		{
		   l=b;
		}
		else
		{
			s=b;
		}
    	} else
    	{ cout<<"Elements cannot be below zero.";
		} }
    	while(10%2); //10%2 is used for falsifying the loop
        a++;
	}
	if(n>0 && b>0)
	{
	cout<<"Largest value: "<<l<<endl;
	cout<<"Smallest value: "<<s<<endl;
	cout<<"Sum: "<<sum<<endl;
	cout<<"Average: "<<sum/n<<endl; 
    }
	else{
	cout<<"Invalid input."; }
}
