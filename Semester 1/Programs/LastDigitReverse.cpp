#include<iostream>
using namespace std;
int main()
{
	int num,reverse;
	cout<<"Enter a number: ";
	cin>>num;
	reverse=num%10;
	num=num/10;
	cout<<reverse<<num<<endl;
	system("pause");
}
