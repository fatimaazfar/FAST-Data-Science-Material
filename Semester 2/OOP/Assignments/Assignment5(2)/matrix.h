/*Fatima Azfar 20L-1027*/

#include <iostream>
using namespace std;

class matrix
{
	int row;
	int col;
	int** mat;
public:
	matrix();//default constructor
	matrix(int, int, int = 0);//overload constructor
	matrix(const matrix&);//copy constructor2
	matrix operator = (const matrix&);//copy using =
	void allocate(int);
	void deallocate();
	friend ostream& operator << (ostream&, matrix);//output
	friend istream& operator >> (istream&, matrix&);//input
	int getrows();
	int getcols();
	static matrix ones(int r, int c);
	static matrix identity(int r);
	matrix operator ++ (int);//post increment
	matrix operator ++ ();//pre increment
	matrix operator + (const matrix) const;//add two objects
	matrix operator + (const int) const;//add object and int
	friend matrix operator + (const int, const matrix);//add int and object
	matrix operator - (const matrix) const;//subtract two objects
	matrix operator - () const;//returns negative of object
	friend matrix operator ^ (int v, const matrix m);//int^elements of object
	matrix operator ^ (int);//elements^2
	matrix operator * (const matrix) const;//multiply two objects
	friend matrix operator * (int, const matrix);//int*elements of object
	matrix operator += (const matrix);
	matrix operator > (const int) const;//return a matrix with elements filled by 1 or 0
	matrix operator >= (const int) const;
	matrix operator < (const int) const;
	matrix operator <= (const int) const;
	bool operator == (const int) const;
	bool operator == (const matrix) const;
	bool operator != (const matrix) const;
	int& operator ()(const int, const int);//return values in 2d array on coordinates
	matrix operator ()(int, int, int, int);//returns a sliced matrix
	matrix transpose();
	~matrix();
};
