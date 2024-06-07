#include<iostream>
using namespace std;
swapStrings(char a[],char b[],int sizea,int sizeb)
{
	int temp;
	temp=sizeb;
	for(int i=0;i<sizea;i++)
	{
		b[temp]=a[i];
		temp++;
	}
	temp=sizea;
	for(int i=0;i<sizeb;i++)
	{
		a[temp]=b[i];
		temp++;
	}
	temp=sizea;
	for(int i=0;i<sizeb;i++)
	{
		a[i]=a[temp];
		temp++;
	}
	a[sizeb]='\0';
	temp=sizeb;
	for(int i=0;i<sizea;i++)
	{
		b[i]=b[temp];
		temp++;
	}
	b[sizea]='\0';
}
int main()
{
	char arr1[3]={'a','b','c'},arr2[4]={'d','e','f','g'};
	cout<<"ARRAY 1 : a b c\nARRAY 2 : d e f g";
	swapStrings(arr1,arr2,3,4);
	cout<<"\nARRAY 1 : ";
	for(int i=0;i<4;i++)
	{
		cout<<arr1[i]<<" ";
	}
	cout<<"\nARRAY 2 : ";
	for(int i=0;i<3;i++)
	{
		cout<<arr2[i]<<" ";
	}
}
