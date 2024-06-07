#include<iostream>
#include<fstream>

#include<math.h>

using namespace std;

int rows, columns;

int** input()
{

	cout << "please enter number of rows and columsn of matrix" << endl;
	cout << "rows : ";
	cin >> rows;
	cout << "colmuns : ";
	cin >> columns;

	int** array = new int* [rows];
	for (int i = 0; i < rows; i++)
	{
		array[i] = new int[columns];
	}

	cout << "please enter the values of matrix " << endl;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			cin >> array[i][j];
		}
	}
	return array;
}

void sum()
{

	int** array = input();
	int sum = 0;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			sum += array[i][j];
		}
	}
	cout << "the sum of the values of the matrix are : " << sum << endl;

}

void multiply()
{
	int** array = input();
	int product = 1;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			product = product* array[i][j];
		}
	}
	cout << "the product of the values of the matrix are : " << product << endl;
}

void row_average()
{
	int** array = input();
	float average = 0;
	for (int i = 0; i < rows; i++)
	{
		average = 0;
		for (int j = 0; j < columns; j++)
		{
			average += array[i][j];
		}
		average = average / columns;
		cout << "Average of row " << i + 1 << " is :" << average << endl;
	}
}

void column_average()
{
	int** array = input();
	float average = 0;
	for (int j = 0;j < columns; j++)
	{
		average = 0;
		for (int i = 0; i < rows; i++)
		{
			average += array[i][j];
		}
		average = average / rows;
		cout << "Average of column " << j + 1 << " is :" << average << endl;
	}
}

void average()
{
	int** array = input();
	float average = 0;
	for (int j = 0; j < rows; j++)
	{
		for (int i = 0; i < columns; i++)
		{
			average += array[i][j];
		}
	}
	average = average / (rows*columns);
	cout << "Average of whole matrix is :" << average;
}

void row_sorting()
{
	int** array = input();
	
	for (int i = 0; i < rows; i++)
	{
		// loop for column of matrix
		for (int j = 0; j < columns; j++)
		{
			// loop for comparison and swapping
			for (int k = 0; k < columns - j - 1; k++)
			{
				if (array[i][k] > array[i][k + 1])
				{
					// swapping of elements
					swap(array[i][k], array[i][k + 1]);
				}
			}
		}
	}

	cout << "The matrix after row wise sorting is : " << endl << endl;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			cout << array[i][j] << "\t";
		}
		cout << endl;
	}
}

void column_sorting()
{
	int** array = input();
	for (int i = 0; i < rows; i++)
	{
		// loop for column of matrix
		for (int j = 0; j < columns; j++)
		{
			// loop for comparison and swapping
			for (int k = 0; k < columns - j - 1; k++)
			{
				if (array[i][k] > array[i][k + 1])
				{
					// swapping of elements
					swap(array[i][k], array[i][k + 1]);
				}
			}
		}
	}

	int** result = new int* [rows];
	for (int i = 0; i < rows; i++)
	{
		result[i] = new int[columns];
	}

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			result[j][i] = array[i][j];
		}
	}
	
	cout << "the matrix after column wise sorting is : " << endl << endl;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			cout << result[i][j] << "\t";
		}
		cout << endl;
	}
}

void scalar_matrix_add()
{
	int** array = input();
	cout << "please enter the value of scalar " << endl;
	int value;
	cin >> value;

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			array[i][j] = array[i][j] + value;
		}
	}

	cout << "The addition of "<<value<<" to  matrix is as follows : " << endl;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			cout << array[i][j] << "\t";
		}
		cout << endl;
	}
}

void scalar_matrix_subtraction()
{
	int** array = input();
	cout << "please enter the value of scalar " << endl;
	int value;
	cin >> value;

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			array[i][j] = array[i][j] - value;
		}
	}

	cout << "The subtraction of " << value << " to  matrix is as follows : " << endl;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			cout << array[i][j] << "\t";
		}
		cout << endl;
	}
}

