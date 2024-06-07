#include<iostream>
using namespace std;
int main()
{
int i=1,j=1,n; //i and j are used as increment variables
cout<<"Enter the value of 'n' : ";
cin>>n;	
while(j<=n)  //this loop is used as a counter for the number of lines printed
{
i=1;	
while(i<=n) //this loop is used as a counter for asterisks printed per line
{
cout<<"*";	
i++;
}
cout<<endl;	
j++;
}
}
