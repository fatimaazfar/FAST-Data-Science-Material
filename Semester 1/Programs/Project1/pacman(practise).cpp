#include<iostream>
#include<windows.h>
#include<conio.h>
#include<stdio.h>
using namespace std;
void gotoxy(short x, short y)           //definition of gotoxy function                                              
{
 COORD pos ={x,y};
 SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
int main()
{
	char a;	
	int x=15,y=0;
	for(int i=0; ;i++)
	{	
	a = getch();
    if(a==77)
    {
    	x++;
	}
	else if(a==75)
	{
		x--;
	}
	else if(a==72)
	{
		y--;
	}
	else if(a==80)
	{
		y++;
	}
	gotoxy(x,y);
    cout<<"*";	}
		
}
