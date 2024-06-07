#include<iostream>
using namespace std;
int main ()
{
int a=1,b=1,n=1,l,c=2,f=0,h=1;
cout<<"Enter limit of rows : ";
cin>>l;
f=l/2+0.5;
h=f-1;
while(n<=l)
{ int d=1;
while(a>=b)
{ 
while(f>h)
{ cout<<d<<" ";
    d+=2;
    h++;
	 }
h--;
b++;
}
a+=c;
c++;
cout<<endl;
n++;
}
}
