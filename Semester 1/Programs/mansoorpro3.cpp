#include<iostream>
using namespace std;
int setSubtraction (int a[], int size1, int b[], int size2, int c[])
{
int newarr[size1];	
for(int i=0;i<size1;i++)
{
	newarr[i]=a[i];
}	
int z=0;
for(int i=0;i<size1;i++)
{
for(int j=0;j<size2;j++)
{
if(newarr[i]==b[j])
{
newarr[i]=-1;
}
}
}
for(int i=0;i<size1;i++)
{
if( newarr[i]!=-1)
{
c[z]=newarr[i];
z++;
}
}
return z;
}
int main()
{
int size;
int A[6] = { 1, 2, 4, 5, 8, 19 };
int B[5] = { 1, 2, 5, 7, 8 };
int C[11];
size = setSubtraction(A, 6, B, 5, C);
cout<<"the size of the subtracttion of B from A (A-B) is = "<<size;
cout << "\n\n\nThe subtraction of B from A (A-B) is = ";
for(int i=0;i<size;i++)
{
cout<<C[i]<<"\t";
}
cout<<endl;
size=setSubtraction(B, 5, A, 6, C);
cout<<"\n\n\nthe size of the subtration of A from B (B-A) is"<<size;
cout << "\n\n\nThe subtraction of A from B (B-A) is"<<endl;
for(int i=0;i<size;i++)
{
cout<<C[i]<<"\t";
}
system("pause");
}
