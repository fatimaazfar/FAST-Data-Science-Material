#include<iostream>
using namespace std;
int main()
{
	int weight,w1=1,w2=1,w3=1;
	cout<<"Enter the weight of the 3 stones : ";
	cin>>weight;
	if(weight>2)
	{
		while(w1>0 && w2>0)
	   {cout<<w1;
	   w2=weight-(w1+1);
	   if(w2>0)
	   {cout<<","<<w2;
	   w3=weight-(w1+w2);
	   cout<<","<<w3<<endl;
	   w1++;}}
	system("pause");
	
	}
}
