//this program adds one element to the user's array at his wanted index 
#include<iostream>
using namespace std;
int main()
{
	cout<<"This program adds one element to the user's array at his wanted index."<<endl;
	int size,index,value;
	cout<<"\nEnter the size of array : "; //inputting the size of array
	cin>>size;
	cout<<endl;
	int arr[size];
	for(int i=0;i<size;i++) //inputting the values of array
	{
		cout<<"Enter element at index "<<i<<" : ";
		cin>>arr[i];
	}
	cout<<"\nYour array is { "; //outputting the entered array
	for(int i=0;i<size;i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<"}";
	cout<<"\n\nEnter the index number where you want to add a value : "; //inputting the index where new element is to be added
	cin>>index;
	cout<<"\nEnter the value you want to add : "; //inputting new element
	cin>>value;
	for(int i=size+1;i>index;i--) //swapping all the values to the right and making space for the new value
	{
    arr[i]=arr[i-1];
    }
    arr[index]=value; //storing the new value to the index given by user
	cout<<"\nYour new array is { "; //outputting the new array
	for(int i=0;i<size+1;i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<"}";
}
