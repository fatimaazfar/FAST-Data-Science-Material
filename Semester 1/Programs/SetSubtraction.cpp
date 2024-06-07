//this program prints the set subtraction of two sets
#include<iostream>
using namespace std;
//function for set subraction
int setSubtraction(int a[], int n, int b[], int m ,int c[])
{ int d[n];
 for(int i=0; i<n ;i++)//storing all values of array a in new array d
{ 
  d[i]=a[i];
}
	int k=0;
for(int i=0 ; i<n ; i++)
{
  for(int j=0 ; j<m ; j++)//if values are same  store 0 instead if them in first array 'a'
   {
   	if(d[i]==b[j])
   	{ d[i]=0;}
   }
} 
for(int i=0; i<n ;i++)//store all the non zero values of array a in array c
{ 
  if(d[i]!=0)
  {c[k]=d[i];
   k++;}
}
return k;
}

int main()
{
int size;	
int A[6] = { 1, 2, 4, 5, 8, 19 };
int B[5] = { 1, 2, 5, 7, 8 };
int C[11];

size=setSubtraction(A, 6, B, 5, C); //calling function
cout<<endl<<"The size of the subtracted set (A-B) is "<<size<<endl;
cout << "The subtracted values of B from A (A-B) are ";
for(int i=0 ; i<size ; i++)
{ cout<<C[i]<<" ";} 

size=setSubtraction(B, 5, A, 6, C);//calling functiom
cout<<endl<<"The size of the subtracted set (B-A) is "<<size<<endl;
cout << "The subtracted values of A from B (B-A) are ";
for(int i=0 ; i<size ; i++)
{ cout<<C[i]<<" ";}
cout<<endl;

system("pause");
}

