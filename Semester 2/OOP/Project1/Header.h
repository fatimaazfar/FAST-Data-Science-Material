#include <string>
using namespace std;
// will set default values using member initializer list. Allocate space to quizzes set default values to 0
class Student
{
public:
	string name = "";
	int roll = 0;
	float mid1 = 0;
	float mid2 = 0;
	float final = 0;
	float total = 0;
	float* quiz;
	// will set default values using member initializer list, and set the given name and roll number
	// Allocate space to quizzes, set default values to 0
	Student();
	Student(Student& S);//default copy constructor
	Student(string name, int roll);
	void print();
	void printStudentArray(Student* arr, int size);
	int highestScorer(Student* arr, int size);
	void setname(string);
	void setRollNo(int);
	void setMid1Marks(float marks);
	void setMid2Marks(float marks);
	void setFinalMarks(float marks);
	// will set the marks of the given quiz number
	// for example if setQuizMarks(10, 2) is called then changes should be made in quiz[1]
	void setQuizMarks(float marks, int quiz_number);
	// returns the sum of all quizzes mids  and final
	float getTotalScore();
	//returns 0 if both students have equal total marks
	// returns 1 if calling object student has higher total marks
	// return 2 if call object student has lower total marks
	int  compare(Student& S);
	//copies all the data of S in calling student. Should create deep copy
	void copy(Student& S);
	~Student();// should print “Destructor invoked for <student name>” and deallocated dynamic data
};
