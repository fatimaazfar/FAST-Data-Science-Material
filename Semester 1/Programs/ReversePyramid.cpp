#include<iostream>
using namespace  std;
int main()
{
int h,l,i=1,p=2,m=1,j=1;	
cout<<"Enter the height of the reverse pyramid : ";
cin>>h;
l=h+h;
while(i<=h)
{l-=m;
m++;
while(l>=0)
{
cout<<"*";
l--;
}
cout<<endl;
while(j<=p && p<=h)
{
cout<<" ";
j++;	
}
p++;
i++;
}
}
