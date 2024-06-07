#include <iostream>
using namespace std;
int main()
{
	const int size = 100;
	int arr[size] = {};
	int k = 0, j = 0;
 
	cout << "Enter the elements in the array (-99 to terminate) \n";
		{
				
			while (arr[k] != -99 && k < size)
				{	
					cin >> arr[k];
					if (arr[k] != -99)
						{						
							k++;
							j++;
						}
				}
			cout << endl;
		}
	cout << "The array is [";
	for (int k = 0; k < j; k++)
		{
			cout << " " << arr[k] << " "; 
		}
	cout << "]" << endl;
	int sum = 0; 
	int limit = j / 2;
	for(int a = 0; a < limit; a++)
		{
			sum+=arr[a];
		}
		cout << "Sum1 = " << sum << endl;
		
	int sum2 = 0;
	for(int a = (j / 2) + 1; a < j; a++)
		{
			sum2+=arr[a];
		}
		cout << "Sum2 = " << sum2 << endl;
		
	if(sum == sum2)
		{
			cout << "Equilibrium Index is " << j /2 << endl;
			return 0;
		}
	cout << "No equilibrium Index. \n";
	
	system("pause");
	return 0;

}
