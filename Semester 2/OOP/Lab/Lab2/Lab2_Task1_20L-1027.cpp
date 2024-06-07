#include<iostream>
using namespace std;
int arrange(int a[],int b[],int size1,int size2,int c[],int size3)
{
	int j=0,k=size3-1;
	//this loop is for arranging the values of A in C
	for(int i=0;i<size1;i++)
	{
		if(a[i]%2==0)
		{
			c[j]=a[i];
			j++;
		}
		else
		{
			c[k]=a[i];
			k--;
		}
	}
	//this loop is for arranging the values of B in C
	for(int i=0;i<size2;i++)
	{
		if(b[i]%2==0)
		{
			c[j]=b[i];
			j++;
		}
		else
		{
			c[k]=b[i];
			k--;
		}
	}
}
int main()
{
	int M,N,S;
	cout<<"Enter the size of first array 'M': ";
	cin>>M;
	cout<<"Enter the size of second array 'N' : ";
	cin>>N;
	S=M+N;
	int *A=new int[M],*B=new int[N],*C=new int[M+N];
	cout<<"Enter the values of the first array of size "<<M<<" :"<<endl;
	for(int i=0;i<M;i++)
	{
		cin>>A[i];
	}
	cout<<endl;
	cout<<"Enter the values of the first array of size "<<N<<" :"<<endl;
	for(int i=0;i<N;i++)
	{
		cin>>B[i];
	}
	arrange(A,B,M,N,C,S);
	cout<<"The resulting array is : ";
	for(int i=0;i<S;i++)
	{
		cout<<C[i]<<" ";
	}
	delete[] A;
	delete[] B;
	delete[] C;
	A=NULL;
	B=NULL;
	C=NULL;
	return 0;
}
