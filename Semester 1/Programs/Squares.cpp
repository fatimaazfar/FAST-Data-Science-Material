//this program prints the squareroots of all the odd numbers from 1 to 25
#include<iostream>
using namespace std;
int main()
{
float squareroot,i=1;	
while(i<=25)
{squareroot=(1+i)/4 + i/(1+i);
cout<<"Squareroot of "<<i<<" is "<<squareroot<<"   "<<endl;
i+=2;}}

