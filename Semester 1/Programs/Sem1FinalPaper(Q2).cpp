#include<iostream>
using namespace std;
main()
{
	int num,rem,count=0,digit[10],sum=0;
	cout<<"Enter a number : ";
	cin>>num;
	rem=num;
	while(rem!=0)
	{
		digit[count]=rem%10;
		rem=rem/10;
		sum+=digit[count];
		count++;
	}
	for(int i=0;i<count;i++)
	{
		cout<<digit[i];
	}
}
