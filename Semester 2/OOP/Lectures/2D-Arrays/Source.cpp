#include <iostream>
using namespace std;


/* Take a string input user and returns the pointer
of dynamic array containing that string
max number of charaters in string can be 20*/
char* getname();


/*<TODO students> chanage getname such that max length of name
can be changed by passing  paramter with default value to getname
function. Default value can be 20*/


/*prints the char string*/
//void print(char*);


/*returns the number of charaters in char string excluding '\0'*/
int getsize(char*p)
{
	int size = 1;
	for (int i = 0;p[i] != '\0';i++)
	{
		size++;
	}
	return size;
}




int main()
{


	char* name = getname();
	cout << "Name: " << name << endl;
	cout << "characters in name: " << getsize(name) << endl;
	delete[] name;


	//2D dynamic array containing names of students
	int no_of_students;
	cout << endl << "enter number of students: ";
	cin >> no_of_students;
	cin.ignore();
	char** student_names = new char* [no_of_students];


	for (int i = 0; i < no_of_students; i++)
		student_names[i] = getname();


	for (int i = 0; i < no_of_students; i++)
		cout << "Student " << i << ": " << *(student_names + i) << endl;


	for (int i = 0; i < no_of_students; i++)
		delete[] student_names[i];


	//<TODO students>
	//Create a 3D arrays of students, each student will have a Rollno, Firstname and last names, 
	//First name and last names and rollnos will be dynamic arrays. 




	// Example of cin.getline after taking number as input
	// https://stackoverflow.com/questions/7786994/c-getline-isnt-waiting-for-input-from-console-when-called-multiple-times
	int x;
	cout << "enter integer";
	cin >> x;
	cout << "enter string";
	char c[10];
	cin.getline(c, 10);


	cout << x;
	cout << c;




	system("pause ");


}








char* getname()
{
	// get name in fixed size array
	cout << "Enter name (not more than 20 characters long):";


	const int max_length = 21; // <TODO students: why is max_length 21>
	char temp[max_length];
	cin.sync(); //<TODO students; Why used cin.sync(), cin.ignore() or cin.clear() ? for me only sync worked for string after string>
	cin.getline(temp, max_length); // reads line in temp till 20 char are types of enter is pressed. cin>>temp; will not read spaces


	   // get the number of charaters in temp inc "\0"



	int size = 1;
	for (int i = 0; temp[i] != '\0'; i++)
		size++;
	// create dynamic array of that size
	char* name = new char[size];
	//copy temp to name
	for (int i = 0; i < size; i++)
		name[i] = temp[i];
	// return pointer of name, temp is local non-dyn array it will be deleted automatically


	return name;


}