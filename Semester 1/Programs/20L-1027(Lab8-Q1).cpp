#include<iostream>
using namespace std;
void distinct(int a[], int num)
{
for (int i=0; i<num; i++)
{
int j;
for (j=0; j<i; j++)
if (a[i] == a[j])
break;
if (i == j)
{
cout << a[i] <<" ";
}
}
}
int main()
{
	int size=0;
	int arraysize=20;
	int arr[arraysize],arr2[arraysize];
	for(int i=0;i<arraysize;i++) //inputting values in array
	{
		cout<<"Enter element in array (-99 for exit): ";
		cin>>arr[i];
		arr2[i]=arr[i];
		if(arr[i]==-99)
		{
			break;
		}
		size++;
	}
	cout<<"\nThe array you entered is { "; //printing the original array
	for(int i=0;i<size;i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<"}";
	cout<<"\nThe distinct elements in array are { "; //printing the distinct array
    distinct(arr,size);
    cout<<"}"; 
    for(int i=0; i<size; i++)
    {
        // Assuming  cuurent element is unique */
        int Unique = 1;
 
        for(int j=i+1; j<size; j++)
        {
 
            //If any duplicate element is found
 
            if(arr2[i]==arr2[j])
            {
                // Removing duplicate element
                for(int k=j; k<size-1; k++)
                {
                    arr2[k] = arr2[k+1];
                }
 
                size--;
                j--;
                Unique = 0;
            }
        }
 
        /*
        If array element is not unique
        then also remove the current element
         */
        if(Unique != 1)
        {
            for(int j=i; j<size-1; j++)
            {
                arr2[j] = arr2[j+1];
            }
 
            size--;
            i--;
        }
    }
    //Printing all unique elements in array
    cout<<"\nThe unique elements in the array are: { ";
    for(int i=0; i<size; i++)
    {
       cout<<arr2[i]<<" ";
    }
    cout<<"}";
}
