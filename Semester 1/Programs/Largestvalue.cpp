#include<iostream>
using namespace std;
int main()
{
float number=0;
int large=0,small=65536;
while(number!=-1)
{ cout<<"please enter the numbers and press -1 if u want to exit from putiing values : ";
cin>>number;
if(number>large)
{
large=number;
}

if(number<small && number!=-1)
{
small=number;
}
}
cout<<"largest number is : "<<large<<endl;
cout<<"smallest number is : " <<small;
}
