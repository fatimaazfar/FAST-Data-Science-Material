#include<iostream>
using namespace std;
int main()
{
	int lower,upper,scm,hcf,a,b,c;
	cout<<"Enter the lower limit : ";
	cin>>lower;
	cout<<"Enter the upper limit : ";
	cin>>upper;
	scm=lower;
	c=lower;//initializing to first number for first loop run
	for(int i=lower+1;i<=upper;i++)
	{	
	a=scm,b=i;
	while(a!=b)//this loop finds the hcf
	{
	if(a>b)
		a=a-b;
	if(b>a)
		b=b-a;
	else
		hcf=a;
	}
	if(a==b)
	{hcf=b;}
	scm=(c*i)/hcf;//formula for lcm used here is lcm = (previous lcm * next number) / hcf of (prev lcm, next num)
	c=scm;//assigning the lcm to c to use it in the formula in next turn of loop 
	}
	cout<<"The smallest common multiple of all values from "<<lower<<" to "<<upper<<" is "<<scm<<"."<<endl;
}
