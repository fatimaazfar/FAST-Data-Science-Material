#include<iostream>
using namespace std;
class Matrix
{
public:
	int** matrix;
	int rows;
	int size;
	Matrix()
	{
		matrix = 0;
		rows = 0;
		size = 0;
		cout << "Default Constructor Called." << endl;
	}
	int** allocate()
	{
		int** m = new int* [rows];
		for (int i = 0;i < rows;i++)
		{
			m[i] = new int[size];
		}
		return m;
	}
	void copy(int** d, int** s, int rows, int cols)
	{
		for (int i = 0;i < rows;i++)
		{
			for (int j = 0;j < cols;j++)
			{
				d[i][j] = s[i][j];
			}
		}
	}
	Matrix(const Matrix& M)
	{
		rows = M.rows;
		size = M.size;
		matrix = new int* [rows];
		for (int i = 0; i < rows; i++)
			matrix[i] = new int[size];
		for (int i = 0; i < rows; i++)
			for (int j = 0; j < size; j++)
				matrix[i][j] = M.matrix[i][j];
		cout << "Copy Constructor Invoked." << endl;
	}
	int** GetMatrix()
	{
		return matrix;
	}
	int GetSize()
	{
		return size;
	}
	int GetRows()
	{
		return rows;
	}
	void SetRows(int r)
	{
		rows = r;
	}
	void SetSize(int s)
	{
		size = s;
	}
	void SetMatrix(int** m)
	{
		matrix = m;
	}
	void print()
	{
		cout << "Rows : " << rows << endl;
		cout << "Colums : " << size << endl;
		cout << "Matrix values : " << endl;
		for (int i = 0;i < rows;i++)
		{
			for (int j = 0;j < size;j++)
			{
				cout << matrix[i][j] << " " ;
			}
			cout << endl;
		}
	}
	void input()
	{
		cout << "Enter rows : ";
		cin >> rows;
		cout << "Enter columns : ";
		cin >> size;
		matrix = allocate();
		cout << "Enter values : " << endl;
		for (int i = 0;i < rows;i++)
		{
			for (int j = 0;j < size;j++)
			{
				cin >> matrix[i][j];
			}
		}
	}
	int** AddMatrix(Matrix& m2)
	{
		int** R = allocate();
		for (int i = 0;i < rows;i++)
		{
			for (int j = 0;j < size;j++)
			{
				R[i][j] = matrix[i][j] + m2.matrix[i][j];
			}
		}
		return R;
	}
	~Matrix()
	{
		for (int i = 0;i < rows;i++)
		{
			delete[] matrix[i];
			matrix[i] = nullptr;
		}
		delete[] matrix;
		matrix = nullptr;
		cout << "Destructor Called." << endl;
	}
};
int main()
{
	Matrix m1;//default constructor called
	m1.input();//taking input
	Matrix m2 = m1;//copy constructor invoked, can also be mentioned as Matrix m2(m1);
	m2.print();//printing
	int** m = m1.AddMatrix(m2);//adding
	cout << "Sum of both matrices : " << endl;
	for (int i = 0;i < m1.rows;i++)
	{
		for (int j = 0;j < m1.size;j++)
		{
			cout << m[i][j] << " ";
		}
		cout << endl;
	}
}