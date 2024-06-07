#include<iostream>
using namespace std;
int main()
{
 int a[5]={1,2,3,-1,6};
 cout<<"{1,2,3,-1,6}"<<endl;
 
 for(int i=0 ; i<5 ; i++)
 {
 	if(a[i]==-1)
 	{
 		int temp=a[i+1];
 		a[i+1]=a[i];
 		a[i]=temp;
	 }
}
 for(int i=0 ; i<5 ; i++)
 {
cout<<a[i]<<" ";
 }
}

