#include <iostream>
#include <cstring>
using namespace std;



/*Gets input string from user, save in dynamic char
array and returns the pointer of array*/
char* getString(int maxlength)
{
	//TODO <Students> Complete the body of function
	char* str = new char[maxlength];
	cin.getline(str, maxlength);
	return str;
}
class Student
{
	char* name; // should end with '\0'
	char rollno[8]; // formate L124356   // should end with '\0'
	int age;
	double cgpa;

public:
	/*Constructor that takes name rollno, age and cgpa as input
	  and initialized the member variables*/
	Student(const char* n,const char* r, int a, double c)
	{
		// TODO <Students> complete this function, 
		//see example of how it runs in main
		int size = sizeof(n);
		name = new char[size+1];
		for (int i = 0;i <= size;i++)
		{
			name[i] = n[i];
		}
		for (int i = 0;i < 7;i++)//as 7 is the standard limit for roll numbers i am using 7 as loop size
		{
			rollno[i] = r[i];
		}
		rollno[7] = '\0';
		age = a;
		cgpa = c;
	}

	/*Constructor that gets values as input form user*/
	Student()

	{   //get name 
		cout << "enter student name, not more than 20 char" << endl;
		name = getString(21); 	// will run when you complete getString function	 
		//get roll no 
		cout << "Enter roll number, formate CBBNNNN" << endl;
		cout << "\tC is campus BB is batch and NNNN is roll no" << endl;
		cin.getline(rollno, 8); //get age		
		cout << "Enter age " << endl;
		cin >> age;
		//get cgpa 
		cout << "Enter cgpa " << endl;
		cin >> cgpa;
		cin.ignore();
	}

	void print()
	{
		cout << "Name:\t" << name << endl;
		cout << "Rollno:\t" << rollno << endl;
		cout << "Age:\t" << age << endl;
		cout << "cgpa:\t" << cgpa << endl;
	}

	/*Takes new name form user and sets the name member variable*/
	void updateName()
	{
		delete[] name;// free the old name space 
		cout << "enter new name, not more than 20 char" << endl;
		name = getString(21);	 // will run when you complete getString function
	}
	/*Takes new name as input parameter and sets the name member variable.*/
	void updateName(const char* n)
	{
		//TODO <Student> complete this function. See sample run in main
		delete[] name;
		int size = sizeof(n);
		name = new char[size+2];
		for (int i = 0;i <= size;i++)
		{
			name[i] = n[i];
		}
		name[size+1] = '\0';
	}
	//*Take rollnumber as string from user and updates member variable rollno*//
	void updateRollno(const char* r = nullptr)//default to identify when roll number has to be taken from the user
	{
		//TODO <Student> complete this function. See sample run in main
		if (r == nullptr)
		{
			cout << "Enter the Rollno. : ";
			r = getString(8);
		}
		for (int i = 0;i < 7;i++)
		{
			rollno[i] = r[i];
		}
		rollno[7] = '\0';
	}


	//void updateRollNumv
		~Student()
	{
		cout << "~Student() called for " << name << endl;
		delete[] name;
	}
};

int main()
{
	Student s1("Ali", "L135070", 20, 3.5);
	s1.print();
	s1.updateName();
	s1.updateRollno("L12345678");// only 7 charaters should be copied
	s1.print();
	s1.updateName("Ahmed");
	s1.updateRollno("L567890");// only 7 charaters should be copied
	s1.print();
	system("pause");

	/*Output of the main is

  Name:   Ali
  Rollno: L135070
  Age:    20
  cgpa:   3.5
  enter new name, not more than 20 char
  Sara
  Name:   Sara
  Rollno: L123456
  Age:    20
  cgpa:   3.5
  Name:   Ahmed
  Rollno: L567890
  Age:    20
  cgpa:   3.5
  Press any key to continue . . .




	*/

}