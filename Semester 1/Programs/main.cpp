#include <iostream>
using namespace std;
#include <conio.h>
#include <Windows.h>


void gotoxy(int x, int y)
{
	COORD coordinates;     // coordinates is declared as COORD
	coordinates.X = x;     // defining x-axis
	coordinates.Y = y;     //defining  y-axis
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates);
}

int const MAX_HEIGHT = 30;
int const MAX_WIDTH = 50;

int main()
{
	int steps = 0;
	int playerX = 10, playerY = 15; //starting position of the player
	
	gotoxy(10, 0);
	cout << "Step Count: " << 0;

	//printing the character at the initial position
	gotoxy(playerX, playerY);
	cout << "*";

	while (true)
	{
	 /*	if a key is pressed _kbhit will return true, otherwise it will return false. So the 
	    body of if will only be executed when the user presses a key. You may need to write 
		code for moving other characters, such as ball in breaks-the-break and enemies
		in pac-man, outside the if's body*/
		if (_kbhit()) 
		{
			gotoxy(10, 0);
			cout << "Step Count: " << steps;

			char key=_getch(); //get the key (which was pressed) without printing the key

			/*you can also add Sleep function if the movement appears to be too fast
			  on your PC.*/
			if (key == 'w') //player will move up
			{
				if (playerY == 0) //the player has reached the upper boundry (vertical)
					continue;

				gotoxy(playerX, playerY);
				cout << ' '; //placing a space at the previous position.

				playerY--; //changing position
				gotoxy(playerX, playerY);
				cout << "*";
				steps++;
			}

			else if (key == 's') //player will move down
			{
				if (playerY == MAX_HEIGHT) //the player has reached the lower boundry (vertical).
					continue;

				gotoxy(playerX, playerY);
				cout << ' '; //placing a space at the previous position.

				playerY++; //changing position
				gotoxy(playerX, playerY);
				cout << "*";
				steps++;
			}

			else if (key == 'a') //player will move left
			{
				if (playerX == 0) //the player has reached the left boundry (horizontal).
					continue;

				gotoxy(playerX, playerY);
				cout << ' '; //placing a space at the previous position.

				playerX--; //changing position
				gotoxy(playerX, playerY);
				cout << "*";
				steps++;
			}

			else if (key == 'd') //player will move right
			{
				if (playerX == MAX_WIDTH) //the player has reached the right boundry (horizontal).
					continue;

				gotoxy(playerX, playerY);
				cout << ' '; //placing a space at the previous position.

				playerX++; //changing position
				gotoxy(playerX, playerY);
				cout << "*";
				steps++;
			}

		}//end of body for if (kbhit()==true)

	}//end of while loop

}