#include<iostream>
using namespace std;
int main()
{
	//print a whole series
	int limit=100,i,num;
    for(num = 2; num <= limit; num++) {

        for(i = 2; i <= (num / 2); i++) {

            if(num % i == 0) {
                i = num;
                break;
            }
        }

        // If the number is prime then print it.
        if(i != num) {
            cout << num << " ";
        }
    }
    //check a single number
	int j=0,k=0,num;
	cout<<"ENTER : ";
	cin>>num;
	for (k = 2; k <= num; k++)
	{
		if (num % k == 0)
		j = j + 1;
	}
	
	if (j == 1)
    {
    	cout<<"it is prime";
	}
	else
	{
	    cout<<"its not prime";
    }
}
