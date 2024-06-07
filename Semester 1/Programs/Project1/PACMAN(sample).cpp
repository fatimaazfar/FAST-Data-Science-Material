//Coded by James Leshko

#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <ctime>

using namespace std;
// 35 = walls
//111 = small pills
// 79 = power pills
//074 = pacman right
//076 = pacman left
//118 = pacman up
//94 = pacman down
// 87 = ghost1
// 88 = ghost2
// 89 = ghost3

const int MAXROWS = 32;
const int MAXCOLUMNS = 28;

char keyboardValue = 127;
//Start position is [15][0]
int pacI = 15, pacJ = 0;
//Ghost1 Start postion is [16][14]
int ghostOneI = 16, ghostOneJ = 14;
int node1i = 16, node1j = 5;
int i = 0 , j = 0;
char key = 127;

char levelMatrix[MAXROWS][MAXCOLUMNS] = 
    {
	   { 35,  35,  35,  35,  35,  35,  35,  35,  35,  35,  35,  35,  35,  35,  35,  35,  35,  35,  35,  35,  35,  35,  35,  35,  35,  35,  35,  35},
	   { 35, 111, 111, 111, 111, 111, 111, 111, 111, 111, 111, 111, 111,  35,  35, 111, 111, 111, 111, 111, 111, 111, 111, 111, 111, 111, 111,  35},
	   { 35, 111,  35,  35,  35,  35, 111,  35,  35,  35,  35,  35, 111,  35,  35, 111,  35,  35,  35,  35,  35, 111,  35,  35,  35,  35, 111,  35},
	   { 35,  79,  35,  35,  35,  35, 111,  35,  35,  35,  35,  35, 111,  35,  35, 111,  35,  35,  35,  35,  35, 111,  35,  35,  35,  35,  79,  35},
	   { 35, 111,  35,  35,  35,  35, 111,  35,  35,  35,  35,  35, 111,  35,  35, 111,  35,  35,  35,  35,  35, 111,  35,  35,  35,  35, 111,  35},
	   { 35, 111, 111, 111, 111, 111, 111, 111, 111, 111, 111, 111, 111, 111, 111, 111, 111, 111, 111, 111, 111, 111, 111, 111, 111, 111, 111,  35},
	   { 35, 111,  35,  35,  35,  35, 111,  35,  35, 111,  35,  35,  35,  35,  35,  35,  35,  35, 111,  35,  35, 111,  35,  35,  35,  35, 111,  35},
	   { 35, 111,  35,  35,  35,  35, 111,  35,  35, 111,  35,  35,  35,  35,  35,  35,  35,  35, 111,  35,  35, 111,  35,  35,  35,  35, 111,  35},
	   { 35, 111, 111, 111, 111, 111, 111,  35,  35, 111, 111, 111, 111,  35,  35, 111, 111, 111, 111,  35,  35, 111, 111, 111, 111, 111, 111,  35},
	   { 35,  35,  35,  35,  35,  35, 111,  35,  35,  35,  35,  35, 000,  35,  35, 000,  35,  35,  35,  35,  35, 111,  35,  35,  35,  35,  35,  35},
	   { 35,  35,  35,  35,  35,  35, 111,  35,  35,  35,  35,  35, 000,  35,  35, 000,  35,  35,  35,  35,  35, 111,  35,  35,  35,  35,  35,  35},
	   { 35,  35,  35,  35,  35,  35, 111,  35,  35, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000,  35,  35, 111,  35,  35,  35,  35,  35,  35},
	   { 35,  35,  35,  35,  35,  35, 111,  35,  35, 000,  35,  35, 000, 000, 000, 000,  35,  35, 000,  35,  35, 111,  35,  35,  35,  35,  35,  35},
	   { 35,  35,  35,  35,  35,  35, 111,  35,  35, 000,  35, 000, 000, 000, 000, 000, 000,  35, 000,  35,  35, 111,  35,  35,  35,  35,  35,  35},
	   { 35,  35,  35,  35,  35,  35, 111,  35,  35, 000,  35, 000, 000, 000, 000, 000, 000,  35, 000,  35,  35, 111,  35,  35,  35,  35,  35,  35},
	   {074, 000, 000, 000, 000, 000, 111, 000, 000, 000,  35, 000, 000, 000, 000, 000, 000,  35, 000, 000, 000, 111, 000, 000, 000, 000, 000, 000},
	   { 35,  35,  35,  35,  35,  35, 111,  35,  35, 000,  35, 000, 000, 000, 000, 000, 000,  35, 000,  35,  35, 111,  35,  35,  35,  35,  35,  35},
	   { 35,  35,  35,  35,  35,  35, 111,  35,  35, 000,  35, 000, 000, 000, 000, 000, 000,  35, 000,  35,  35, 111,  35,  35,  35,  35,  35,  35},
	   { 35,  35,  35,  35,  35,  35, 111,  35,  35, 000,  35,  35, 000, 000, 000, 000,  35,  35, 000,  35,  35, 111,  35,  35,  35,  35,  35,  35},
	   { 35,  35,  35,  35,  35,  35, 111,  35,  35, 000, 000, 000, 000, 000, 000, 000, 000, 000, 000,  35,  35, 111,  35,  35,  35,  35,  35,  35},
	   { 35,  35,  35,  35,  35,  35, 111,  35,  35, 000,  35,  35,  35,  35,  35,  35,  35,  35, 000,  35,  35, 111,  35,  35,  35,  35,  35,  35},
	   { 35, 111, 111, 111, 111, 111, 111, 111, 111, 111, 111, 111, 111,  35,  35, 111, 111, 111, 111, 111, 111, 111, 111, 111, 111, 111, 111,  35},
	   { 35, 111,  35,  35,  35,  35, 111,  35,  35,  35,  35,  35, 111,  35,  35, 111,  35,  35,  35,  35,  35, 111,  35,  35,  35,  35, 111,  35},
	   { 35, 111,  35,  35,  35,  35, 111,  35,  35,  35,  35,  35, 111,  35,  35, 111,  35,  35,  35,  35,  35, 111,  35,  35,  35,  35, 111,  35},
	   { 35,  79, 111, 111,  35,  35, 111, 111, 111, 111, 111, 111, 111, 111, 111, 111, 111, 111, 111, 111, 111, 111,  35,  35, 111, 111,  79,  35},
	   { 35,  35,  35, 111,  35,  35, 111,  35,  35, 111,  35,  35,  35,  35,  35,  35,  35,  35, 111,  35,  35, 111,  35,  35, 111,  35,  35,  35},
	   { 35,  35,  35, 111,  35,  35, 111,  35,  35, 111,  35,  35,  35,  35,  35,  35,  35,  35, 111,  35,  35, 111,  35,  35, 111,  35,  35,  35},
	   { 35, 111, 111, 111, 111, 111, 111,  35,  35, 111, 111, 111, 111,  35,  35, 111, 111, 111, 111,  35,  35, 111, 111, 111, 111, 111, 111,  35},
	   { 35, 111,  35,  35,  35,  35,  35,  35,  35,  35,  35,  35, 111,  35,  35, 111,  35,  35,  35,  35,  35,  35,  35,  35,  35,  35, 111,  35},
	   { 35, 111,  35,  35,  35,  35,  35,  35,  35,  35,  35,  35, 111,  35,  35, 111,  35,  35,  35,  35,  35,  35,  35,  35,  35,  35, 111,  35},
	   { 35, 111, 111, 111, 111, 111, 111, 111, 111, 111, 111, 111, 111, 111, 111, 111, 111, 111, 111, 111, 111, 111, 111, 111, 111, 111, 111,  35},
	   { 35,  35,  35,  35,  35,  35,  35,  35,  35,  35,  35,  35,  35,  35,  35,  35,  35,  35,  35,  35,  35,  35,  35,  35,  35,  35,  35,  35}
    };

