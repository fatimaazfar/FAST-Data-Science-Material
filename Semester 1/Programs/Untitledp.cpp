/* Mohammad Anas (20L-1289)
	BDS-1A
	Question 4 (Part 1)
	Assignemnt 4
*/
#include <iostream>
using namespace std;

int main()
{
	const int i = 100;
	int A[i] = {};
	int k = 0, j = 0;
	
	cout << "Enter the limit for the array is 100 elements. \n";
 
	cout << "Enter the elements in the array and -1 to terminate getting input. \n";
		{
				
			while (A[k] != -1 && k < i)
				{	
					cin >> A[k];
					if (A[k] != -1)
						{						
							k++;
							j++;
						}
				}
			cout << endl;
		}
	cout << "The array is [ ";
	for (int k = 0; k < j; k++)
		{
			cout << " " << A[k] << " "; 
		}
	cout << " ]" << endl;
	int m=0,n=0,evenarray[j],oddarray[j];
	for(int i=0;i<j;i++)
	{
		if(i%2==0)
		{
			evenarray[m]=A[i];
			m++;
		}
		else
		{
		    oddarray[n]=A[i];
		    n++;
		}
	}
	//soring even index numbers in increasing order
    	for(int s=0;s<m;s++)
	{
		for(int i=0;i<m;i++)
	{
		if(evenarray[i+1]<evenarray[i] && i!=m-1)
		{
			int temp=evenarray[i];
		    evenarray[i]=evenarray[i+1];
		    evenarray[i+1]=temp;
		}
	}	
	}
	//sorting odd index numbers in decreasing order
	    for(int s=0;s<n;s++)
	{
		for(int i=0;i<n;i++)
	{
		if(oddarray[i+1]>oddarray[i] && i!=n-1)
		{
			int temp=oddarray[i];
		    oddarray[i]=oddarray[i+1];
		    oddarray[i+1]=temp;
		}
	}	
	}	
	//storing numbers in original array after sorting	
    int	p=0;
	for(int i=0; i<j;i+=2)
	{
	    A[i]=evenarray[p];
	    p++;
	}	
	p=0;
	for(int i=1; i<j;i+=2)
	{
	    A[i]=oddarray[p];
	    p++;
	}
	//outputting sorted array
	cout<<"The sorted array is : [ ";
    for(int i = 0; i < j; i++)
    {
	    cout << A[i] << " ";
    }
    cout<<" ]";
}
