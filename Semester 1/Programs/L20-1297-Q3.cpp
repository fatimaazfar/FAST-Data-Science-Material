#include<iostream>
using namespace std;

int setSubtraction(int arr1[],int size1,int arr2[],int size2,int c[])
{
	int index = 0;
	for(int i=0;i<size1;i++)
	{
		bool found = false;
		for(int j=0;j<size2;j++)
		{
			if(arr1[i] == arr2[j])
			{
				found = true;
			}
		}
		if(found == false)
		{
			c[index] = arr1[i];
			index++;
		}
	
	}
	return index;
}

int main()
{
	
	int A[6] = { 1, 2, 4, 5, 8, 19 }; 
    int B[5] = { 1, 2, 5, 7, 8 };
	int C[11]; 
	
	int size = setSubtraction(A, 6, B, 5, C);  
	cout << "\n\n\nThe subtraction of B from A (A-B) is"<<endl;  
	for(int i=0;i<size;i++)
	{
		cout << C[i] << ", ";
	}
	
	
     size = setSubtraction(B, 5, A, 6, C); 

	cout << "\n\n\nThe subtraction of A from B (B-A) is"<<endl; 
	for(int i=0;i<size;i++)
	{
		cout << C[i] << ", ";
	}
}