char ghostCurrent = levelMatrix[ghostOneI][ghostOneJ];
char ghostTrail = ghostCurrent[&ghostOneI][&ghostOneJ];

void getKeyPress();
bool blockValid(int block);
void Ghost();
void GoToXY(int column, int line);
bool ghostMoveUp();
bool ghostMoveDown();
bool ghostMoveLeft();
bool ghostMoveRight();
int findNode();

int pillCount = 244;
int lives = 3;
clock_t startTime = 0, endTime= 0;
bool superPellet = false;
bool pill = false;



int main()
{
    HANDLE  hConsole;
    int k =14;

    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, k);

    cout << "       ###############			   "<< endl;         
    cout << "      ##################		   "<< endl;       
    cout << "    #######################		   "<< endl;         
    cout << "  ##############   ###########				   "<< endl;
    cout << "##############################				   "<< endl;
    cout << "#######################				   "<< endl;
    cout << "####################			   "<< endl;
    cout << "################			   "<< endl;
    cout << "#############			   "<< endl;
    cout << "###########				   "<< endl;   
    cout << "#########					   "<< endl;
    cout << "############			   "<< "PACMAN" << endl;         
    cout << "##################		   "<< endl;       
    cout << "#######################		   "<< endl;         
    cout << "###########################				   "<< endl;
    cout << "##############################				   "<< endl;
    cout << "    #######################				   "<< endl;
    cout << "      ####################			   "<< endl;
    cout << "        ################			   "<< endl;

    cout << endl;
    system("pause");
    char key = 0;
    system("mode 80, 50");
    int pills = 30;
    bool stopCounting  = false;
    //create the matrix 
    //28 columns
    //32 high

    do
    {
	   //Set Start position
	   GoToXY(0, 0);
	   Ghost();
	   //Column
	   for (i = 0; i <= 31; i++)
	   {
		  //Row
		  for (j = 0; j <= 27; j++)
		  {
			 //Walls
			 if (levelMatrix[i][j] == 35)
			 {
				k = 1;
				SetConsoleTextAttribute(hConsole, k);
			 }
			 //Pacman
			 else if (levelMatrix[i][j] == 074 || levelMatrix[i][j] == 076 || levelMatrix[i][j] == 118 ||levelMatrix[i][j] == 94)
			 {
				k = 14;
				SetConsoleTextAttribute(hConsole, k);
			 }
			 //Blank
			 else if (levelMatrix[i][j] == 000)
			 {
				k = 0;
				SetConsoleTextAttribute(hConsole, k);
			 }
			 //Ghost
			 else if (levelMatrix[i][j] == 87)
			 {
				if (superPellet)
				{
				    k = 7;
				    SetConsoleTextAttribute(hConsole, k);
				}
				else
				{
				    k = 4;
				    SetConsoleTextAttribute(hConsole, k);
				}
			 }
			 //pill
			 else if (levelMatrix[i][j] == 111)
			 {
				k = 15;
				SetConsoleTextAttribute(hConsole, k);
			 }
			 //Power pill
			 else if (levelMatrix[i][j] == 79)
			 {
				k = 14;
				SetConsoleTextAttribute(hConsole, k);
			 }

			 cout << levelMatrix[i][j];
			 if ( j == 27)
				cout << endl;

			 if ( j == 27 && i == 31)
				stopCounting = true;
		  }  
	   }
	   getKeyPress();
	   //Color
	   k = 15;
	   SetConsoleTextAttribute(hConsole, k);
	   
	   cout << "lives remaining " << lives << endl;
	   endTime = clock();
	   int elapsed = int((endTime - startTime) / CLOCKS_PER_SEC);
	   //cout  << elapsed;

	   if (elapsed > 5)
	   {
		  superPellet = false;
		  elapsed = 0;
	   }
    }
    while (lives >= 0 || pillCount != 0);
    
    	system("pause");
	return 0;
};

