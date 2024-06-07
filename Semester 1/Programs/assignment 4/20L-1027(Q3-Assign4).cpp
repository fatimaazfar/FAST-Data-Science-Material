//this program takes an array and outputs a sorted array in descending order of the frequency sequence of elements in array
#include<iostream>
using namespace std;
int main()
{
	cout<<"This program takes an array and outputs a sorted array in descending order of the frequency sequence of elements in array."<<endl;
	int size;
	cout<<"\nEnter size of the array : ";
	cin>>size;
	cout<<endl;
	int a[size],d[size];
	for(int i=0;i<size;i++)
	{
		cout<<"Enter element : ";
		cin>>a[i];
	}
	//printing the original array
		cout<<"\nThe array you entered is { ";
		for(int i=0;i<size;i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<"}";
	//storing the values of original array in a new array to use when making changes
		for(int i=0;i<size;i++)
	{
		d[i]=a[i];
	}
	//removing repeated values from a array
	for(int i=0;i<size;i++)
	{
		for(int j=i+1;j<size;j++)
		{
			if(a[i]==a[j])
			{
				a[j]=-1;
			}
		} 
	}
	//storing non-repeating values in u array
	int p=0,k=0,u[size];
	for(int j=0;j<size;j++)
	{
		if(a[j]!=-1)
		{
			u[p]=a[j];
			p++;
			k++;
		}
	}
	//storing the frequencies of corresponding elements of u array in freq array
	int freq[size],count=0;
		for(int i=0;i<k;i++)
	{   
		for(int j=0;j<size;j++)
		{
			if(u[i]==d[j])
			{
				count++;
			}
		} 
		freq[i]=count;
		count=0;
	}
	//printing the u array
	cout<<"\n\nThe array ('u') after removing repetition is { ";
	for(int i=0;i<k;i++)
	{
		cout<<u[i]<<" ";
	}
	cout<<"}";
	//printing the freq array
	cout<<"\n\nThe frequency array is { ";
	for(int i=0;i<k;i++)
	{
		cout<<freq[i]<<" ";
	}
	cout<<"}";
	//sorting the u array according to descending order of freq array
	for(int s=0;s<k;s++)
	{
		for(int i=0;i<k;i++)
	{
		if(freq[i+1]>freq[i] && i!=k-1)
		{
		   int temp=u[i];
		    u[i]=u[i+1];
		    u[i+1]=temp;
		    temp=freq[i];
		    freq[i]=freq[i+1];
		    freq[i+1]=temp;
		}
	}	
	}
	//printing the sorted u array
	cout<<"\n\nThe sorted 'u' array is { ";
	for(int i=0;i<k;i++)
	{
		cout<<u[i]<<" ";
	}
	cout<<"}";
	//printing the sorted frequency array
	cout<<"\n\nThe sorted (descending) frequency array is { ";
	for(int i=0;i<k;i++)
	{
		cout<<freq[i]<<" ";
	}	
	cout<<"}";
	//calculating and storing the size of result array in variable 'resize'
	int resize=0;
	for(int i=0;i<k;i++)
	{
	resize+=freq[i];
    }
    //storing values of u array in result array according to the frequency of each array
	int result[resize],j=0,q=0;
	for(int j=0;j<k;j++)
	{
        for(int i=0;i<freq[j];i++)
        {
		    result[q]=u[j];
		    q++;
	    }
    }
	cout<<"\n\nThe new result array is { ";
	for(int i=0;i<resize;i++)
	{
		cout<<result[i]<<" ";
	}
	cout<<"}";
}
