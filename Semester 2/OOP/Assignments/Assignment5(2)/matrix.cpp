/*Fatima Azfar 20L-1027*/

#include "matrix.h"
#include<iostream>
#include<cmath>
using namespace std;

matrix::matrix() :row(0), col(0)//default constructor
{
	mat = nullptr;
}

matrix::matrix(int r, int c, int v)//overload constructor
{
	row = r;
	col = c;
	this->allocate(v);
}

matrix::matrix(const matrix& m)//deep copy constructor matrix m(m2); m(m2);
{
	if (!mat)
	{
		this->deallocate();
	}
	row = m.row;
	col = m.col;
	this->allocate(0);
	for (int i = 0;i < row;i++)
	{
		for (int j = 0;j < col;j++)
		{
			mat[i][j] = m.mat[i][j];
		}
	}
}

matrix matrix::operator = (const matrix& m)//deep copy using = (cascading)
{
	if (!mat)
	{
		this->deallocate();
	}
	row = m.row;
	col = m.col;
	this->allocate(0);
	for (int i = 0;i < row;i++)
	{
		for (int j = 0;j < col;j++)
		{
			mat[i][j] = m.mat[i][j];
		}
	}
	return *this;
}

void matrix::allocate(int value = 0)
{
	//allocating
	mat = new int* [row];
	for (int i = 0;i < row;i++)
	{
		mat[i] = new int[col];
	}
	//populating
	for (int i = 0;i < row;i++)
	{
		for (int j = 0;j < col;j++)
		{
			mat[i][j] = value;
		}
	}
}

void matrix::deallocate()
{
	if (mat != nullptr)
	{
		for (int i = 0;i < row;i++)
		{
			delete[] mat[i];
		}
		delete[] mat;
		mat = nullptr;
	}
}

int matrix::getrows()
{
	return row;
}

int matrix::getcols()
{
	return col;
}

matrix matrix::ones(int r, int c)
{
	matrix m;
	m.row = r;
	m.col = c;
	m.allocate(1);
	return m;
}

matrix matrix::identity(int r)
{
	matrix m;
	m.row = r;
	m.col = r;
	m.allocate();
	for (int i = 0;i < r;i++)
	{
		for (int j = 0;j < r;j++)
		{
			if (i == j)
			{
				m.mat[i][j] = 1;
			}
		}
	}
	return m;
}

matrix matrix::operator++(int v)//post increment
{
	matrix m = *this;//copy original matrix in a new obj
	m.row = row;
	m.col = col;
	for (int i = 0;i < row;i++)//increment in the original matrix
	{
		for (int j = 0;j < col;j++)
		{
			mat[i][j]++;
		}
	}
	return m;//return the copy of old matrix
}

matrix matrix::operator++()//pre increment
{
	for (int i = 0;i < row;i++)//increment the original obj
	{
		for (int j = 0;j < col;j++)
		{
			mat[i][j]++;
		}
	}
	return *this;//return the original incremented obj
}

matrix matrix::operator+(const matrix m) const //adds two matrix class
{
	matrix r;
	if (row == m.row && col == m.col)//condition for checking dimentions
	{
		r.row = row;
		r.col = col;
		r.allocate();
		for (int i = 0;i < row;i++)
		{
			for (int j = 0;j < col;j++)
			{
				r.mat[i][j] = mat[i][j] + m.mat[i][j];
			}
		}
	}
	return r;//returns empty matrix is dimentions are not equal
}

matrix matrix::operator+(const int v) const//adds matrix and integer
{
	matrix r;
	r.row = row;
	r.col = col;
	r.allocate();
	for (int i = 0;i < row;i++)
	{
		for (int j = 0;j < col;j++)
		{
			r.mat[i][j] = mat[i][j] + v;
		}
	}
	return r;
}

matrix matrix::operator-(const matrix m) const//subtracts two matrix objects
{
	matrix r;
	if (row == m.row && col == m.col)//condition for checking dimentions
	{
		r.row = row;
		r.col = col;
		r.allocate();
		for (int i = 0;i < row;i++)
		{
			for (int j = 0;j < col;j++)
			{
				r.mat[i][j] = mat[i][j] - m.mat[i][j];
			}
		}
	}
	return r;//returns empty matrix if the dimentions differ
}

matrix matrix::operator-() const//makes a new matrix with all elements negative
{
	matrix r;
	r.row = row;
	r.col = col;
	r.allocate();
	for (int i = 0;i < row;i++)
	{
		for (int j = 0;j < col;j++)
		{
			r.mat[i][j] = mat[i][j] * -1;
		}
	}
	return r;
}

matrix matrix::operator^(int v)//elements^int
{
	matrix r;
	r.row = row;
	r.col = col;
	r.allocate();
	for (int i = 0;i < row;i++)
	{
		for (int j = 0;j < col;j++)
		{
			r.mat[i][j] = pow(mat[i][j], v);
		}
	}
	return r;
}

matrix matrix::operator*(const matrix m) const//returns a multiplied matrix of two matrices
{
	matrix r;
	if (col == m.row)//condition for checking dimentions
	{
		{
			r.row = row;
			r.col = m.col;
			r.allocate();
			int sum = 0;
			for (int i = 0; i < r.row; i++)
			{
				for (int j = 0; j < r.col; j++)
				{
					sum = 0;
					for (int k = 0; k < col; k++)
					{
						sum += mat[i][k] * m.mat[k][j];
					}
					r.mat[i][j] = sum;
				}
			}
		}
	}
	return r;
}

matrix matrix::operator+=(const matrix m)//adds the right hand matrix to the left hand matrix
{
	if (row == m.row && col == m.col)//condition for checking dimentions
	{
		for (int i = 0;i < row;i++)
		{
			for (int j = 0;j < col;j++)
			{
				mat[i][j] += m.mat[i][j];
			}
		}
	}
	return *this;
}

