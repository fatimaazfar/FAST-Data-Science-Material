#include<iostream>
using namespace std;
int samevalues(int a[],int b[],int n)
{int k=0;
	for(int i=0; i<n ; i++)
	{
		for(int j=0; j<n ;j++)
		{
		if(a[i]==b[j])
		{
			cout<<a[i]<<" ";
		}
	    }
	}
	return k;
}
int main()
{
	int size=5;
	int a[size]={1,2,3,4,5};
	int b[size]={2,7,3,6,5};
	samevalues(a,b,size);
}
