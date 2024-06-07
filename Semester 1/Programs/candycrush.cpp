#include<iostream>
using namespace std;
int main()
{
	char a[5][5]={{'e','o','e','v','o'},
	              {'e','e','v','o','e'},
				  {'o','o','e','v','o'},
				  {'o','e','v','o','e'},
				  {'o','v','o','v','o'}};
	int temp[5],k=0;
	cout<<"Your array is "<<endl;
	for(int i=0;i<5;i++)
	{
		for(int j=0;j<5;j++)
		{
			cout<<a[i][j]<<"	";
		}
		cout<<endl;
	}
	for(int i=0;i<5;i++)
	{
		for(int j=0;j<5;j++)
		{
			if(a[i][j]==a[i][j+1] && a[i][j]==a[i][j+2])
			{
				a[i][j]='x';
				a[i][j+1]='x';
				a[i][j+2]='x';
			}
			if(a[i][j]==a[i+1][j] && a[i][j]==a[i+2][j])
			{
				a[i][j]='x';
				a[i+1][j]='x';
				a[i+2][j]='x';
			}
		}
	}
	cout<<"\nNew array : "<<endl;
	for(int i=0;i<5;i++)
	{
		for(int j=0;j<5;j++)
		{
			cout<<a[i][j]<<"	";
		}
		cout<<endl;
	}
}
