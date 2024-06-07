#include <iostream>
#include<fstream>
using namespace std;

int main() {
    int size;
    ifstream fin;
    fin.open("C:\\Users\\Nadeem\\Desktop\\BSDS\\Semester 2\\OOP\\Rough\\text.txt");
    fin >> size;
    size += 2;// adding two because the loop runs for size - 1
    char* c = new char[size];
    fin.getline(c, size);
    fin.close();
    fin.open("C:\\Users\\Nadeem\\Desktop\\BSDS\\Semester 2\\OOP\\Rough\\text.txt");
    fin >> size;
    size += 2;
    char* r = new char[size];
    int j = 0;
    char word[15]{ '\0' };
    while (j != size)
    {
        for (int i = 0;i < 10;i++)
        {
            word[i] = '\0';
        }
        fin >> word;
        for (int i = 9;i >= 0;i--,j++)
        {
            if (i != '\0')
            {
                r[j] = word[i];
            }
        }
    }
    fin.close();
    cout << "Original : " << endl;
    for (int i = 0;i < size;i++)
    {
        cout << c[i];
    }
    cout << "\nReversed : " << endl;
    for (int i = size - 1, j = 0;i >= 0;i--, j++)
    {
        r[j] = c[i];
    }
    for (int i = 0;i < size;i++)
    {
        cout << r[i];
    }
    delete[] c;
    c = nullptr;
    delete[] r;
    r = nullptr;
}