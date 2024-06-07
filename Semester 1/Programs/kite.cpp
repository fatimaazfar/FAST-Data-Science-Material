#include<iostream>
using namespace std;
int main()
{
	int size,tempsize,temp=0;
	cout<<"Enter the size of the kite : ";
	cin>>size;
	tempsize=size;
	for(int j=0;j<size;j+=2)
	{
	for(int i=0;i<tempsize;i++)
	{
		cout<<" ";
	}
	tempsize--;
	cout<<"*";
	for(int k=1;k<temp;k++)
	{
		cout<<" ";
	}
	if(temp!=0)
	{
		cout<<"|";
	}
	for(int l=1;l<temp;l++)
	{
		cout<<" ";
	}
	if(temp>0)
	{
		cout<<"*";
	}
	temp++;
	cout<<"\n";
    }
    temp=0;
    tempsize=size;
    for(int i=0;i<size;i++)
    {
    	for(int j=0;j<temp;j++)
    	{
    		cout<<" ";
		}
		cout<<"*";
		for(int k=0;k<tempsize;k++)
    	{
    		if(k==tempsize-1)
			{
				cout<<"|";
			}
			else if(tempsize==size)
			{
				cout<<"-";
			}
			else
			{
				cout<<" ";
			}
		}
		temp++;
		tempsize--;
		for(int l=tempsize;l>0;l--)
    	{
    		if(tempsize==size-1)
			{
				cout<<"-";
			}
			else
			{
				cout<<" ";
			}
		}
		cout<<"*";
		cout<<"\n";
	}
	for(int f=0;f<size;f++)
		{
			cout<<" ";
		}
		cout<<"*";
}
