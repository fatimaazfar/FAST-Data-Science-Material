#include<iostream>
using namespace std;

template<typename T>
int ismember(T key, T arr[], int size)
{
	if (size < 0)
		return -1;
	else if (arr[size] == key)
		return size;
	else
		return ismember(key, arr, size--);
}

int main()
{
	int size = 5;
	int key = 2;
	int arr[5] = { 1,2,3,4,5 };
	if (ismember(key, arr, size))
		cout << "The key " << key << " exists in the array." << endl;
	else
		cout << "The key " << key << " does not exist in the array." << endl;
}