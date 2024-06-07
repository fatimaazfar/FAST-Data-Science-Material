#include<iostream>
#include<Windows.h>//added to use the gotoxy function
using namespace std;

void gotoxy(int x, int y)//function to move cursor to wanted place on console screen
{
	COORD c = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

/*	 .   .   .
	  .  .  .
       . . .
   . . . . . . .
	   . . . 
	  .  .  .
	 .   .   .

	 Peony firework shape
	 size = 7 here
*/
void peony(int size, char character)
{
	int a, b;
	if (size % 2 == 0)
	{
		size++;
	}
	for (int t = 0;t < 2;t++)//to print the shape on two different locations on the console screen
	{
		if (t == 0)//to set location on console screen for the first circle
		{
			a = 10;//x
			b = 10;//y
		}
		else if (t == 1)//to set location on console screen for the second circle
		{
			a = 80;
			b = 5;
		}
		for (int i = 0,x = a;i < size;i++,x++)
		{
			for (int j = 0,y = b,k = size-1;j < size;j++, k--,y++)
			{
				gotoxy(x, y);
				if (j == size - 1)//if loop ends, to move to next line
				{
					cout << endl;
				}
				else if (i == j || i == k)//diagnols 
				{
					cout << character;
				}
				else if (j == size / 2 || i == size / 2)//horizontal and verticle line
				{
					cout << character;
				}
				else
					cout << " ";//anywhere where there is no character
			}
		}
	}
}

void square(int size, char character)
{
	int x = 0, y = 0, a = 0, b = 0, t = 0;
	for (t = 0;t < 2;t++)//to print the shape on two different locations on the console screen
	{
		if (t == 0)//to set location on console screen for the first circle
		{
			a = 10;
			b = 10;
		}
		else if (t == 1)//to set location on console screen for the second circle
		{
			a = 80;
			b = 5;
		}
		for (int i = 0,x = a; i <= size; i++,x++)
		{
			for (int j = 0,y = b; j <= size; j++,y++)
			{
				gotoxy(x, y);
				if (i == 0 || i == size || j == 0 || j == size)//prints boundaries
				{
					cout << character << " ";
				}
				else//prints spaces
				{
					cout << " " << " ";
				}
			}
			cout << endl;
		}
	}
}

void gotoRowCol(int rpos, int cpos)
{
	COORD scrn;
	HANDLE hOuput = GetStdHandle(STD_OUTPUT_HANDLE);
	scrn.X = cpos;
	scrn.Y = rpos;
	SetConsoleCursorPosition(hOuput, scrn);
}

void ReversePyramid(int n, char character)
{

	int l = 40;
	for (int t = 0;t < 2;t++)
	{
		system("CLS");
		for (int i = 1; i <= n; ++i)
		{
			gotoRowCol(l, 10);
			l--;
			for (int j = 1; j <= i; ++j)
			{
				cout << character << " ";
			}
			Sleep(200);
			cout << "\n";
		}
	}
}

void Pyramid(int n,char character)
{
	int a = 40;
	for (int t = 0;t < 2;t++)
	{
		system("CLS");
		for (int i = 1, k = 0; i <= n; ++i, k = 0)
		{
			gotoRowCol(a, 10);
			a--;
			for (int space = 1; space <= n - i; ++space)
			{
				cout << "  ";
			}

			while (k != 2 * i - 1)
			{
				cout << character << " ";
				++k;
			}
			cout << endl;
			Sleep(200);
		}
	}
}

int main()
{
	int size, choice = 0, shape = 0;
	char character;

	while (choice == 0)
	{
		cout << "Choose the shape of the fireworks.\nEnter\n1 for square\n2 for peony\n3 for pyramid\n4 for right pyramid : ";
		cin >> shape;

		cout << "Enter the size of the firework : ";//input size
		cin >> size;

		cout << "Enter the character you want the firework to be printed in : ";//input character
		cin >> character;

		for (int i = 0; i < size;i++)//this loop prints the motion of the circular firework
		{
			system("CLS");//clears the whole screen
			if (shape == 1)
			{
				square(i, character);//prints a square
			}
			else if (shape == 2)
			{
				peony(i, character);
			}
			else if (shape == 3 || shape == 4)
			{
				goto other;
			}
			else
				break;
			Sleep(130);//makes the execution on the console screen slower by milliseconds
		}
		other:
		if (shape == 4)
		{
			Pyramid(size, character);
		}
		else if (shape == 3)
		{
			ReversePyramid(size, character);
		}
		system("pause");
		system("CLS");//to clear the whole screen
		gotoxy(0, 0);
		cout << "Do you want to see the fireworks again? Enter 0 for Yes, any other number to exit : ";
		cin >> choice;
	}
	return 0;

}