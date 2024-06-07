//this program prints whether the number user entered has three consecutive multiples or not
#include<iostream>
using namespace std;
int main()
{
int num,a=1,b=2,c=3,product=0;	
cout<<"Enter a number : ";
cin>>num;
while(product<num) //this loop checks the three consecutive multiples of the number entered
{
product=a*b*c;
if(product!=num)
{
a++;
b++;
c++;	
}
}
if(product==num)
{cout<<"The three consecutive multiples for your number are "<<a<<" , "<<b<<" and "<<c<<endl;}
else
{cout<<"The number you entered does not have three consecutive multiples."<<endl;}
}
