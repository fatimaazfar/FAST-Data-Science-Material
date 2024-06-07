#include<iostream>
using namespace std;
int* InputArray(int&size)
{
	int* arr = new int[size];
	for (int i = 0;i < size;i++)
	{
		cin >> arr[i];
	}
	return arr;
}
void OutputArray(int* myArray, const int &size)
{
	cout << "{ ";
	for (int i = 0;i < size;i++)
	{
		cout << myArray[i] << " ";
	}
	cout << "}" << endl;
}
int* Intersection(int* setA, int size1, int* setB, int size2, int&size3)
{
	int* temp = new int[size1];
	size3=0;
	for (int i = 0;i < size1;i++)
	{
		for (int j = 0;j < size2;j++)
		{
			if (setA[i] == setB[j])
			{
				temp[size3] = setA[i];
				size3++;
			}
		}
	}
	int* inter_array = new int[size3];
	for (int i = 0;i < size3;i++)
	{
		inter_array[i] = temp[i];
	}
	delete[] temp;
	return inter_array;
}
int main()
{
	int size_A,size_B,size;
	cout << "Enter the size of the 'A' array: ";
	cin >> size_A;
	cout << "Enter the values of the 'A' array: " << endl;
	int*A=InputArray(size_A);
	cout << "Enter the size of the 'B' array: ";
	cin >> size_B;
	cout << "Enter the values of the 'B' array: " << endl;
	int* B = InputArray(size_B);
	cout << "A = ";
	OutputArray(A, size_A);
	cout << "B = ";
	OutputArray(B, size_B);
	cout << "Intersection = ";
	int* inter_array = Intersection(A, size_A, B, size_B, size);
	OutputArray(inter_array, size);
	delete[] A;
	delete[] B;
	delete[] inter_array;
	system("pause");
	return 0;
}