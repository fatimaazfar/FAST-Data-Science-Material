#include<iostream>
using namespace std;
void cin_Array(int arr[], int n)
{
	for (int i = 0;i < n;i++)
	{
		cin >> arr[i];
	}
}
void cout_Array(const int arr[], int n)
{
	cout << "{ ";
	for (int i = 0;i < n;i++)
	{
		cout << arr[i]<< " ";
	}
	cout << "}"<<endl;
}
void Digit_Frequency(const int Numbers[], int N, int F[])
{
	int num,check;
	for (int i = 0;i < N;i++)
	{
		num = Numbers[i];
		for (int j = 0;num != 0;j++)
		{
			check=num % 10;
			num = num / 10;
			for (int k = 0;k < N;k++)
			{
				if (check == k)
				{
					F[k]++;
				}
			}
		}
	}
}
int main()
{
	int size;
	again:
	cout << "Enter the size of array (less that 20): ";
	cin >> size;
	if (size > 20 || size <= 0)
	{
		cout << "Wrong Input! Enter again."<<endl;
		goto again;
	}
	int* arr = new int[size];
	cout << "Enter the elements in array: " << endl;
	cin_Array(arr, size);
	cout_Array(arr, size);
	int* F = new int[size] {0};
	Digit_Frequency(arr, size, F);
	cout_Array(F, size);
	delete[] arr;
	delete[] F;
	system("pause");
	return 0;
}
