//this program reverses the input number 
#include<iostream>
using namespace std;
int main()
{
	int a=1, n, b=0, d;
	cout<<"Enter a number: ";
	cin>>n;
	cout<<"Enter the amount of digits in your given number: ";
	cin>>d;
	while(a<=d)
	{
		b=n%10;
		cout<<b<<endl;
		n=n/10;
		a++;
	} 
}