void addition_of_two()
{
	int sum = 0;
	int** array1 = input();
	
	int rows1, columns1;
	cout << "please enter number of rows and columsn of second matrix" << endl;

	cout << "rows : ";
	cin >> rows1;
	cout << "colmuns : ";
	cin >> columns1;

	int** array2 = new int* [rows1];
	for (int i = 0; i < rows1; i++)
	{
		array2[i] = new int[columns1];
	}

	cout << "please enter the values of second matrix " << endl;
	for (int i = 0; i < rows1; i++)
	{
		for (int j = 0; j < columns1; j++)
		{
			cin >> array2[i][j];
		}
	}

	if (rows == rows1 && columns == columns1)
	{
		int** result = new int* [rows];
		for (int i = 0; i < rows; i++)
		{
			result[i] = new int[columns];
		}

		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < columns; j++)
			{
				result[i][j]=array1[i][j] + array2[i][j];
			}
		}

		cout << "The sum of the two matrices are : " << endl;
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < columns; j++)
			{
				cout << result[i][j] << "\t";
			}
			cout << endl;
		}
		
	}
	else
	{
		cout << "The number of rows and columns should be same for matrix addition" << endl;
	}

}

void subtraction_of_two()
{
	int sub= 0;
	int** array1 = input();

	int rows1, columns1;
	cout << "please enter number of rows and columsn of second matrix" << endl;

	cout << "rows : ";
	cin >> rows1;
	cout << "colmuns : ";
	cin >> columns1;

	int** array2 = new int* [rows1];
	for (int i = 0; i < rows1; i++)
	{
		array2[i] = new int[columns1];
	}

	cout << "please enter the values of second matrix " << endl;
	for (int i = 0; i < rows1; i++)
	{
		for (int j = 0; j < columns1; j++)
		{
			cin >> array2[i][j];
		}
	}

	if (rows == rows1 && columns == columns1)
	{
		int** result = new int* [rows];
		for (int i = 0; i < rows; i++)
		{
			result[i] = new int[columns];
		}

		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < columns; j++)
			{
				result[i][j] = array1[i][j] - array2[i][j];
			}
		}
		cout << "The subtration of the two matrices are : " << endl;
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < columns; j++)
			{
				cout << result[i][j] << "\t";
			}
			cout << endl;
		}
	}
	else
	{
		cout << "The number of rows and columns should be same for matrix addition" << endl;
	}

}

void multiplication_of_two()
{
	int sum = 0;
	int** array1 = input();

	int rows1, columns1;
	cout << "please enter number of rows and columsn of second matrix" << endl;

	cout << "rows : ";
	cin >> rows1;
	cout << "colmuns : ";
	cin >> columns1;

	int** array2 = new int* [rows1];
	for (int i = 0; i < rows1; i++)
	{
		array2[i] = new int[columns1];
	}

	cout << "please enter the values of second matrix " << endl;
	for (int i = 0; i < rows1; i++)
	{
		for (int j = 0; j < columns1; j++)
		{
			cin >> array2[i][j];
		}
	}
  
	
	if (rows == rows1 && columns == columns1)
	{
		int** mult = new int* [rows1];
		for (int i = 0; i < rows1; i++)
		{
			mult[i] = new int[columns1];
		}

		// Multiplying matrix a and b and storing in array mult.
		for (int i = 0; i < rows; ++i)
			for (int j = 0; j < columns; ++j)
				for (int k = 0; k < columns; ++k)
				{
					mult[i][j] += array1[i][k] * array2[k][j];
				}

		cout << "The multiplaction of two matrices are as follows " << endl;
		for (int i = 0; i < rows1; i++)
		{
			for (int j = 0; j < columns1; j++)
			{
				cout<< mult[i][j];
			}
		}

	}
	else
	{
		cout << "The number of rows and columns should be same for matrix addition" << endl;
	}

}

void scalar_multiplication()
{
	int** array = input();
	cout << "please enter the value of scalar " << endl;
	int value;
	cin >> value;

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			array[i][j] = array[i][j] * value;
		}
	}

	cout << "The multiplication of " << value << " to  matrix is as follows : " << endl;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			cout << array[i][j] << "\t";
		}
		cout << endl;
	}
}

void scalar_division()
{
	int** array = input();

	float** result = new float* [rows];
	for (int i = 0; i < rows; i++)
	{
		result[i] = new float[columns];
	}

	cout << "please enter the value of scalar " << endl;
	int value;
	cin >> value;

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			result[i][j] = (array[i][j] / float(value));
		}
	}

	cout << "The devision of " << value << " to  matrix is as follows : " << endl;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			cout << result[i][j] << "\t";
		}
		cout << endl;
	}
}

void transpose()
{
	int** array = input();

	int** result = new int*[rows];
	for (int i = 0; i < rows; i++)
	{
		result[i] = new int[columns];
	}

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			result[j][i] = array[i][j];
		}
	}
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			cout << result[i][j] << "\t";
		}
		cout << endl;
	}
}

