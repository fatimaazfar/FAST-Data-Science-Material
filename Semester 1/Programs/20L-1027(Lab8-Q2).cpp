#include<iostream>
using namespace std;
int main()
{
	char arr[100];
	int size=0,b=0;
	cout<<"Enter size of array : ";
	cin>>size;
	for(int i=0;i<size;i++) //inputting values in array
	{
		cout<<"Enter element in array : ";
		cin>>arr[i];
	}
	cout<<"\nThe array you entered is { "; //printing the original array
	for(int i=0;i<size;i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<"}";
	int p=0;
	char arr2[size];
	for(int i=0;i<size;i++)
	{
		if(arr[i]=='b')
		{
			arr2[p]=arr[i];
			p++;
	    }
	}
		for(int i=0;i<size;i++)
	{
		if(arr[i]=='m')
		{
			arr2[p]=arr[i];
			p++;
	    }
	}
		for(int i=0;i<size;i++)
	{
		if(arr[i]=='a')
		{
			arr2[p]=arr[i];
			p++;
	    }
	}
	cout<<"\nThe sorted array is { "; //printing the original array
	for(int i=0;i<size;i++)
	{
		cout<<arr2[i]<<" ";
	}
	cout<<"}";
}

