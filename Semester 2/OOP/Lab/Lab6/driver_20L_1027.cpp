#include"student_20L_1027.h"
#include<iostream>
#include<string>
using namespace std;
int main()
{
	int size = 3;
	Student* arr = new Student[size];
	//to take input from user
	for (int i = 0;i < size;i++)
	{
		cout << "STUDENT " << i+1 << " : " << endl;
		cout << "Enter name : " << endl;
		cin >> arr[i].name;
		cout << "Enter roll no : " << endl;
		cin >> arr[i].roll;
		cout << "Enter mid 1 marks : " << endl;
		cin >> arr[i].mid1;
		cout << "Enter mid 2 marks : " << endl;
		cin >> arr[i].mid2;
		cout << "Enter finals : " << endl;
		cin >> arr[i].final;
		for (int j = 0;j < 4;j++)
		{
			cout << "Enter quiz " << j + 1 << " marks : " << endl;
			cin >> arr[i].quiz[j];
		}
	}
	//to take input in main
	/*arr[0].Student("Ali", 1);
	arr[1].Student("Sara", 2);
	arr[2].Student("Sana", 3);*/
	Student s;
	s.printStudentArray(arr, size);
	int index = s.highestScorer(arr, size);
	cout << "Highest scorer is : " << arr[index].name << endl;
	delete[] arr;
	return 0;
}