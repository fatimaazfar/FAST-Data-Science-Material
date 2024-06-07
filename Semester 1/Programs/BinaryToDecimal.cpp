#include<iostream>
using namespace std;

int main()
{
	// this program converrts binary to denary

	int num=0,count=1,denary=0,flag=0;
	
	while (flag!=1)
	{
		cout<<"input num"<<endl;
		cin>>num;
		if (num<0)
		{
			flag=1;
		}
		else
		{
			denary += (count*num);
			count *=2;
		}
		
	}
	cout<<denary<<endl;
	system("pause");
	
}
