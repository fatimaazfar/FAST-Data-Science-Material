//this program sorts array in sequence of fibonacci, nonprimefibonacci and then prime numbers
#include<iostream>
using namespace std;
//function for checking if a number is fibonacci or not
int fibonacci(int num)
{
	int f=0, a=0, b=1;
	while(f<num)
	{
		f=a+b;
		a=b;
		b=f;
	}
    if(f==num)
    {
    	return 1;
	}
	else
	{
		return 0;
	}
}
//function of checking if a number is prime or not
int prime(int num)
{
	int j=0,k=0;
	for (k = 2; k <= num; k++)
	{
		if (num % k == 0)
		j = j + 1;
	}
	
	if (j == 1)
    {
    	return 1;
	}
	else
	{
	return 0;
    }
}
//main function
int main()
{
	int temp=0,index=0,size;
	cout<<"This program sorts array in sequence of fibonacci, nonprimefibonacci and then prime numbers."<<endl;
	cout<<"\nEnter the size of array : ";
	cin>>size;
	cout<<endl;
	int a[size],copyarr[size]; //copy array will be used to check swap count
	//storing users' elements in array
	for(int i=0;i<size;i++)
	{
		cout<<"Enter element : ";
		cin>>a[i];
		copyarr[i]=a[i];
	}
	//printing original array
	cout<<"\nThe original array is { ";
	for(int i=0;i<size;i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<"}";
	int f=0;
	//this loop swaps all fibonacci numbers including the prime fibonacci to the start of array
	for(int i=0;i<size;i++) 
	{
		int f=fibonacci(a[i]); //calling functions
		int p=prime(a[i]);
		if(f==1)
		{
			temp=a[index];
			a[index]=a[i];
			a[i]=temp;
			index++;
		}
	}
	f=index;
	//this loop swaps all non-primefibonacci numbers to the middle of array
	for(int i=index;i<size;i++)
	{
	    int f=fibonacci(a[i]); //calling functions
		int p=prime(a[i]);
		if(f==0 && p==0)
		{
		    temp=a[index];
			a[index]=a[i];
			a[i]=temp;
			index++;
		}
	}
    int npf=index;
	//this loop swaps all non-fibonacci prime numbers to the end of array
	for(int i=index;i<size;i++)
	{
		int p=prime(a[i]); //calling functions
		int f=fibonacci(a[i]);
		if(p==1)
		{
		    temp=a[index];
			a[index]=a[i];
			a[i]=temp;
			index++;	
		}
	}
	int p=index;
	//calculating  the swap count by comparing the sorted array with the copy of original array
	int swapcount=0;
	for(int i=0; i<size ; i++)
	{
		if(a[i]!=copyarr[i])
		{
			swapcount++;
		}
	}
	swapcount=swapcount/2+1;	
	//printing the sorted array
	cout<<"\n\nThe sorted array is { ";
	for(int i=0;i<size;i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<"}";
	//printing the parts of array seperately
	cout<<"\n\nThe fibonacci elements are { ";
	for(int i=0;i<f;i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<"}";
	cout<<"\n\nThe non-prime-fibonacci elements are { ";
	for(int i=f;i<npf;i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<"}";
	cout<<"\n\nThe only prime elements are { ";
	for(int i=npf;i<p;i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<"}";
	//printing the minimum swap count
	cout<<"\n\nThe minimum swap count is "<<swapcount<<endl;
}
