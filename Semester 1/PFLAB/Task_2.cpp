#include<iostream>
using namespace std;

void frequency(string s)
{
	int size = s.size();
	int counter = 0;
	for (int i = 0;i < size;i++)
	{
		counter = 1;
		for (int j = i+1;j < size;j++)
		{
			if (s[i] == s[j] && s[i] != 0)
			{
				s[j] = 0;
				counter++;
			}
		}
		if(s[i] != 0)
			cout << s[i] << "->" << counter << endl;
	}
}

int main()
{
	int choice = 0;
	while (choice <= 1)
	{
		cout << "Enter\n0 to find frequency of each digit in a string\n1 to find frequency of a digit in a string of numbers\nany other number to exit" << endl;
		cout << "Your choice : ";
		cin >> choice;
		if (choice == 0)
		{
			string s;
			cout << "Enter a string : ";
			cin >> s;
			frequency(s);
		}
		else if (choice == 1)
		{
			string s;
			cout << "Enter a string : ";
			cin >> s;
			frequency(s);
		}
		else
		{
			break;
		}
	}
	return 0;
}