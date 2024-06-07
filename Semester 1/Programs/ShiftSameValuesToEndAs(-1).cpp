//this program takes the size and elements of an array from the user and prints out a sorted array with repeated values as -1 shifted all to the end
#include<iostream>
using namespace std;
int main ()
{
	int n=0;
	cout<<"Enter the size of array : "; //taking size of array from the user
	cin>>n;
	int array[n];
for(int i = 0 ; i < n ; i++) //this loop takes all values of the array from user
    {
	cout<<"Enter the element except -1 : ";
	cin>>array[i]; 
    }
for(int i=0; i<n; i++) //this loop converts all the repeated values into -1
	{
		for(int j =i+1; j<n; j++)
		{
			if (array[i] == array[j])
			{array[j]=-1;}
		}
	}	
		
			cout<<"The values in the array after replacing repeating values with -1 are "; //printing the shift array
	for(int i = 0 ; i < n ; i++)
{
	cout<<" "<<array[i];
}
		
int shift[n]; //forming a new array of the same size
int j=0;

for(int i=0 ; i<n ; i++) //this loop puts all the non -1 values in the shift array 
{
 if(array[i]!=-1)
 {
  shift[j]=array[i];
  j++;
 }
}
while(j<n) //this loop puts -1 in the left over space in the shift array
{
 shift[j]=-1;
 j++;
}
cout<<endl;
	cout<<"The values in the array after shifting -1 to the end are "; //printing the shift array
	for(int i = 0 ; i < n ; i++)
{
	cout<<" "<<shift[i];
}

}




