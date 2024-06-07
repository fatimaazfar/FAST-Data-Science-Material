// C++ program sort array in even and odd manner. 
// The odd numbers are to be sorted in descending 
// order and the even numbers in ascending order 
#include <bits/stdc++.h> 
using namespace std; 

// To do two way sort. First sort even numbers in 
// ascending order, then odd numbers in descending 
// order. 
void twoWaySort(int arr[], int n) 
{ 

// Current indexes from left and right 
int l = 0, r = n - 1; 

// Count of odd numbers 
int k = 0; 

while (l < r) 
{
// Find first even number 
// from left side. 
while (arr[l] % 2 != 0) 
{ 
l++; 
k++; 
} 

// Find first odd number 
// from right side. 
while (arr[r] % 2 == 0 && l < r) 
r--; 

// Swap even number present on left and odd 
// number right. 
if (l < r) 
swap(arr[l], arr[r]); 
} 

// Sort odd number in descending order 
sort(arr, arr + k, greater<int>()); 

// Sort even number in ascending order 
sort(arr + k, arr + n); 
} 

// Driver code 
int main() 
{ 
int size=0, arr[100];
cout<<"Enter elements (-1 to stop) : ";
for(int i=0; ;i++)
{
	cin>>arr[i];
	if(arr[i]==-1)
	{
		break;
	}
	size++;
} 
twoWaySort(arr, size); 
for (int i = 0; i < size; i++) 
cout << arr[i] << " "; 
return 0; 
}
