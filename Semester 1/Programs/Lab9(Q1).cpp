#include<iostream>
using namespace std;
int counter(char array[],int countSmallAlph,int countLargeAlph,int countSpaces)
{
	int countChar=0,counter=0;
	 for(counter=0;array[counter]!=NULL;counter++)
    {
 
        if(array[counter]>='0' && array[counter]<='9')
            {
			countChar++;
		    }
        else if((array[counter]>='A' && array[counter]<='Z'))
            {
			countLargeAlph++;
            countChar++;
            }
        else if((array[counter]>='a' && array[counter]<='z'))    
            {
			countSmallAlph++;
            countChar++;
            }
        else if(array[counter]==' ')
            {
			countSpaces++;
            }
        else
            {
            countChar++;
            }
    }
    return countChar;
}
int main()
{
	int countSmallAlph=0,countLargeAlph=0,countSpaces=0;
   char str[100];
   cout << "Please enter a string terminating with 0:\t";
   cin.getline(str,100,'0');
   int charcount=counter(str,countSmallAlph,countLargeAlph,countSpaces);
   cout<<"The total number of characters is "<<charcount;
   cout<<"\nThe number of Large Alphabets is "<<countLargeAlph;
   cout<<"\nThe number of Small Alphabets is "<<countSmallAlph;
   cout<<"\nThe number of Spaces is "<<countSpaces;
}
