#include<iostream>
using namespace std;
//this func copies the original pointer array in a temporary array for later use
copyArray(int* arr, int *&arr1, int size)
{
	for(int i=0;i<size;i++)
	{
		arr1[i]=arr[i];
	}
}
//this func allocates a new reduced array in dynamic memory and copies temp in that newly allocated array
int reduceArray(int *arr, int *&arr1, int size2,int size)
{
	delete[] arr;
	arr=new int[size];
	int j=size-size2;
	for(int i=0;i<size;i++)
	{
		arr[i]=arr1[j];
		j++;
	}
}
int main()
{
	int size,size2;
	cout<<"Enter the size of array : ";
	cin>>size;
	int* arr=new int[size],*arr1=new int[size];
	cout<<"Enter the elements of the array : "<<endl;
	for(int i=0;i<size;i++)
	{
		cin>>arr[i];
	}
	copyArray(arr,arr1,size);
	cout<<"Enter the reduced size of array : ";
	cin>>size2;
	reduceArray(arr,arr1,size2,size);
	cout<<"The reduced array is : ";
	for(int i=0;i<size2;i++)
	{
		cout<<arr[i]<<" ";
	}
	delete[] arr;
	delete[] arr1;
	arr=NULL;
	arr1=NULL;
	return 0;
}
