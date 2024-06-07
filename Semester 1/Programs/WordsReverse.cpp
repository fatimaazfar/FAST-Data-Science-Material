#include<iostream>
#include<cstring>
using namespace std;
Reverse(char a[],int start,int length)
{
	char rev[50];
	for(int i=start;i<length;i++)
	{
		rev[i]=a[i];
	}
	for(int i=length-1,j=0;i>0,j<length;i--,j++)
	{
		a[j]=rev[i];
	}
}
sentenceReverse(char a[],int length,int spaces)
{
	char rev[100];
	int size=0,size2=0;
	for(int s=0;s<=spaces+1;s++)
	{
	for(int i=size;i<=length;i++)
	{
		if(a[i]==' ')
		{
			break;
		}
		rev[i]=a[i];
		size2++;
	}
	Reverse(rev,size,size2);
	for(int i=size;i<size2;i++)
	{
		a[i]=rev[i];
	}
	size2++;
	size=size2;
	}
}
main()
{
	char a[100];
	int spaces;
	cout<<"Enter array : ";
	cin.getline(a,100,'\n');
	int length=strlen(a);
	for(int i=0;i<length;i++)
	{
		if(a[i]==' ')
		{
		spaces++;
		}
	}
	sentenceReverse(a,length,spaces);
	for(int i=0;i<length;i++)
	{
		cout<<a[i];
	}
}
