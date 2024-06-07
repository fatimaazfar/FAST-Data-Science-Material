//this program takes the length of one side of a square and prints a square of that length 
#include<iostream>
using namespace std;
int main()
{
int length,i=1,j=0,k=1,l,m=1; //i,j,m,k are used as increment variables
cout<<"Enter the length of one side of the square between 1 and 20 : ";
cin>>length;
l=length-2;
if(length>0 && length<=20) //used for fulfilling the condition of staying between 1 and 20
{
while(i<=length) //this loop is used for printing first line
{
cout<<"*";	
i++;
}
cout<<endl;
while(k<=l) //this loop prints the asterisks along with spaces 
{j=1;
cout<<"*";
while(j<=l)
{
cout<<" ";
j++;
}
cout<<"*"<<endl;
k++;}
while(m<=length) //this loop prints the last line
{
cout<<"*";	
m++;
}
}
else
cout<<"Invalid input value."<<endl; 
}

