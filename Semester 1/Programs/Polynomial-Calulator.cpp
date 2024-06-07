#include<iostream>
using namespace std;
addsub(int arr[],int arr2[],int size,int size2,char sign)
{
	int temparr[30],temparr2[30],answer[30],res=0;
	for(int i=0;i<30;i++)
	{
		temparr[i]=0;
		temparr2[i]=0;
	}
	int temp=size-1;
	for(int i=0;i<size-1;i++)
	{
		temparr[i]=arr[temp];
		temp--;
	}
	temp=size2-1;
	for(int i=0;i<size2-1;i++)
	{
		temparr2[i]=arr2[temp];
		temp--;
	}
	if(size>size2)
	{temp=size-1;
		for(int i=0;i<size;i++)
		{
			if(sign=='+')
			{
				answer[temp]=temparr[i]+temparr2[i];
				temp--;
		    }
		    else if(sign=='-')
		    {
		    	answer[temp]=temparr[i]-temparr2[i];
				temp--;
			}
		}
		res=size;
		answer[0]=arr[0];
    }
	else
	{temp=size2-1;
		for(int i=0;i<size2;i++)
		{
			if(sign=='+')
			{
				answer[temp]=temparr[i]+temparr2[i];
				temp--;
		    }
		    else if(sign=='-')
		    {
		    	answer[temp]=temparr[i]-temparr2[i];
				temp--;
			}
		}
		res=size2;
		answer[0]=arr2[0];
	}
	for(int i=0;i<res;i++)
	{
		cout<<answer[i]<<" ";
	}
}
multiply(int arr[],int arr2[],int size,int size2)
{
	
}
main()
{
	int result[30],resultsize=0;
	int arr[30],size=0;
	int arr2[30],size2=0;
	char sign;
	cout<<"Enter your two polynomials in this form e.g 6503058 stands for 5x^6+3x^3+5x+8\nThe first number is the degree of polynomial\n\nEnter -1 to terminate\n";
	cout<<"\nEnter the 1st polynomial values one by one :\n";
	for(int j=0; ;j++)
	{
		cin>>arr[j];
		if(arr[j]==-1)
		{
			break;
		}
		size++;
	}
	cout<<"\nEnter the 2nd polynomial values one by one :\n";
	for(int j=0; ;j++)
	{
		cin>>arr2[j];
		if(arr2[j]==-1)
		{
			break;
		}
		size2++;
	}
	repeat:
	cout<<"\nEnter :\n'+' for addition\n'-' for subtraction\n'x' for multiplication\n";
	cin>>sign;
	if(sign=='+' || sign=='-')
	{
		addsub(arr,arr2,size,size2,sign);
	}
	else if(sign=='x')
	{
		multiply(arr,arr2,size,size2);
	}
	else
	{
		cout<<"\nInvalid input!\n";
		goto repeat;
	}
}
