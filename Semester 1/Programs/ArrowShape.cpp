//this program takes an input from the user and prints an arrow shape 
#include<iostream>
using namespace std;
int main()
{
int n,i=1,j=1,k=1,m=1; //i,j,k,m are all used as increment variables
cout<<"Enter the value of 'n' : ";
cin>>n;
while(m<=n) //this loop is used to print first 'n' lines
{
while(i<=j)
{cout<<"*";
i++;}
k++;
j+=k;
cout<<endl;
m++;
}
//reassigning the value 1 to all the increment variables to use them again
m=1; 
k=1;
while(m<=n) //this loop is used to print next reversed 'n' lines
{i=1;
while(i<=n-k)
{cout<<"*";
i++;}
k++;
m++;
cout<<endl;	
}
}
