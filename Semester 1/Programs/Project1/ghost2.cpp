#include <iostream>
#include <windows.h> //for gotoxy function

using namespace std;

void gotoxy(short x, short y)
{
	COORD pos = {x, y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

int main()
{
	
	for (int r = 0; r <  10; r++)
		{
			for (int c = 0; c < 10; c++)
			{
			
			system("cls");
			gotoxy(r, c);
			cout << "M";
			Sleep(150);
			}
		}
	/*
	for (int r = 0; r <  10; r++)
		{
			system("cls");
			gotoxy(1, r);
			
			cout << "n ";
			Sleep(200);
		
		}
	for (int r = 0; r <  10; r++)
		{
			system("cls");
			gotoxy(2, r);
			
			cout << "a ";
			Sleep(200);
		
		}
	for (int r = 0; r <  10; r++)
		{
			system("cls");
			gotoxy(3, r);
			
			cout << "s ";
			Sleep(200);
		
		}*/
}
