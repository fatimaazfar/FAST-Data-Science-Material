#include<iostream>
using namespace std;
int x = 15, y = 15, z = 50;
int const elements = 3; //number of categories i.e 1st name, 2nd name, address
int elem_array[elements] = { x,y,z };
char*** allocate(int num_of_students)
{
	char*** students = new char** [num_of_students];
	for (int i = 0;i < num_of_students;i++)
	{
		students[i] = new char* [elements];
		for (int j = 0;j < elements;j++)
		{
			students[i][j] = new char[elem_array[j]];
		}
	}
	return students;
}
void deallocate(char*** students,int num_of_students)
{
	for (int i = 0;i < num_of_students;i++)
	{
		for (int j = 0;j < elements;j++)
		{
			delete [] students[i][j];
		}
		delete[] students[i];
	}
	delete[] students;
}
void input(char*** students, int num_of_students)
{
	for (int i = 0;i < num_of_students;i++)
	{
		cout << "\nStudent no." << i + 1 << endl;
		for (int j = 0;j < elements;j++)
		{
			if (j == 0)
			{
				cout << "Enter first name : ";
			}
			else if (j == 1)
			{
				cout << "Enter second name : ";
			}
			else
			{
				cout << "Enter address : ";
			}
			cin.getline(students[i][j], elem_array[j]);
		}
	}
}
void print(char*** students, int num_of_students)
{
	for (int i = 0;i < num_of_students;i++)
	{
		cout << "\nStudent no." << i + 1 << endl;
		for (int j = 0;j < elements;j++)
		{
			if (j == 0)
			{
				cout << "First name : ";
			}
			else if (j == 1)
			{
				cout << "\nSecond name : ";
			}
			else
			{
				cout << "\nAddress : ";
			}
			cout << students[i][j];
		}
		cout << endl << endl;
	}
}
int main()
{
	int num;
	cout << "Enter the number of students :  ";
	cin >> num;
	char*** students = allocate(num);
	cin.ignore();
	input(students, num);
	print(students, num);
	deallocate(students, num);
}