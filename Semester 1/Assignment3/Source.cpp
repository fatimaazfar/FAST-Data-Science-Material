#include <iostream>
#include <fstream>
using namespace std;

void sort(int** arr, int row, int column)
{
    int temp;
    for (int i = 0;i < 1;i++)
    {
        for (int j = 0;j < column;j++)
        {
            if (arr[i][j] > arr[i + 1][j])
            {
                temp = arr[i + 1][j];
                arr[i + 1][j] = arr[i][j];
                arr[i][j] = temp;
            }
        }
    }
}
int main()
{
    int row, column;
    ifstream fin;
    fin.open("text.txt");
    fin >> row >> column;
    //allocating
    int** arr = new int* [row];
    for (int i = 0;i < row;i++)
    {
        arr[i] = new int[column];
    }
    //inputting from file
    for (int i = 0;i < row;i++)
    {
        for (int j = 0;j < column;j++)
        {
            fin >> arr[i][j];
        }
    }
    fin.close();
    //allocating the new array
    int** sortedarr = new int* [row];
    for (int i = 0;i < row;i++)
    {
        sortedarr[i] = new int[column];
    }
    //copying the original array into the new array
    for (int i = 0;i < row;i++)
    {
        for (int j = 0;j < column;j++)
        {
            sortedarr[i][j] = arr[i][j];
        }
    }
    //sorting
    sort(sortedarr, row, column);
    //outputting on console
    cout << "Original Array : " << endl;
    for (int i = 0;i < row;i++)
    {
        for (int j = 0;j < column;j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << "Sorted Array : " << endl;
    for (int i = 0;i < row;i++)
    {
        for (int j = 0;j < column;j++)
        {
            cout << sortedarr[i][j] << " ";
        }
        cout << endl;
    }
    //deallocating
    for (int i = 0;i < row;i++)
    {
        delete[] arr[i];
    }
    delete[] arr;

    for (int i = 0;i < row;i++)
    {
        delete[] sortedarr[i];
    }
    delete[] sortedarr;
}