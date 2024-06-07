#include<iostream>
using namespace std;
int main()
{
char a=0; int b=0,sum=0,i=1; 
do
   {cout<<"please input a value to sum : ";
    cin>>a;
     { b=a;
	 if((b>=48 && b<=57))
       {
	    sum+=a;
	    i++;
	    }
	 else
	    i++; }
	    }while(i<=5);
cout<<"Sum is "<<sum;

}
