#include<iostream>
using namespace std;
arraySort(int a[],int size)
{
	for(int i=0;i<size;i++)
	{
		for(int j=i+1;j<size;j++)
		{
			if(a[i]>a[j])
			{
				int temp=a[i];
				a[i]=a[j];
				a[j]=temp;
			}
		}
	}
}
int main()
{
	int a[5];
	cout<<"Enter elements : "<<endl;
	for(int i=0;i<5;i++)
	{
		cin>>a[i];
	}
	arraySort(a,5);
	for(int i=0;i<5;i++)
	{
		cout<<a[i]<<" ";
	}
}
