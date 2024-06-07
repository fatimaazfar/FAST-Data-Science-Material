//this program outputs a table whose diagnol values are all zeros
#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
int size,product;
cout << "Please enter the table size: ";
cin >> size;
for (int row=1 ; row <= size ; row++) 
{
for (int column=1 ; column<= size ; column++) 
{
if(row==column)
{
product=0;	
}
else	
{
product = row*column;
}
cout << setw(4) << product;
}
cout << endl;
}	
}
