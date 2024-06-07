/*this program takes two integers and finds their greatest common factor GCR*/
#include<iostream>
using namespace std;
int main()
{
	int a, b, gcr=0,c,d,e;   
	/*a and b are the values to be used to find gcr, 
	gcr is the greatest common factor, 
	c is used to hold the remainder amount, 
	d is used for holding the value of remainder so it can be used in the while condition, 
	e is used to hold the divisors*/
	cout<<"Enter the first integer: ";
	cin>>a;
	cout<<"Enter the second integer: ";
	cin>>b;
    if (a>b)
    { while(d>0)
	  {	
	  c=a%b;
	  d=c;
	  e=a/b;
	  gcr=b;
      a=b;
      b=c;
	   if (e>gcr)
	  { gcr=e; }
      } 
	}
	else if (b>a)
	{ while(d>0)
	  {	
	  c=b%a;
	  d=c;
	  e=b/a;
	  gcr=a;
	  b=a;
      a=c;
	   if (e>gcr)
	  { gcr=e; }
	} }
	cout<<"The greatest common factor is "<<gcr;
}
