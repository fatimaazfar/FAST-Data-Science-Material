#include <iostream>
using namespace std;

int main()
{
	int num = 0, flag = 0, count, denary;
	
	
	
	while (flag != 1)
		{	
			cout << "Enter a binary. \n";
			cin >> num;
			if (num < 0)
			flag = 1;
			else
			{
			
			denary = denary + (count * num);
			count = count * 2;
			}
		}

	cout << denary << endl;

}

