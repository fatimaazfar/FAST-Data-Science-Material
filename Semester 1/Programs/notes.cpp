#include<iostream>
using namespace std;
int main()
{
	float amount,h,t,o,r;
	cout<<"Enter three digit amount : ";
	cin>>amount;
	h=h/100;
	r=amount-h;
	t=r/10;
	r=amount-t;
	o=r;
	cout<<h*100<<" * "<<h;
	cout<<t*10<<" * "<<t;
	cout<<o<<" * "<<o;
	
}
