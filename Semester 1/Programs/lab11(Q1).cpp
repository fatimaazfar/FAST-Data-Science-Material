#include <iostream>
#include <fstream>

using namespace std;
const int c=6;
const int r=6;
bool isSymmetric(int a[r][c]);
void transposeMatrix(int a[][6],int b[][6],int r,int c);
void FileInput(int M[r][c]);

int main()
{
	int M[r][c];
	FileInput (M);
	if(isSymmetric (M))
		cout << "Symmetric" << endl;
	else
		cout << "Not symmetric" << endl;
	return 0;
}

void FileInput(int M[r][c])
{
	ifstream inFile(Matrix.txt);
	 if (!inFile)
        cout << "File not found!" << endl;
     else
        for (int a = 0; a < 2; a++)
        {
            for (int b = 0; b < 2; b++)
            {
                inFile >> M[a][b];
                cout << "Matrix is:" << M[a][b] << endl;
            }
        }
}

void transposeMatrix(int a[][6], int b[][6], int r, int c) 
{ 
    for (int i = 0; i < r; i++) 
        for (int j = 0; j < c; j++) 
            b[i][j] = a[j][i]; 
} 
  

bool isSymmetric(int a[][6],int r,int c)
{ 
    int tr[r][c]; 
    transposeMatrix(matrix, tr, r, c); 
    for (int i = 0; i < r; i++) 
        for (int j = 0; j < c; j++) 
            if (mat[i][j] != tr[i][j]) 
                return false; 
    return true; 
}
