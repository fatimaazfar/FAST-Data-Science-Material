#include "ThreeDvector.h"
#include<fstream>
using namespace std;

int main()
{
	ThreeDvector v(1,2,3),v2(2,2,3);
	cout << "V = 1,2,3 and V2 = 2,2,3." << endl;
	cout << "V++ : " << endl;
	cout << v++;
	cout << "V after V++ : " << endl;
	cout << v;
	cout << "++V2 : " << endl;
	cout << ++v2;
	cout << "Checking cascading cout << v << v2 : " << endl;
	cout << v << v2;
	cout << "Taking input in V : " << endl;
	cin >> v;
	cout << "Outputting the V you just entered : " << endl;
	cout << v;

	ofstream fout;
	fout.open("C:\\Users\\Nadeem\\Desktop\\BSDS\\Semester 2\\OOP\\Lab\\Lab8\\Output.txt");
	fout << v << v2;
	fout.close();
	ifstream fin;
	fin.open("C:\\Users\\Nadeem\\Desktop\\BSDS\\Semester 2\\OOP\\Lab\\Lab8\\Input.txt");
	fin >> v;
	fin.close();
	cout << "V after reading from file : " << endl;
	cout << v;

	system("pause");

	int size;
	int j = 0;
	char comma;
	fin.open("C:\\Users\\Nadeem\\Desktop\\BSDS\\Semester 2\\OOP\\Lab\\Lab8\\Input.txt");
	fin >> size;
	int** arr = new int* [size];
	for (int i = 0;i < size;i++)
	{
		arr[i] = new int[3];
	}
	for (int i = 0;i < size;i++)
	{
		for (j = 0;j < 2;j++)
		{
			fin >> arr[i][j] >> comma;
		}
		fin >> arr[i][j];
	}
	fin.close();
	cout << "Size : " << size << endl;
	cout << "Outputting the array : " << endl;
	for (int i = 0;i < size;i++)
	{
		for (j = 0;j < 2;j++)
		{
			cout << arr[i][j] << ",";
		}
		cout << arr[i][j] << endl;
	}
	for (int i = 0;i < size;i++)
	{
		delete[] arr[i];
	}
	delete[] arr;
	system("pause");
}