void determinant() 
{
	int determin = 0;

	int** arr = input();
	if (rows == 2 && columns == 2)
	{
		cout << "The determinant of matrix is : "<< ((arr[0][0] * arr[1][1]) - (arr[1][0] * arr[0][1]));
	}

	else if(rows==3&&columns==3)
	{

		determin= arr[0][0] * ((arr[1][1] * arr[2][2]) - (arr[2][1] * arr[1][2])) - arr[0][1] * ((arr[1][0] * arr[2][2]) - (arr[2][0] * arr[1][2])) + arr[0][2] * ((arr[1][0] * arr[2][1]) - (arr[2][0] * arr[1][1]));
		cout <<"The determinant of matrix is : "<< determin << endl;
	}
	else
	{
		cout << "determinant can only be calcualted for a 2 by 2 or 3 by 3 matrix" << endl;
	}
}

void inverse()
{
	int** arr = input();

	int** result = new int* [rows];
	for (int i = 0; i < rows; i++)
	{
		result[i] = new int[columns];
	}

	if ((rows == 2 && columns == 2) || (rows == 3 && columns == 3))
	{
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < columns; j++)
			{
				result[j][i] = arr[i][j];
			}
		}

		int determin = 0;

		int** arr = input();
		if (rows == 2 && columns == 2)
		{
			determin = ((arr[0][0] * arr[1][1]) - (arr[1][0] * arr[0][1]));
		}

		else if (rows == 3 && columns == 3)
		{

			determin = arr[0][0] * ((arr[1][1] * arr[2][2]) - (arr[2][1] * arr[1][2])) - arr[0][1] * ((arr[1][0] * arr[2][2]) - (arr[2][0] * arr[1][2])) + arr[0][2] * ((arr[1][0] * arr[2][1]) - (arr[2][0] * arr[1][1]));
		}

		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < columns; j++)
			{
				result[j][i] = result[i][j] / determin;
			}
		}

		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < columns; j++)
			{
				cout << result[i][j] << "\t";
			}
			cout << endl;
		}
	}
	else
	{
		cout << "only 2 by 2 and 3 by 3 matrix inverse can be found " << endl;
	}
}
int main()
{
	
	    int choice = 0;
	    cout << "please enter the functianlity you want to perform : " << endl;
	    cout << "1. Sum of Matrix(sum of all values)" << endl;
		cout << "2. Product of Matrix(product of all values)" << endl;
		cout << "3. Row - wise Average" << endl;
		cout << "4. Column - wise Average" << endl;
		cout << "5. Average or whole Matrix" << endl;
		cout << "6. Row - wise sorting of Matrix" << endl;
		cout << "7. Column - wise sorting of Matrix" << endl;
		cout << "8. Scalar Matrix Addition" << endl;
		cout << "9. Addition of two Matrices" << endl;
		cout << "10. Scalar Matrix Subtraction" << endl;
		cout << "11. Subtraction of two Matrices" << endl;
		cout << "12. Scalar Matrix Multiplication" << endl;
		cout << "13. Multiplication of two Matrices" << endl;
		cout << "14. Scalar Matrix Division" << endl;
		cout << "15. Matrix transpose" << endl;
		cout << "16. Matrix determinant" << endl;
		cout << "17. Matrix Inverse" << endl;
		cout << "Enter 0 to exit " << endl;
		do {
			cout <<endl<<endl<< "please enter your choice : ";
			cin >> choice;

			if (choice == 1)
			{
				sum();
			}
			else if (choice == 2)
			{
				multiply();
			}
			else if (choice == 3)
			{
				row_average();
			}
			else if (choice == 4)
			{
				column_average();
			}
			else if (choice == 5)
			{
				average();
			}
			else if (choice == 6)
			{
				row_sorting();
			}
			else if (choice == 7)
			{
				column_sorting();
			}
			else if (choice == 8)
			{
				scalar_matrix_add();
			}
			else if (choice == 9)
			{
				addition_of_two();
			}
			else if (choice == 10)
			{
				scalar_matrix_subtraction();
			}
			else if (choice == 11)
			{
				subtraction_of_two();
			}
			else if (choice == 12)
			{
				scalar_multiplication();
			}
			else if (choice == 13)
			{
				multiplication_of_two();
			}
			else if (choice == 14)
			{
				scalar_division();
			}
			else if (choice == 15)
			{
				transpose();
			}
			else if (choice == 16)
			{	
				determinant();
			}
			else
			{
				inverse();
			}

		} while (choice != 0);
}