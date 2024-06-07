#include<iostream>
using namespace std;
main()
{
	int *p,*p2,num,num2,sum;
	cout<<"Enter an integer : ";
	cin>>num;
	p=&num;
	cout<<"Enter an integer : ";
	cin>>num2;
	p2=&num2;
	sum=*p+*p2;
	cout<<"Your sum is : "<<sum<<endl;
}
