//this program sorts the array according to the even and odd index number
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
	cout<<"This program sorts the input array according to the even and odd index numbers."<<endl;
	int size=0,arr[100],ascend[100],descend[100];
	cout<<"\nEnter -1 to stop storing elements.\n\n";
	for(int i=0; ;i++) //inputting values in array
	{
		cout<<"Enter element in array : ";
		cin>>arr[i];
		size++;
		if(arr[i]==-1) //breaking loop when user enters -1
		{
			break;
		}
	}
	cout<<"\nThe array you entered is { "; //printing the original array
	for(int i=0;i<size-1;i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<"}";
	int j=0,k=0;
    for(int i=0;i<size-1;i++) //seperating even and odd index values in separate arrays
    {
        if(i%2==0)
        {
        	ascend[j]=arr[i];
        	j++;
		}
		else
		{
			descend[k]=arr[i];
			k++;
		}
	}
	ascendsort(ascend,j); //calling functions
	descendsort(descend,k);
	j=0; k=0;
	 for(int i=0;i<size-1;i++) //re-storing the separated arrays back in original array after sorting
    {
        if(i%2==0)
        {
        	arr[i]=ascend[j];
        	j++;
		}
		else
		{
			arr[i]=descend[k];
			k++;
		}
	}
	cout<<"\n\nThe sorted array is { "; //printing the final sorted array
	for(int i=0;i<size-1;i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<"}";
}
