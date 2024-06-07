#include<iostream>
using namespace std;
int main()
{
  int a[5]={-1,5,8,9,10},b[6]={1,2,3,4,6,7},c[11]={1,2,3,5,4,8,11,7,6,10,9},j=0;
  /*for(int i=0 ; i<11 ; i++)
  { 
  	if(a[i]>b[i])
  	{
  		c[j]=b[i];
  		j++;
  		c[j]=a[i];
  		j++;
	}
	else if(a[i]<b[i])
	{
		c[j]=a[i];
		j++;
		c[j]=b[i];
		j++;
	}
  }*/
     for(int i=0 ; i<11 ; i++)
  {
     if(c[i]>c[i+1])
     {
     	int temp=c[i];
     	c[i]=c[i+1];
     	c[i+1]=temp;
	 }
  }
    for(int i=0 ; i<11 ; i++)
  {
     cout<<c[i]<<" ";
  }
}
