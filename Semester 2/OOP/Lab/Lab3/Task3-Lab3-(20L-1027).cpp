#include<iostream>
using namespace std;
int** AllocateMemory(int rows, int cols)
{
	int** arr = new int* [rows];
	for (int i = 0;i < rows;i++)
	{
		arr[i] = new int[cols];
	}
	return arr;
}
void InputMatrix(int** matrix, const int rows, const int cols)
{
	for (int i = 0;i < rows;i++)
	{
		for (int j = 0;j < cols;j++)
		{
			cin>>matrix[i][j];
		}
	}
}
void DisplayMatrix(int** matrix, int rows, int cols)
{
	for (int i = 0;i < rows;i++)
	{
		for (int j = 0;j < cols;j++)
		{
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
	cout <<endl;
}
int* maxCol(int**matrix,int rows,int cols)
{
	int temp;
	int* max = new int[rows];
	for (int i = 0;i < rows;i++)
	{
		for (int j = 0;j < cols;j++)
		{
			temp=matrix[i][j];
			for (int k = 0;k < cols;k++)
			{
				if (temp < matrix[i][k])
				{
					temp = matrix[i][k];
				}
			}
			max[i] = temp;
		}
	}
	return max;
}
void DeallocateMemory(int** matrix, const int rows)
{
	for (int i = 0;i < rows;i++)
	{
		delete[] matrix[i];
	}
	delete[] matrix;
}
int** concat_table(int** table1, const int row1, const int col1, int** table2, int row2, int col2, const bool axis,int& rows3,int& cols3)
{
	if (axis == 0)//concatinate the number of rows
	{
		rows3 = (row1 + row2);
		cols3 = col1;
	}
	else if (axis == 1)//concatinate the number of columns
	{
		cols3 = (col1 + col2);
		rows3 = row1;
	}
	else
	{
		return 0;
	}
	int** con = AllocateMemory(rows3, cols3);
	int k = 0, l = 0, i = 0;
	for (i = 0;i < row1;i++)
	{
		for (int j = 0;j < col1;j++)
		{
			con[i][j] = table1[i][j];
		}
	}
	for (i = row1;i < rows3;i++, k++)
	{
		for (int j = 0;j < cols3;j++, l++)
		{
			con[i][j] = table2[k][l];
		}
	}
	return con;
}
int main()
{
	int rows, cols,input,axis;
	menu:
	cout << "Enter\n1 to find max number in each colum\n2 to concatinate at one axis\n3 to exit:" << endl;
	cin >> input;
	if (input == 1)
	{
		cout << "Enter the number of rows : ";
		cin >> rows;
		cout << "Enter the number of columns : ";
		cin >> cols;
		int** matrix = AllocateMemory(rows, cols);
		cout << "Enter the elements of the 2D array : " << endl;
		InputMatrix(matrix, rows, cols);
		cout << "Your matrix is : " << endl;
		DisplayMatrix(matrix, rows, cols);
		cout << "Maximum value in each columb is : " << endl;
		int* max = maxCol(matrix, rows, cols);
		for (int i = 0;i < rows;i++)
		{
			cout << "Largest number in col no. " << i + 1 << " is " << max[i] << endl;
		}
		delete[] max;
		DeallocateMemory(matrix, rows);
		cout << endl;
		goto menu;
	}
	else if (input == 2)
	{
		int rows2, cols2;
		cout << "Enter the number of rows for table 1 : ";
		cin >> rows;
		cout << "Enter the number of columns for table 1 : ";
		cin >> cols;
		int** matrix = AllocateMemory(rows, cols);
		cout << "Enter the elements of the table 1 : " << endl;
		InputMatrix(matrix, rows, cols);
		cout << "Enter the number of rows for table 2 : ";
		cin >> rows2;
		cout << "Enter the number of columns for table 2 : ";
		cin >> cols2;
		int** matrix2 = AllocateMemory(rows2, cols2);
		cout << "Enter the elements of the table 2 : " << endl;
		InputMatrix(matrix2, rows2, cols2);
		cout << "Enter value of axis\n0 for X\n1 for Y:"<<endl;
		cin >> axis;
		int conrow, concol;
		int** con = concat_table(matrix,rows,cols,matrix2,rows2,cols2,axis,conrow,concol);
		cout << "Table 1: "<<endl;
		DisplayMatrix(matrix, rows, cols);
		cout << "Table 2: "<<endl;
		DisplayMatrix(matrix2, rows2, cols2);
		cout << "Concatenated table: " << endl;
		DisplayMatrix(con, conrow, concol);
		DeallocateMemory(matrix, rows);
		DeallocateMemory(matrix2, rows2);
		DeallocateMemory(con, conrow);
	}
	else
	{
		return 0;
	}
	return 0;
}