#include <iostream>
using namespace std;

int main()
{
	int arr[10];
	cout << "Please enter 10 numbers" << endl;
	int *p;
	p = arr;
	for (int i = 0; i < 10; i++)
		cin >> *(p+i);
	for (int i = 0; i < 10; i++)
		*(p+i) += 3;
	cout << "The final array is:";
	for (int i = 0; i < 10; i++)
		cout << *(p+i) << " ";
	cout << endl;
	
	
	system("pause");
	return 0;
}
