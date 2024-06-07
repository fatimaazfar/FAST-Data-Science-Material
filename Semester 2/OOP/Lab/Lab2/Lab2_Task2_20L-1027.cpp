#include<iostream>
using namespace std;
//this function allocates a new array everytime the user exceeds size 5 in dynamic memory
int newarray(int a[],int temp[],int size)
{
	delete[] a;
	a=new int[size];
	for(int i=0;i<size;i++)
	{
		a[i]=temp[i];
	}
}
//this function inputs the array and stops when -1 is entered
int inputArray(int a[],int &size)
{
	int temp[size],size1=0;
	for(int i=0;i<=size;i++)
	{
		cin>>a[i];
		size1++;
		temp[i]=a[i];
		if(i==size && a[i]!=-1)
		{
			size+=5;
			newarray(a,temp,size);
		}
		else if (a[i]==-1)
		{
			size=size1-1;
			return 0;
		}
	}
}
int main()
{
	int size=5;
	int* A=new int[size];
	cout<<"Enter the elements in Array (-1 to stop) : "<<endl;
	inputArray(A,size);
	cout<<"Your Array is : ";
	for(int i=0;i<size;i++)
	{
		cout<<A[i]<<" ";
	}
	delete[] A;
	A=NULL;
	return 0;
}