bool ghostMoveUp()
{
    char ghostNextUp = levelMatrix[ghostOneI - 1][ghostOneJ];
      //Check the next upward block to be sure it is not a wall
    if ( ghostNextUp != 35)
    {
	   //Check the last block to see if there was a pill
	   if ( ghostNextUp == 111 || ghostNextUp == 117 )
	   {
		  //put the pill back
		  levelMatrix[ghostOneI - 1][ghostOneJ] = 87;

		  levelMatrix[ghostOneI][ghostOneJ] = ghostTrail;
		  ghostOneI--;
	   }
	   else
	   {
		  pill = false;
		  levelMatrix[ghostOneI][ghostOneJ] = 000;
		  levelMatrix[ghostOneI - 1][ghostOneJ] = 87;
		  ghostOneI--;
	   }
	   return true;
    }
    else
    {
	   return false;
    }
}

bool ghostMoveDown()
{

    char ghostNextDown = levelMatrix[ghostOneI + 1][ghostOneJ];
    if ( ghostNextDown != 35)
    {
	   if ( ghostNextDown == 111 || ghostNextDown ==117)
	   {
		  levelMatrix[ghostOneI + 1][ghostOneJ] = 87;
		  levelMatrix[ghostOneI][ghostOneJ] = ghostNextDown;
		  ghostOneI++;
	   }
	   else
	   {
		  levelMatrix[ghostOneI][ghostOneJ] = 000;
		  levelMatrix[ghostOneI + 1][ghostOneJ] = 87;
		  ghostOneI++;
	   }
	   return true;
    }
    else
    {
	   return false;
    }
}

