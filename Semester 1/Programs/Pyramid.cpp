#include<iostream>
using namespace  std;
int main()
{
	int h,k=2,i,m=1,n=1;
	cout<<"Enter the height of the pyramid : ";
	cin>>h;
	while(m<=h)
	{ i=h-n; 
	while(i>=1) 
		{	
		cout<<" ";
		i--;
	    }    
	for(int j=1 ; j<k ; j+=2)
	    {
	      cout<<"*";
		}
		k+=4;
	    cout<<endl;
	    m++; 
	    n++;
    }
}
