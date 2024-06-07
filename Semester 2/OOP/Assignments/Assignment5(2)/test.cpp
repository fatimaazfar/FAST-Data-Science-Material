#include "matrix.h"

#include <fstream>

void main()
{

	//***********************************constructors***********************************
	matrix m1;
	//will create an empty matrix of size 0 x 0
	matrix m2(3, 2);
	//will create a matrix of size 3 x 2 with all elements 0(default value)
	matrix m3(3, 2, 10);
	//will create a matrix of size 3 x 2 with all elements 10
	matrix m4(m3);
	//will create a m4 as deep copy of m3
	cout << m1 << endl << m2 << endl << m3 << endl << m4;
	//will print size and data of matrix in format as shown in results

	//***********************************getters***********************************
	cout << endl << m4.getrows() << ',' << m4.getcols() << endl;
	//will print the numbr of rows and number of columns of matrix m4

	//***********************************static functions***********************************
	matrix m5 = matrix::ones(4, 5);
	//ones is a static function of class matrix that will return a matrix of size 4 x5   containing all elements equal to 1 

	matrix Iden = matrix::identity(4);
	//ones is a static function of class matrix that will return an identity matrix of size 4 x 4 
	cout << m5 << endl << Iden;


	//***********************************reading and writing to file (insertion and extraction operator)***********************************
	ofstream fout;
	const char* outFile = "C:\\Users\\Nadeem\\Desktop\\BSDS\\Semester 2\\OOP\\Assignments\\Assignment5(2)\\output.txt"; //change the path of file before running
	fout.open(outFile);
	fout << m2;
	//write m2 to file


	ifstream fin;
	const char* inFile = "C:\\Users\\Nadeem\\Desktop\\BSDS\\Semester 2\\OOP\\Assignments\\Assignment5(2)\\input.txt"; //change the path of file before running
	fin.open(inFile);

	matrix m6;
	fin >> m6;
	//read a matrix from file in m6
	cout << m6;


	//***********************************Arithmetic operators***********************************
	cout << m5++ << endl;
	cout << m5;
	//m5++ will post increment m5	
	m2++;
	//will pre increment m2
	cout << (m2 + m3) << endl;
	//m2+m3 will return the sum of these two matrices
	cout << (m2 + 30) << endl;
	//m2+30 will return a matrix with 30 added to all elements of m2
	cout << (30 + m2) << endl;
	//30+m2 will return a matrix with 30 added to all elements of m2
	cout << (m3 - m2) << endl;
	//m3-m2 will return a matrix that is difference of m3 and m2
	cout << (-m2) << endl;
	//-m2 will return a matrix that is negative of m2	
	cout << (2 ^ m6) << endl;
	//will return all new matrix with elements equal to 2^elements of m6
	cout << (m6 ^ 2) << endl;
	//will return all new matrix with elements equal to elements of m6^2
	cout << m6 * m5;
	//will multiple m6 with m5 but as the dimensions are not same result will be an empty matrix
	cout << m6 * matrix::ones(m6.getcols(), 7);
	//will return a new matrix that is product of  m6 with matrix ones(m6.getcols(),7) 
	cout << (3 * m6);
	//will return a new matrix that is element wise product of  m6 and 3 
	m2 += matrix::ones(m2.getrows(), m2.getcols());
	//Compound addition operation
	cout << m2;


	//***********************************Relational Operators***********************************
	cout << (m6 > 9) << endl;
	//returns same dimension matrix as m6 matrix, with 1 or 0 where condition in true or false, ie element is >1
	cout << (m6 > 9) << endl << (m6 < 9) << endl << (m6 >= 9) << endl << (m6 <= 9) << endl << (m6 == 9) << endl;
	//other element wise relational operators

	//object wise comparison 
	cout << (m6 == m6) << endl;
	//will return true as m6 is equal to m6
	cout << (m6 != m1) << endl;
	//will return true as m6 is not equal to m1
	cout << (m6 != m6) << endl;
	//will return false as m6 is equal to m6



	//***********************************Function call operator***********************************
	cout << m6(1, 2) << endl;
	//will return the int in row 1 and column 2 or m6 by reference. 
	m6(1, 2) = -1;
	//as the value was returned by reference so the value can be changed
	cout << m6 << endl;

	cout << m6(1, 2, 0, 3);
	//m6(1,2,0,3) will return a new array that is a chunk of m6 from row 1 to 2 and column 0 to 3
	cout << m6(1, 10, 0, 3);
	// will return empty matrix as the input valeus are not in range of matrix rows

	cout << endl << endl << endl;
	//************************MORE TESTS***************************************************************
	cout << m1 << endl << m2 << endl << m3 << endl << m4 << endl << m5 << endl << m6 << endl;

	m1 = -m2 = m3++;

	m1 += (m6 ^ 6);

	matrix m7 = ((4 * m6 ^ 3) + (2 ^ m6)) * m6.transpose();
	cout << m7;
	//m6.transpose function will return and new matrix that is  transpose of m6

	cout << m1 << endl << m2 << endl << m3 << endl << m4 << endl << m5 << endl << m6 << endl;
	//please note which operations are in place and which ones are not

	system("PAUSE");

}