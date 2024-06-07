#include<iostream>
using namespace std;
main()
{
	int num,sqr;
	while(1)
	{
	cout<<"Enter the number : ";
	cin>>num;
	if(num==-1)
	{
		break;
	}
	for(int i=2;i<num;i++)
	{
		for(int j=2;j<num;j++)
		{
			if(i*j==num)
			{
				if(i==j)
				{
					sqr=i;
				}
			    else
			    {
			    	sqr=i;
				}
			}
		}
	}
	cout<<"The square root for "<<num<<" is "<<sqr<<endl<<endl;
	}
}
