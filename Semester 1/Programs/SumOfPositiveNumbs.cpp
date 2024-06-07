#include<iostream>
using namespace std;
int main()
{
	int n,sum=0,i=1;
	while(i++)
	{
	cout<<"Enter a number : ";
	cin>>n;
	if(n>=0)
	    sum=sum+n;
	else
	    break;
    }
    cout<<"Sum of all positive values is "<<sum;   
}
