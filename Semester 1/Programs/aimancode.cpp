#include<iostream>
 
using namespace std;
 
int main()
{
	int i,j,k,size;
	cout<<"Enter the size of array: ";
	cin>>size;
	int array[size];
	cout<<"\nEnter the elements of array\n";
	for(i=0;i<size;++i)
	{cin>>array[i];	}	
		
	for(i=0;i<size;++i)
	{	
		for(j=i+1;j<size;j++)
		{
			if(array[i]==array[j])
			{ array[j]=-1;}
		}
	}
	
    cout<<"\n";
	for(i=0;i<size;++i)
	{cout<<array[i]<<" ";
		}	
 
}
