#include<iostream>
using namespace std;
main ()
{
int withdraw, n, remain, i;
cout<<"Enter the amount you want to withdraw (must be a mulitple of 500): ";
cin>>withdraw;
while(remain>0)
  {
   if(withdraw>=5000)
     {
	  n=withdraw/5000;
      remain=withdraw%5000;
      withdraw=remain;
      i=5000;
	 }
   else if(withdraw<5000 && withdraw>=1000)
     {
	  n=withdraw/1000;
	  remain=withdraw%1000;
      withdraw=remain;
	  i=1000;}
   else
     {
	  n=withdraw/500;
	  remain=withdraw%500;
      withdraw=remain;
	  i=500; }
   cout<<n<<" notes of "<<i; }      	  			
}


