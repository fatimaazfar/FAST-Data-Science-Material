#include"student_20L_1027.h"
#include<iostream>
#include<string>
using namespace std;
Student::Student() : roll(0), mid1(0), mid2(0), final(0)
{
	quiz = new float[4]{};
	cout << "Default Constructor Called." << endl;
}
Student::Student(string n,int r) : roll(0),mid1(0),mid2(0),final(0)
{
	name = n;
	roll = r;
	quiz = new float[4]{};
	cout << "Overload Constructor Called." << endl;
}
void Student::print()
{
	cout << "Name : " << name << endl;
	cout << "Roll no. : " << roll << endl;
	cout << "Mid 1 : " << mid1 << endl;
	cout << "Mid 2 : " << mid2 << endl;
	cout << "Final : " << final << endl;
	cout << "Quiz 1 : " << quiz[0] << endl;
	cout << "Quiz 2 : " << quiz[1] << endl;
	cout << "Quiz 3 : " << quiz[2] << endl;
	cout << "Quiz 4 : " << quiz[3] << endl;
	cout << "Total Score : " << total << endl;
}
void Student::setname(string n)
{
	name = n;
}
void Student::setRollNo(int r)
{
	roll = r;
}
void Student::setMid1Marks(float marks)
{
	mid1 = marks;
}
void Student::setMid2Marks(float marks)
{
	mid2 = marks;
}
void Student::setFinalMarks(float marks)
{
	final = marks;
}

void Student::setQuizMarks(float marks, int quiz_number)
{
	quiz[quiz_number] = marks;
}

float Student::getTotalScore()
{
	total = mid1 + mid2 + final + quiz[0] + quiz[1] + quiz[2] + quiz[3];
	return total;
}

int Student::compare(Student& S)
{
	if (total == S.total)
	{
		return 0;
	}
	else if (total > S.total)
	{
		return 1;
	}
	else
	{
		return 2;
	}
}

Student::Student(Student& S)
{
	name = S.name;
	roll = S.roll;
	mid1 = S.mid1;
	mid2 = S.mid2;
	final = S.final;
	total = S.total;
	quiz = new float[4];
	for (int i = 0;i < 4;i++)
	{
		quiz[i] = S.quiz[i];
	}
	cout << "Default Copy constructor called." << endl;
}

void Student::copy(Student& S)
{
	name = S.name;
	roll = S.roll;
	mid1 = S.mid1;
	mid2 = S.mid2;
	final = S.final;
	total = S.total;
	quiz = new float[4];
	for (int i = 0;i < 4;i++)
	{
		quiz[i] = S.quiz[i];
	}
	cout << "Copy constructor called." << endl;
}

void Student::printStudentArray(Student* arr, int size)
{
	for (int i = 0;i < size;i++)
	{
		cout << "STUDENT " << i + 1 << " : " << endl;
		cout << "Name : " << arr[i].name << endl;
		cout << "Roll no : " << arr[i].roll  << endl;
		cout << "Mid 1 marks : " << arr[i].mid1 << endl;
		cout << "Mid 2 marks : " << arr[i].mid2 << endl;
		cout << "Finals Marks : " << arr[i].final << endl;
		for (int j = 0;j < 4;j++)
		{
			cout << "Quiz no. " << j + 1 << " marks : " << arr[i].quiz[j] << endl;
		}
		cout << "Total Score : " << arr[i].getTotalScore() << endl;
	}
}

int Student::highestScorer(Student* arr, int size)
{
	float highest = arr[0].total;
	int index = 0;
	for (int i = 0;i < size;i++)
	{
		if (arr[i].total > highest)
		{
			highest = arr[i].total;
			index = i;
		}
	}
	return index;
}

Student::~Student()
{
	delete[] quiz;
	quiz = nullptr;
	cout << "Destructor invoked for "<< name << endl;
}
