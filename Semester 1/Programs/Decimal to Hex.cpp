#include<iostream>
using namespace std;

hexToDec(long hexa[])
{
	long arr[7]={0,16,256,4096,65536,1048576,16777216};
	for(int i=0;hexa[i]!='\0';i++)
	{
		hexa[i]*=arr[i];
	}
}
decToHex(long number)
{
	while(number!=0)
	{
		cout<<number%16<<"  ";
		number=number/16;
	}
}
int main()
{
	long number;
	long hexa2[7];
	char hexa[7];
	int size=0,input;
	cout<<"Enter 1 to convert Hex to Dec, 2 for Dec to Hex : ";
	cin>>input;
	if(input==1)
	{
	cout<<"Enter the hexadecimal number (-1 to stop): ";
	for(int i=0;hexa[i]!=-1;i++)
	{
		cin>>hexa[i];
	}
	for(int i=0;hexa[i]!='\0';i++)
	{
		if(hexa[i]=='a'||hexa[i]=='A')
		{
			hexa2[i]=10;
		}
		else if(hexa[i]=='b'||hexa[i]=='B')
		{
			hexa2[i]=11;
		}
		else if(hexa[i]=='c'||hexa[i]=='C')
		{
			hexa2[i]=12;
		}
		else if(hexa[i]='d'||hexa[i]=='D')
		{
			hexa2[i]=13;
		}
		else if(hexa[i]=='e'||hexa[i]=='E')
		{
			hexa2[i]=14;
		}
		else if(hexa[i]=='f'||hexa[i]=='F')
		{
			hexa2[i]=15;
		}
		else
		{
			hexa2[i]=hexa[i];
		}
		size++;
	}
	hexToDec(hexa);
	for(int i=0;i<=size;i++)
	{
		cout<<hexa[i]<<"  ";
	}
	}
	else if(input==2)
	{
		cout<<"Enter a decimal number : ";
		cin>>number;
		decToHex(number);
	}
	else
	{
		return 0;
	}
}