bool ghostMoveLeft()
{
    char ghostNextLeft = levelMatrix[ghostOneI][ghostOneJ - 1];
    if ( ghostNextLeft != 35)
	   {
		  if ( ghostNextLeft == 111 || ghostNextLeft ==117)
		  {
			 levelMatrix[ghostOneI][ghostOneJ - 1] = 87;
			 levelMatrix[ghostOneI][ghostOneJ] = ghostNextLeft;
			 ghostOneJ--;
		  }
		  else
		  {
			 levelMatrix[ghostOneI][ghostOneJ] = 000;
			 levelMatrix[ghostOneI][ghostOneJ - 1] = 87;
			 ghostOneJ--;
		  }
		   return true;
	   }
        else
	   {
		  return false;
	   }

}

bool ghostMoveRight()
{
    char ghostNextRight = levelMatrix[ghostOneI][ghostOneJ + 1];
    if ( ghostNextRight != 35)
    {
	  
	   if ( ghostNextRight == 111 || ghostNextRight ==117)
	   {
		  levelMatrix[ghostOneI][ghostOneJ + 1] = 87;
		  levelMatrix[ghostOneI][ghostOneJ] = ghostNextRight;
		  ghostOneJ++;
	   }
	   else
	   {
		  levelMatrix[ghostOneI][ghostOneJ] = 000;
		  levelMatrix[ghostOneI][ghostOneJ + 1] = 87;
		  ghostOneJ++;
	   }
	   return true;
    }
    else
    {
	   return false;
    }

}

