#include <iostream>
using namespace std;


int fn(int A[],int key)
    {   int k = 0;
        for (int i = 0; i < 5; i++)
            {
                if (A[i] == key)
                {
                    k++;
                }
            }
        return k;    
    }

int main()
{
int i;
int A[5] = {};

cout << "Enter the elements in the array. \n";
for (int k = 0; k < 5; k++)
{
cin >> A[k];

}
cout << endl;
cout << "The array is [";
for (int k = 0; k < 5; k++)
{
cout << " " << A[k] << " ";
}
cout << "]" << endl;

int key;
cin >> key;
int frequency = 0 ;
frequency = fn(A, key);
cout << "The value you entered has the frequency of " << frequency << endl;

system ("pause");
return 0;
}
