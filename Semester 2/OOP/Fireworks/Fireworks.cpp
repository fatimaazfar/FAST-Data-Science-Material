#include <iostream>
#include <Windows.h>
#include<cmath>
using namespace std;

void gotoRowCol(int rpos, int cpos)
{
	COORD scrn;
	HANDLE hOuput = GetStdHandle(STD_OUTPUT_HANDLE);
	scrn.X = cpos;
	scrn.Y = rpos;
	SetConsoleCursorPosition(hOuput, scrn);
}

void RT1(int n)
{

	int l = 40;
	for (int i = 1; i <= n; ++i)
	{
		gotoRowCol(l, 10);
		l--;
		for (int j = 1; j <= i; ++j)
		{
			cout << "* ";
		}
		Sleep(150);
		cout << "\n";
	}
}

void PY(int n)
{
	int a = 40;
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
			cout << "* ";
			++k;
		}
		cout << endl;
		Sleep(150);
	}
}
void peony(int n)
{
	int a, b;
	if (n % 2 == 0)
	{
		n++;
	}
	for (int t = 0; t < 2; t++)        //to print the shape on two different locations on the console screen
	{
		if (t == 0)                 //to set location on console screen for the first circle
		{
			a = 10;
			b = 10;
		}
		else if (t == 1)             //to set location on console screen for the second circle
		{
			a = 80;
			b = 5;
		}
		for (int i = 0, x = a; i < n; i++, x++)
		{
			for (int j = 0, y = b, k = n - 1; j < n; j++, k--, y++)
			{
				gotoRowCol(x, y);
				if (j == n - 1)                //if loop ends, to move to next line
				{
					cout << endl;
				}
				else if (i == j || i == k)            //diagnols 
				{
					cout << "* ";
				}
				else if (j == n / 2 || i == n / 2)       //horizontal and verticle line
				{
					cout << "* ";
				}
				else
					cout << " ";
				Sleep(10);//anywhere where there is no character
			}
		}
	}
}

void square(int n)
{
	int x = 0, y = 0, a = 0, b = 0, t = 0;
	for (t = 0; t < 2; t++)                                                //to print the shape on two different locations on the console screen
	{
		if (t == 0)                                                     //to set location on console screen for the first circle
		{
			a = 10;
			b = 10;
		}
		else if (t == 1)                                                //to set location on console screen for the second circle
		{
			a = 80;
			b = 5;
		}
		for (int i = 0, x = a; i < n; i++, x++)
		{
			for (int j = 0, y = b; j < n; j++, y++)
			{
				gotoRowCol(x, y);
				if (i == 0 || i == n - 1 || j == 0 || j == n - 1)          //prints boundaries
				{
					cout << "* ";
				}
				else           //prints spaces
				{
					cout << " " << " ";
				}
			}
			Sleep(150);
			cout << endl;
		}
	}
}
void circle(int n)
{
	//distance to the center
	float distance;
	int x = 0, y = 0, a = 0, b = 0, t = 0;
	for (t = 0; t < 2; t++)            //to print the shape on two different locations on the console screen
	{
		if (t == 0)
		{
			a = 10;
			b = 10;
		}
		else if (t == 1)
		{
			a = 80;
			b = 5;
		}
		for (int i = 0, x = a; i <= 2 * n; i++, x++)
		{
			for (int j = 0, y = b; j <= 2 * n; j++, y++)
			{
				gotoRowCol(x, y);
				distance = sqrt((i - n) * (i - n) + (j - n) * (j - n));       //calculating distance by using the distance formula i.e _/(x1-x2)^2+(y1-y2)^2
			   //distance should be in the range (radius - 0.5) and (radius + 0.5) to print character in the perfect point
				if (distance > n - 0.5 && distance < n + 0.5)
					cout << "* ";
				else
					cout << " ";
			}
			Sleep(150);
			cout << endl;
		}
	}
}



int main()
{
	int n = 0;
	do
	{
		cout << "Enter the size of firework (Max size should be 40): ";
		cin >> n;
		if (n < 1 || n>40)
		{
			cout << "Please Enter the size again\n";


			cout << "Enter the size of firework (Max size should be 40): ";
			cin >> n;
		}

	} while (n < 1 || n>40);
	int opt;
	int* optptr = &opt;
	cout << "There are two shapes Inverted Pyrmid ,Inverted Right Triagle\n";
	cout << "Enter 1 to print Inverted Right angle\n";
	cout << "Enter 2 to print Inverted Pyramid\n";
	cout << "Enter 3 to print Peony\n";
	cout << "Enter 4 to print Square\n";
	cout << "Enter 5 to print Circle\n";


	cin >> *optptr;
	system("cls");
	switch (*optptr)
	{
	case 1:
		RT1(n);
		break;
	case 2:
		PY(n);
		break;
	case 3:
		peony(n);
		break;
	case 4:
		square(n);
		break;
	case 5:
		circle(n);
		break;
	}
	gotoRowCol(45, 0);
	return 0;
	system("pause");
}