void Ghost()
{
    if (superPellet)
    {
	   //Ghost is moving up 
	   if ( pacI > ghostOneI)
	   {
		  //if wall found
		  if (!ghostMoveUp())
		  { 
			 //find node path 
		  }
	   }
    
	   //Ghost is moving down
	   else if (pacI < ghostOneI)
	   {
		  if (!ghostMoveDown())
		  {

		  }
	   }

	   //Ghost is moving left
	    if (pacJ > ghostOneJ)
	   {
		  if (!ghostMoveLeft())
		  {

		  }
	   }

	   //Ghost is moving right
	   else if (pacJ < ghostOneJ)
	   {
		  if (!ghostMoveRight())
		  {

		  }
	   }
    }
    else
    {


	   //Ghost is moving up 
	   if ( pacI < ghostOneI)
	   {

		  //if wall found
		  if (!ghostMoveUp())
		  { 

		  }
	   }
    
	   //Ghost is moving down
	   else if (pacI > ghostOneI)
	   {
		  if (!ghostMoveDown())
		  {

		  }
	   }

	   //Ghost is moving left
	   if (pacJ < ghostOneJ)
	   {
		  if (!ghostMoveLeft())
		  {

		  }
	   }

	   //Ghost is moving right
	   else if (pacJ > ghostOneJ)
	   {
		  if (!ghostMoveRight())
		  {

		  }
	   }
    }

    //you caught the ghost
    if (pacJ == ghostOneJ && pacI == ghostOneI && superPellet)
    {
	   levelMatrix[ghostOneI][ghostOneJ] = 074;
	   ghostOneI = 16;
	   ghostOneJ = 14;
	   levelMatrix[16][14] = 87;
    }
    //Reset the postion of pacman you died
    else if (pacJ == ghostOneJ && pacI == ghostOneI)
    {
	   lives--;
	   levelMatrix[pacI][pacJ] = 000;
	   levelMatrix[ghostOneI][ghostOneJ] = 000;
	   pacI = 15;
	   pacJ = 0;
	   ghostOneI = 16;
	   ghostOneJ = 14;
	   levelMatrix[15][0] = 074;
	   levelMatrix[16][14] = 87;
    }
}

void getKeyPress()
{
	key = _getch();
    char pacTemp = '<';
	//get a special key
	if (key == 0 || key == -32)  
	{
		key = _getch();

		if (key == 72) //up
		{
		   if ( levelMatrix[pacI- 1][pacJ] != 35)
		   {
			 if (levelMatrix[pacI- 1][pacJ] == 79)
			 {
				startTime = clock();
				superPellet = true;
			 }
			 levelMatrix[pacI][pacJ] = 000;
			 levelMatrix[pacI - 1][pacJ] = 118;
			 pacI--;
		   }
		}
		else if (key == 75) //left
		{
		    if ( levelMatrix[pacI][pacJ- 1] != 35)
		    {
			 if (levelMatrix[pacI][pacJ - 1] == 79)
			 {
				startTime = clock();
				superPellet = true;
			 }
			 levelMatrix[pacI][pacJ] = 000;
			 levelMatrix[pacI][pacJ - 1] = 076;
			 pacJ--;
		    }
		}
		else if (key == 77) //right
		{
		    if ( levelMatrix[pacI][pacJ+ 1] != 35)
		    {
			 if (levelMatrix[pacI][pacJ + 1] == 79)
			 {
				startTime = clock();
				superPellet = true;
			 }
			 levelMatrix[pacI][pacJ] = 000;
			 levelMatrix[pacI][pacJ + 1] = 074;
			 pacJ++;
		    }
		}
		else if (key == 80) //down
		{
		   if ( levelMatrix[pacI + 1][pacJ] != 35)
		   {
			 if (levelMatrix[pacI + 1][pacJ] == 79)
			 {
				startTime = clock();
				superPellet = true;
			 }
			 levelMatrix[pacI][pacJ] = 000;
			 levelMatrix[pacI + 1][pacJ] = 94;
			 pacI++;
		   }
	   }
    }
}

void GoToXY(int column, int line)
{
    // Create a COORD structure and fill in its members.
    // This specifies the new position of the cursor that we will set.
    COORD coord;
    coord.X = column;
    coord.Y = line;

    // Obtain a handle to the console screen buffer.
    // (You're just using the standard console, so you can use STD_OUTPUT_HANDLE
    // in conjunction with the GetStdHandle() to retrieve the handle.)
    // Note that because it is a standard handle, we don't need to close it.
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    // Finally, call the SetConsoleCursorPosition function.
    if (!SetConsoleCursorPosition(hConsole, coord))
    {
        // Uh-oh! The function call failed, so you need to handle the error.
        // You can call GetLastError() to get a more specific error code.
        // ...
    }
}



