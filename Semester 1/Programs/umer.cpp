#include <iostream>
using namespace std;
int main ()

{  int size , array [size] ;


   // Making a function which input the size and key of array and displays it
   cout << "Please enter the size of the array you want : ";
   cin >> size;

   for ( int i=0 ; i<size ; i++ )
   { cout << "Please enter the value of index " << i << " : " ;
     cin >> array[i] ;   }
   
  
   // Making a funtion which display array

  cout << "Original Array = ";
    
    for ( int i=0 ; i<size ; i++ )
   {cout << array [i] << " ";} 
   
	cout<< endl;
	
	for ( int j=0 ; j<size ; j++)
   { for (int k=j+1; k<size ;k++)
      { if ( array [j]== array [k])
           {array [k] = -1;	}
	  }
   }
  
	cout << "New Array = ";
    
    for ( int i=0 ; i<size ; i++ )
       {cout << array [i] << " ";} 
       
	cout<< endl;
   
 system ("pause");

   return 0;

}
