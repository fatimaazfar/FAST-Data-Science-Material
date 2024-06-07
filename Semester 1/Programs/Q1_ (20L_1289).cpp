#include <iostream>
using namespace std;

int fn(int A[], int size1, int B[],int size2)
{  
    int i = 0;
    for(int i = 0;i < size1; i++) //copying values
    {
        B[i] = A[i];
    }
    cout << "After squaring: \n";
    for(int i = 0; i < size1; i++) // squaring values
    {
        B[i] = (B[i] * B[i]);
    }
   
    return i;
}

int main()
{
        int A[5];
        int B[5];
        cout << "Enter values for array. \n";
		for (int i = 0; i < 5; i++)
        {
            cin >> A[i];
        }
       
        for (int i = 0; i < 5; i++)
        {
            cout << A[i] << endl;
        }
        cout << "The second array is: \n";
        fn(A,5,B,5);
       
        for(int i = 0; i < 5; i++)
        {
            cout << B[i] << endl;
        }
       
    system("pause");
    return 0;
}
