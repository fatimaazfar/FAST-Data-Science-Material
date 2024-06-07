#include<iostream>
using namespace std;
int main ()
{ int a;
double d,b,s;
char c;
cout<<"Enter: 1 for Chicken Handi : 2 for Chicken Karahi : 3 for Chicken Tikkha : 4 for Chicken Haleem : 5 for Creamy Chicken : ";
cin>>a;
if (a>=1 && a<=5)
{ if (a==1)
 d=1800;
else if (a==2)
 d=2000;
else if (a==3)
 d=2200;
else if (a==4)
 d=500;
else 
 d=2500;}
else
	cout<<"Invalid code."<<endl;
if (a>=1 && a<=5)
	cout<<"Enter amount in KGs: ";
    cin>>b;
if ((a>=1 && a<=5) && (b>=1))
{d*=b;
if (d<=1000)
	s=0;
else if (d>1000 && d<=3000)
	s=d*0.02;
else 
	s=d*0.05;}
if (b<1)
	cout<<"Invalid amount."<<endl;
else 
	{cout<<"Enter R for price in Rs. : D for dollars : E for euros : ";
    cin>>c;
	if (c=='r'|| c=='R')
		cout<<"Price: Rs."<<d<<endl<<"Tax: Rs."<<s<<endl<<"Total price: Rs."<<(s+d)<<endl;
	else if (c=='d'|| c=='D')
		cout<<"Price: $"<<(d/165)<<endl<<"Tax: $"<<(s/165)<<endl<<"Total price: $"<<(s+d)/165<<endl;
	else if (c=='e'|| c=='E')
		cout<<"Price: €"<<(d/193)<<endl<<"Tax: €"<<(s/193)<<endl<<"Total price: €"<<(s+d)/193<<endl;
    else
		cout<<"Invalid code."<<endl;}
system("pause");
}
