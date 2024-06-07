#include<iostream>
using namespace std;
void repdup(int array[],int size)
{
		for(int i=0;i<size;i++)
	{
		for(int j=i+1;j<size;j++)
		{
			if(array[i]==array[j])
			{
				array[j]=-1;
			}
		}
	}
}
int main()
{
    int size;
	cout<<"Enter size : ";
	cin>>size;
	int a[size];
	for(int i=0 ; i<size ; i++)
	{
		cout<<"Enter element : ";
		cin>>a[i];
	}
	cout<<"The array you entered is : ";
	for(int i=0 ; i<size ; i++)
	{
		cout<<a[i]<<" ";
	}
    repdup(a,size);
	cout<<"\nThe array after replacing duplicates with -1 is : ";
	for(int i=0 ; i<size ; i++)
	{
		cout<<a[i]<<" ";
	}
}
