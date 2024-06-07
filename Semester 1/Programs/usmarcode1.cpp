#include<iostream>
using namespace std;
int main()
{
	int size=0,minswap=0;
	cout<<"Enter size : ";
	cin>>size;
	int a[size];
	cout<<"Enter elements in array : "<<endl;
	for(int i=0;i<size;i++)
	{
		cin>>a[i];
	}
	cout<<"\nOriginal array is : ";
	for(int i=0;i<size;i++)
	{
		cout<<a[i]<<" ";
	}
	//fibonacci sorting
	int index=0;
	for(int i=0;i<size;i++)
	{
	int f=0, c=0, b=1;
	while(f<a[i])
	{
		f=c+b;
		c=b; 
		b=f;
	}
	if(f==a[i])
    {
    	int swap=a[index];
		a[index]=a[i];
		a[i]=swap;
		index++;
		minswap++;
	}
    }
    //prime sorting
    int index2=size-1,ans;
    for(int i=index2;i>=index;i--)
    {   ans=0;
    	for (int j = 2; j <= a[i]; j++)
	    {
		if (a[i] % j == 0)
		  {
		  ans++;
	      }
		}
		if(ans==1)
		{
	    int swap=a[index2];
		a[index2]=a[i];
		a[i]=swap;
		index2--;
		minswap++;
		}
	}	
	cout<<"\nSorted array is : ";
	for(int i=0;i<size;i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<"\nFibonacci elements : ";
	for(int i=0;i<index;i++)
	{
		cout<<a[i]<<" ";
	}	
	cout<<"\nNon-PrimeFibonacci elements : ";
	for(int i=index;i<=index2;i++)
	{
		cout<<a[i]<<" ";
	}		
	cout<<"\nPrime elements : ";
	for(int i=index2+1;i<size;i++)
	{
		cout<<a[i]<<" ";
	}	
	cout<<"\nMinimum swap count : "<<minswap/2+1;	
}
