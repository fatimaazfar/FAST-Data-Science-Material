#include<iostream>
using namespace std;
int main()
{
	float a=0,b=0,c=0;
cout<<"Enter your first integer: "<<endl;
cin>>a;
cout<<"Enter your second integer: "<<endl;
cin>>b;
cout<<"Enter your third integer: "<<endl;
cin>>c;
if (a>b && b>c)
{cout<<"Ascending order: "<<c<<" "<<b<<" "<<a<<endl;
cout<<"Descending order: "<<a<<" "<<b<<" "<<c;}
else if (b>a && a>c)
{cout<<"Ascending order: "<<c<<" "<<a<<" "<<b<<endl;
cout<<"Descending order: "<<b<<" "<<a<<" "<<c<<endl;}
else if (c>b && b>a)
{cout<<"Ascending order: "<<a<<" "<<b<<" "<<c<<endl;
cout<<"Descending order: "<<c<<" "<<b<<" "<<a<<endl;}
else if (c>a && a>b)
{cout<<"Ascending order: "<<b<<" "<<a<<" "<<c<<endl;
cout<<"Descending order: "<<c<<" "<<a<<" "<<b<<endl;}
else if (a>c && c>b)
{cout<<"Ascending order: "<<b<<" "<<c<<" "<<a<<endl;
cout<<"Descending order: "<<a<<" "<<c<<" "<<b<<endl;}
else if (b>c && c>a)
{cout<<"Ascending order: "<<a<<" "<<c<<" "<<b<<endl;
cout<<"Descending order: "<<b<<" "<<c<<" "<<a<<endl;}
else if (a==b && b==c)
{cout<<"All values are equal."<<endl;}
else
{cout<<"Two values are equal."<<endl;}
system("pause");
}
