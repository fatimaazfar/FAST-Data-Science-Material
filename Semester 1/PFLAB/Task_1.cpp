#include<iostream>
#include<fstream>
using namespace std;

int found(string source, string find)
{
	if (source == find)
	{
		return 1;
	}
	else
	{
		int count = 0;
		string temp;
		int size = source.size();
		for (int i = 0, j = 0;j < size;i++, j++)
		{
			if (find[i] == source[j])
			{
				count++;
				temp = source;
			}
		}
		if (count >= size/2+1)
		{
			cout << "Did you mean " << temp << "?" << endl;
			return 2;
		}
		else
		{
			return 0;
		}
	}	
}

int main()
{
	int size;
	cout << "Enter the size of your dictionary : ";
	cin >> size;
	string* wordlist = new string[size];
	cout << "Enter the words one by one in the dictionary : " << endl;
	for (int i = 0;i < size;i++)
	{
		cin >> wordlist[i];
	}
	ofstream fout;
	fout.open("dictionary.txt");
	for (int i = 0;i < size;i++)
	{
		fout << wordlist[i] << endl;
	}
	fout.close();
	string word;
	cout << "Enter a word : ";
	cin >> word;
	int a;
	for (int i = 0;i < size;i++)
	{
		a = found(wordlist[i], word);
		if (a == 1)
		{
			break;
		}
		else if (a == 2)
		{
			break;
		}
	}
	if (a == 1)
	{
		cout << "You typed the correct spelling!" << endl;
	}
	else if (a == 0)
	{
		cout << "No word with these spellings exit!" << endl;
	}
}