matrix matrix::operator>(const int v) const//if element>int then store 1 else 0 
{
	matrix r;
	r.row = row;
	r.col = col;
	r.allocate();
	for (int i = 0;i < row;i++)
	{
		for (int j = 0;j < col;j++)
		{
			if (mat[i][j] > v)
			{
				r.mat[i][j] = 1;
			}
			else
			{
				r.mat[i][j] = 0;
			}
		}
	}
	return r;
}

matrix matrix::operator>=(const int v) const//if elements>=int then store 1 else 0
{
	matrix r;
	r.row = row;
	r.col = col;
	r.allocate();
	for (int i = 0;i < row;i++)
	{
		for (int j = 0;j < col;j++)
		{
			if (mat[i][j] >= v)
			{
				r.mat[i][j] = 1;
			}
			else
			{
				r.mat[i][j] = 0;
			}
		}
	}
	return r;
}

matrix matrix::operator<(const int v) const
{
	matrix r;
	r.row = row;
	r.col = col;
	r.allocate();
	for (int i = 0;i < row;i++)
	{
		for (int j = 0;j < col;j++)
		{
			if (mat[i][j] < v)
			{
				r.mat[i][j] = 1;
			}
			else
			{
				r.mat[i][j] = 0;
			}
		}
	}
	return r;
}

matrix matrix::operator<=(const int v) const
{
	matrix r;
	r.row = row;
	r.col = col;
	r.allocate();
	for (int i = 0;i < row;i++)
	{
		for (int j = 0;j < col;j++)
		{
			if (mat[i][j] <= v)
			{
				r.mat[i][j] = 1;
			}
			else
			{
				r.mat[i][j] = 0;
			}
		}
	}
	return r;
}

bool matrix::operator==(const int v) const
{
	int count = 0;
	for (int i = 0;i < row;i++)
	{
		for (int j = 0;j < col;j++)
		{
			if (mat[i][j] == v)
			{
				count++;
			}
		}
	}
	if (count == row * col)
	{
		return true;
	}
	return false;
}

bool matrix::operator==(const matrix m) const
{
	if (row == m.row && col == m.col)//condition for if rows != columns then directly return false
	{
		int count = 0;
		for (int i = 0;i < row;i++)
		{
			for (int j = 0;j < col;j++)
			{
				if (mat[i][j] == m.mat[i][j])
				{
					count++;
				}
			}
		}
		if (count == row * col)
		{
			return true;
		}
	}
	return false;
}

bool matrix::operator!=(const matrix m) const
{
	if (row == m.row && col == m.col)//condition for if rows != columns then directly return false
	{
		int count = 0;
		for (int i = 0;i < row;i++)
		{
			for (int j = 0;j < col;j++)
			{
				if (mat[i][j] != m.mat[i][j])
				{
					count++;
				}
			}
		}
		if (count == row * col)
		{
			return true;
		}
	}
	return false;
}

int& matrix::operator ()(const int r, const int c)
{
	return mat[r][c];
}

matrix matrix::operator()(int rstart, int rend, int cstart, int cend)
{
	matrix m;
	if (rend <= row && cend <= col)//condition that prevents the sliced array to extend from the rows and cols
	{
		m.row = (rend - rstart) + 1;
		m.col = (cend - cstart) + 1;
		m.allocate();
		for (int i = rstart, k = 0;i <= rend;i++, k++)
		{
			for (int j = cstart, l = 0;j <= cend;j++, l++)
			{
				m.mat[k][l] = mat[i][j];
			}
		}
	}
	return m;
}

matrix matrix::transpose()
{
	matrix m;
	m.row = col;
	m.col = row;
	m.allocate();
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			m.mat[j][i] = this->mat[i][j];
	return m;
}

matrix::~matrix()
{
	this->deallocate();
}

ostream& operator<<(ostream& output, matrix m)
{
	output << m.row << " " << m.col << endl;
	for (int i = 0; i < m.row; i++)
	{
		for (int j = 0; j < m.col; j++)
		{
			output << m.mat[i][j] << " ";
		}
		output << endl;
	}
	output << endl;
	return output;
}

istream& operator>>(istream& input, matrix& m)
{
	if (!m.mat)//in case the object is already allocated (to avoid memory leakage)
	{
		m.deallocate();
	}
	char comma;
	int x;
	input >> m.row >> comma >> m.col;
	m.allocate();
	for (int i = 0; i < m.row; i++)
	{
		int j;
		for (j = 0; j < m.col - 1; j++)
		{
			input >> x;
			m.mat[i][j] = x;
			input >> comma;
		}
		input >> x;
		m.mat[i][j] = x;
	}
	return input;
}

matrix operator+(const int v, const matrix m)//int + obj
{
	matrix r;
	r.row = m.row;
	r.col = m.col;
	r.allocate();
	for (int i = 0;i < m.row;i++)
	{
		for (int j = 0;j < m.col;j++)
		{
			r.mat[i][j] = m.mat[i][j] + v;
		}
	}
	return r;
}

matrix operator^(int v, const matrix m)
{
	matrix r;
	r.row = m.row;
	r.col = m.col;
	r.allocate();
	for (int i = 0;i < m.row;i++)
	{
		for (int j = 0;j < m.col;j++)
		{
			r.mat[i][j] = pow(v, m.mat[i][j]);
		}
	}
	return r;
}

matrix operator*(int v, const matrix m)
{
	matrix r;
	r.row = m.row;
	r.col = m.col;
	r.allocate();
	for (int i = 0;i < m.row;i++)
	{
		for (int j = 0;j < m.col;j++)
		{
			r.mat[i][j] = v * m.mat[i][j];
		}
	}
	return r;
}