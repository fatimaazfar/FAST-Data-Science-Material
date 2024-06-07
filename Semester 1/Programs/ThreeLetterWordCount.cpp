#include<iostream>
using namespace std;
int main()
{
	char a[10];
	int count=0,letter3=0;
	cout<<"Enter : ";
	cin.getline(a);
	cout<<a;
	for(int j=0;a[j]!='\0';j++)
	{count=0;
	for(int i=0;i<10;i++)
	{
		if(a[i]==' ')
		{
			break;
		}
		count++;
	}
	if(count==3)
	{
		letter3++;
	}
	}
	cout<<"Three letter words are "<<letter3<<endl;
}
