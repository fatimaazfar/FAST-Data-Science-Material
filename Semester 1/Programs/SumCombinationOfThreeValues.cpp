//this program takes a number from user and print combiations of three values that would add into the input number 
#include<iostream>
using namespace std;
int main()
{   const int e=10;
	int a[e]={1,2,3,4,5,6,7,8,9,10};
	int num;
	cout<<"The values in the array are {1,2,3,4,5,6,7,8,9,10} \n"; //taking input
	cout<<"Enter a number : ";
	cin>>num;
    for(int i=0; i<e ; i++) //this loop checks all the probabilities of combinations of three values summing to form the number that user inputs
		{
		for(int j=i+1; j<e; j++)
		{
			for(int k=j+1; k<e; k++)
			{
				if(a[i]+a[j]+a[k]==num)//printing all the possible combinations
				{ 
				cout << a[i] << " " << a[j] << " " << a[k];
				cout << endl;
			    }
			}
		}
		}

}

