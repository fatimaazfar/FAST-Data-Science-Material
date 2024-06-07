#include<iostream>
using namespace std;
struct ComplexNum
{
	int real,imag;
};
int main()
{
struct ComplexNum n1,n2,newnum;
char cal;

cout<<"First number : \n";
cout<<"Enter real part : ";
cin>>n1.real;
cout<<"Enter imaginary part : ";
cin>>n1.imag;

cout<<"\nSecond number : \n";
cout<<"Enter real part : ";
cin>>n2.real;
cout<<"Enter imaginary part : ";
cin>>n2.imag;	

cout<<"\nEnter the operator (+ - *) : ";
cin>>cal;

if(cal=='+')
{
	newnum.real=n1.real+n2.real;
	newnum.imag=n1.imag+n2.imag;
	cout<<"\nResult is "<<newnum.real<<" + "<<newnum.imag<<"i"<<endl;
}
else if(cal=='-')
{
	newnum.real=n1.real-n2.real;
	newnum.imag=n1.imag-n2.imag;
	cout<<"\nResult is "<<newnum.real<<" + "<<newnum.imag<<"i"<<endl;
}
else if(cal=='*')
{
	newnum.real=n1.real*n2.real;
	newnum.imag=n1.imag*n2.imag;
	cout<<"\nResult is "<<newnum.real<<" + "<<newnum.imag<<"i"<<endl;
}
else
{
	cout<<"Invalid input.";
}

}
