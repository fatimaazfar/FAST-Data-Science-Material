#include<iostream>
using namespace std;
matmul(int arr1[][10],int r1,int c1,int arr2[][10],int r2,int c2,int result[][10],int r3,int c3)
{
	for(int i=0;i<r1;i++)
	{
		for(int j=0;j<c2;j++)
		{
			result[i][j]=arr1[i][j]*arr2[i][j];
			c3++;
		}
		r3++;
	}
}
main()
{
	int m1,n1,m2,n2,m3,n3;
	int arr1[m1][n1],arr2[m2][n2],res[m3][n3];
	cout<<"Enter the number of rows in first matrix : ";
	cin>>m1;
	cout<<"Enter the number of columns in first matrix : ";
	cin>>n1;
	cout<<"Enter the number of rows in second matrix : ";
	cin>>m2;
	cout<<"Enter the number of columns in second matrix : ";
	cin>>n2;
	cout<<"Enter the elements in the first matrix :\n";
	for(int i=0;i<m1;i++)
	{
		for(int j=0;j<n1;j++)
		{
			cin>>arr1[i][j];
		}
	}
	cout<<"Enter the elements in the second matrix :\n";
	for(int i=0;i<m2;i++)
	{
		for(int j=0;j<n2;j++)
		{
			cin>>arr2[i][j];
		}
	}
	matmul(arr1,m1,n1,arr2,m2,n2,res,m3,n3);
	for(int i=0;i<m3;i++)
	{
		for(int j=0;j<n3;j++)
		{
			cout<<res[i][j]<<" ";
		}
	}
}
