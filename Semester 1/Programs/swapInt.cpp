#include<iostream>
using namespace std;
swapInt(int& a,int& b)
{
	a=a+b;
	b=a-b;
	a=a-b;
}
int main()
{
	int num,num2;
	cout<<"Enter 1st number : ";
	cin>>num;
	cout<<"Enter 2nd number : ";
	cin>>num2;
	swapInt(num,num2);
	cout<<"1st Number : "<<num<<endl<<"2nd Number : "<<num2;
}
