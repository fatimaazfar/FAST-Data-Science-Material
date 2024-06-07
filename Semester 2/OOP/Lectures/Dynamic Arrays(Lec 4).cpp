//this program shrinks,expands the size of and deletes,replaces an element from dynamic arrays
#include<Iostream>
using namespace std;
main()
{
	int size;
	cout<<"Enter the size of array : ";
	cin>>size;
	int *arp=new int[size];
	cout<<"Enter the elements of array : \n";
	for(int i=0;i<size;i++)
	{
		cin>>arp[i];
	}
	cout<<"Your current array is : ";
	for(int i=0;i<size;i++)
	{
		cout<<arp[i]<<" ";
	}
	again:
	int add,sub,input;
	cout<<"\n\nEnter\n1 for extending array\n2 for shrinking it\n3 to replace an element\n4 to delete some element\n5 to exit : ";
	cin>>input;
	//EXPAND ARRAY IN SIZE
	if(input==1)
	{
	cout<<"\nHow many elements do you want to add? : ";
	cin>>add;
	int newsize=size+add;
	int *arp2=new int[newsize];
	for(int i=0;i<size;i++)
	{
		arp2[i]=arp[i];
	}
	cout<<"Enter the elements : \n";
	for(int i=size;i<newsize;i++)
	{
		cin>>arp2[i];
	}
	cout<<"Your extended new array is : ";
	for(int i=0;i<newsize;i++)
	{
		cout<<arp2[i]<<" ";
	}
	arp=arp2;
	size=newsize;
	delete[] arp2;
	arp2=0;
	goto again;
	}
	//SHRINK ARRAY IN SIZE
	else if (input==2)
	{
		cout<<"\nHow many elements do you want to subtract? : ";
	cin>>sub;
	int newsize=size-sub;
	int *arp2=new int[newsize];
	for(int i=0;i<newsize;i++)
	{
		arp2[i]=arp[i];
	}
	cout<<"Your shrinked new array is : ";
	for(int i=0;i<newsize;i++)
	{
		cout<<arp2[i]<<" ";
	}
	arp=arp2;
	size=newsize;
	delete[] arp2;
	arp2=0;
	goto again;
	}
	//REPLACE AN ELEMENT FROM ARRAY 
	else if (input==3)
	{
		int element,repelement;
		cout<<"What element do you want to replace? : ";
		cin>>element;
		cout<<"With what element do you want to replace it? : ";
		cin>>repelement;
		for(int i=0; i<size ;i++)
		{
			if(arp[i]==element)
			{
				arp[i]=repelement;
			}
		}
		for(int i=0; i<size ;i++)
		{
			cout<<arp[i]<<" ";
		}
		goto again;
	}
	//DELETE AN ELEMENT FROM ARRAY 
	else if(input==4)
	{
		int element,count=0;
		cout<<"What element do you want to delete? : ";
		cin>>element;
		for(int i=0; i<size ;i++)
		{
			if(arp[i]==element)
			{
				count++;
			}
		}
		int newsize=size-count;
		int *arp2=new int[newsize];
		for(int i=0,j=0; i<size ;i++)
		{
			if(arp[i]!=element)
			{
				arp2[j]=arp[i];
				j++;
			}
		}
		for(int i=0; i<newsize ;i++)
		{
			cout<<arp2[i]<<" ";
		}
		arp=arp2;
		size=newsize;
		delete[] arp2;
		arp2=0;
		goto again;
	}
	else
	{
		delete[] arp;
		*arp=0;
		return 0;
	}
	delete[] arp;
	*arp=0;
}
