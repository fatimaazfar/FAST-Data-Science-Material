//this program sorts the array into largest and smallest number one after another
#include<iostream>
using namespace std;
void ascendsort(int arr[],int size) //function for sorting an array in ascending order
{
	for(int s=0;s<size;s++)
	{
		for(int i=0;i<size;i++)
	{
		if(arr[i+1]<arr[i] && i!=size-1)
		{
			int temp=arr[i];
		    arr[i]=arr[i+1];
		    arr[i+1]=temp;
		}
	}	
    }
}
void descendsort(int arr[],int size) //function for sorting an array in descending order
{
	for(int s=0;s<size;s++)
	{
		for(int i=0;i<size;i++)
	{
		if(arr[i+1]>arr[i] && i!=size-1)
		{
			int temp=arr[i];
		    arr[i]=arr[i+1];
		    arr[i+1]=temp;
		}
	}	
    }
}
int main() //main function
{
	cout<<"This program sorts the array into largest and smallest number one after another."<<endl;
	int size;
	cout<<"\nEnter the size of array : ";
	cin>>size;
	cout<<endl;
	int arr[size],ascend[size],descend[size];
	for(int i=0;i<size;i++) //inputting values in array
	{
		cout<<"Enter element in array : ";
		cin>>arr[i];
	}
		for(int i=0;i<size;i++) //copying values in other two arrays to later use them in sorting
	{
		ascend[i]=arr[i];
		descend[i]=ascend[i];
	}
	cout<<"\nThe array you entered is { "; //printing the original array
	for(int i=0;i<size;i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<"}";
	ascendsort(ascend,size); //calling functions
	descendsort(descend,size);
	int k=0,f=0; //initializing increment variables
	for(int i=0;i<size;i++) //storing the values in the original array according to the required sequence
	{
		arr[i]=descend[k];
		k++;
		arr[i+1]=ascend[f];
		f++;
		i++;
	}
	cout<<"\n\nThe sorted array is { "; //printing the final sorted array
	for(int i=0;i<size;i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<"}";
}
