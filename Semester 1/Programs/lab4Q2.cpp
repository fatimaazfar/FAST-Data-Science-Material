#include<iostream>
using namespace std;
int main()
{
	int amount=0;
	cout<<"Enter an amount : ";
	cin>>amount;
	int h=amount/100;
	int remain=amount%100;
    int f=remain/50;
	remain=remain%50;
	int t=remain/10;
	int o=remain%10;
	cout<<h<<" notes of hundred."<<endl;
	cout<<f<<" notes of fifty."<<endl;
	cout<<t<<" notes of ten."<<endl;
	cout<<o<<" notes of one."<<endl;
}
