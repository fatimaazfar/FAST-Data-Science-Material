//this program prints a series and outputs the sum of that series
#include<iostream>
using namespace std;
int main ()
{
int a=1,b=1,sum=0,n,i=1,c; //i is used as increment variable and c is used to store the multiplied values
cout<<"Enter the 'n' value : ";
cin>>n;
while(i<=n)	//this loop prints the series and their multiplied amount and sums all the results
{
c=a*b;
sum+=c;
cout<<a<<" * "<<b<<" = "<<c<<endl;
a++;
b++;
i++;
}
cout<<"Sum is equal to "<<sum;
}
