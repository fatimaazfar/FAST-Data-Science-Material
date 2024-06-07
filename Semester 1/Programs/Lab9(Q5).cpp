#include<iostream>
#include<bits/stdc++.h> 
using namespace std;  
void fillrotate(int arr[5][5], int m, int n, int temp[]) 
{ 
	int i, k = 0, l = 0; 
	int tIdx = 0; 
	while (k < m && l < n) 
	{ 
		for (int i = l; i < n; ++i) 
			arr[k][i] = temp[tIdx++]; 
		k++; 
		for (int i = k; i < m; ++i) 
			arr[i][n-1] = temp[tIdx++]; 
		n--; 
		if (k < m) 
		{ 
			for (int i = n-1; i >= l; --i) 
				arr[m-1][i] = temp[tIdx++]; 
			m--; 
		} 
		if (l < n) 
		{ 
			for (int i = m-1; i >= k; --i) 
				arr[i][l] = temp[tIdx++]; 
			l++; 
		} 
	} 
} 
void Rotate(int arr[5][5], int M, int N, int k) 
{ 
	int temp[M*N]; 
	int m = M, n = N, s = 0, l = 0; 

	int *start = temp; 
	int tIdx = 0; 
	while (s < m && l < n) 
	{  
		int *end = start; 
		for (int i = l; i < n; ++i) 
		{ 
			temp[tIdx++] = arr[s][i]; 
			end++; 
		} 
		s++; 
		for (int i = s; i < m; ++i) 
		{ 
			temp[tIdx++] = arr[i][n-1]; 
			end++; 
		} 
		n--; 
		if (s < m) 
		{ 
			for (int i = n-1; i >= l; --i) 
			{ 
				temp[tIdx++] = arr[m-1][i]; 
				end++; 
			} 
			m--; 
		} 
		if (l < n) 
		{ 
			for (int i = m-1; i >= s; --i) 
			{ 
				temp[tIdx++] = arr[i][l]; 
				end++; 
			} 
			l++; 
		} 
		if (end-start > k) 
		{ 
			reverse(start, start+k); 
			reverse(start+k, end); 
			reverse(start, end); 
			start = end; 
		} 
		else
			break; 
	} 
	fillrotate(arr, M, N, temp); 
} 
int main() 
{ 
	int M = 5, N = 5, k = 1,a[5][5]; 
for(int i=0;i<5;i++)
{
	for(int j=0;j<5;j++)
	{
		cout<<"Enter element : ";
		cin>>a[i][j];
	}
}
cout<<"The original array is "<<endl;
	for (int i=0; i<M; i++) 
	{ 
		for (int j=0; j<N; j++) 
			cout << a[i][j] << " "; 
		cout << endl; 
	} 
	Rotate(a, M, N, k); 
cout<<"\nThe rotated array is "<<endl;
	for (int i=0; i<M; i++) 
	{ 
		for (int j=0; j<N; j++) 
			cout << a[i][j] << " "; 
		cout << endl; 
	} 
	return 0; 
} 

