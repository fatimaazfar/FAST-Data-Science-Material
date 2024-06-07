#include<iostream>
using namespace std;
int main ()
{
	long f=0, a=0, b=1, n;
	cout<<"Enter a number : ";
	cin>>n;
	cout<<a<<" "<<b<<" ";
	while(f<n)
	{
		f=a+b;
		cout<<f<<" ";
		a=b; 
		b=f;
}
}
