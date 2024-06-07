#include<iostream>
using namespace std;
int main()
{
	int arr[14]={3,7,4,6,2,5,1,8,10,9,13,11,14,12};
	for(int s=0;s<14;s++)
	{
		for(int i=0;i<14;i++)
	{
		if(arr[i+1]>arr[i] && i!=13)
		{
			int temp=arr[i];
		    arr[i]=arr[i+1];
		    arr[i+1]=temp;
		}
	}	
	}
		for(int i=0;i<14;i++)
	{
        cout<<arr[i]<<" ";
	}
}
