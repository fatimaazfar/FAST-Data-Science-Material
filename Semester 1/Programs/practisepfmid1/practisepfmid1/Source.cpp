#include<iostream>
using namespace std;
int main()
{
int number,remainder;
float fir_val,sec_val,third_val,forth_val;

cout<<"please enter the four didit number "<<endl;
cin>>number;
fir_val=number/1000;
remainder=number%1000;

sec_val=remainder/100;
remainder=remainder%100;

third_val=remainder/10;
remainder=remainder%10;

forth_val=remainder;

if(fir_val==forth_val&&sec_val==third_val)
{
cout<<"this is good bro"<<endl;
}
else
{
cout<<"nkl"<<endl;
}
system("pause");
}