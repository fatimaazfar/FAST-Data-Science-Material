#include<iostream>
using namespace std;
char symbol[7]={'I','V','X','L','C','D','M'};
int value[7]={1,5,10,50,100,500,1000};
int findindex(char ch)
{
	int index=-1;
	for(int i=0;i<7;i++)
	{
		if(ch==symbol[i])
		{
			index=i;
		}
	}
	return index;
}
int romantoarabic(char romannum[])
{
	int sum=0,index[10]={},size=0;
	for(int i=0;romannum[i]!='\0';i++)
	{
		index[i]=findindex(romannum[i]);
		size++;
	}
	for(int i=0;i<=size;i++)
	{
		if(index[i]>=index[i+1])
		{
			sum=sum+value[index[i]];
		}
		else
		{
			sum=sum-value[index[i]];
		}
	}
	return sum;
}
int main()
{
	char romannum[20]=" ";
	cout<<"Enter a number in roman numerals : ";
	cin>>romannum;
	cout<<"Number in Arabic is : "<<romantoarabic(romannum)<<endl;
	return 0;
}
