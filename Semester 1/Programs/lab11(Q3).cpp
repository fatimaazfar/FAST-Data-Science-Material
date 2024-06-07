#include<iostream>
using namespace std;
const int size=2;
void transpose(int arr[size][size])
{
	int copy[size][size];
	for(int i=0;i<size;i++)
	{
		for(int j=0;j<size;j++)
		{
			copy[i][j]=arr[j][i];
		}
	}
	for(int i=0;i<size;i++)
	{
		for(int j=0;j<size;j++)
		{
			arr[i][j]=copy[i][j];
		}
	}
}
int identity(int arr[size][size])
{
	int counter=0;
	for(int i=0;i<size;i++)
	{
		for(int j=0;j<size;j++)
		{
			if(i==j)
			{
				if(arr[i][j]==0)
				{
					counter++;
				}
			}
		}
	}
	if(counter==size)
	{
		return 1;
	}
	else 
	{
		return 0;
	}
}
int main()
{
	int a[size][size]={};
	cout<<"Enter elements in array of 5 x 5 : "<<endl;
	for(int i=0;i<size;i++)
	{
		for(int j=0;j<size;j++)
		{
			cin>>a[i][j];
		}
	}
	cout<<"\nThe original matrix is : "<<endl;
	for(int i=0;i<size;i++)
	{
		for(int j=0;j<size;j++)
		{
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}
	int check=identity(a);
	if(check==1)
	{
		cout<<"\nThe array is identity matrix .\n";
	}
	else
	{
		cout<<"\nThe array is not identity matrix.\n";
	}
	transpose(a);
	cout<<"\nThe transposed matrix is : "<<endl;
	for(int i=0;i<size;i++)
	{
		for(int j=0;j<size;j++)
		{
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}	
}
