//this program prints the sum of a even values in the fibonacci sequence till 4 million
#include<iostream>
using namespace std;
int main()
{
long f,a=0,b=1,sum=0;	
while(f<=4000000) //this loops sums all even values in fibonacci sequence
	{
		f=a+b;
		if(f%2==0)
		{ sum+=f;
		}
		a=b; 
		b=f;
	}	
cout<<"The sum of all even values in fibonacci sequence till 4 million is "<<sum;	
}

