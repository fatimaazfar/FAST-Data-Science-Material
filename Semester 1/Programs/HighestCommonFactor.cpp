#include<iostream>
using namespace std;
int main()
{
	int a,b,hcf;
	cout<<"Enter 1st number : ";
	cin>>a;
	cout<<"Enter 2nd number : ";
	cin>>b;
	while(a!=b)
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
	cout<<"HCF is "<<hcf;
}
