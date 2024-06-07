#include<iostream>
#include<windows.h>
#include<conio.h>
#include<stdio.h>
//#include<graphics.h>
using namespace std;
bool gameover;//global bool variable represents true for game over, false for game not over
int width =40;//global variables
int length =25;
char level,in;
int x,y,gx,gy,fruitx,fruity,score;//global variables for all functions
int tailX[100], tailY[100];//arrays for storing the axis of tail segments
int nTail;//tail length counter
enum eDirection{STOP=0,LEFT,RIGHT,UP,DOWN};//constants
eDirection dir;//a direction directory from where we can call all the constants
void setup()//general game setup function
{
	gameover=false;
	dir=STOP; //this makes the snake stop at one position when game starts untill the user clicks a key
	x=width/2;//determining the position of snake head
	y=length/2;
	gx=2;
	gy=2;
	fruitx= rand() % width;//laying fruits at random axis using rand()
	fruity= rand() % length;
	score=0;
	nTail=0;
}
void draw()//prints everything going on on console screen
{
	system("cls");
	//map printing
	if(level=='e'||level=='E')
	{
	for(int i=0;i<=width+1;i++)//printing the top wall
	{
		cout<<"#";
	}
	cout<<endl;
	for(int i=0;i<length;i++)//this loop continuosly updates and prints the inner body of the map
	{
		for(int j=0;j<width;j++)
		{
			if(j==0)//printing side wall
			{
				cout<<"#";
			}
			if(i==y && j==x)//printing the snake's head
			{
				cout<<"O";
			}
			else if(i==gx && j==gy)//printing the ghost
		    {
		    	cout<<"G";
			}
			else if(i==fruity && j==fruitx)//printing the fruit
			{
				cout<<"F";
			}
			else//printing the tail of snake
			{
				bool print = false;
				for (int k = 0; k < nTail; k++)
				{
					if (tailX[k] == j && tailY[k] == i)
					{
						cout << "o";
						print = true;
					}
				}
            	if(!print)//prints blank space after the snake has passed by an axis
		   	    	{
		   		 		cout<<" ";
					}	
		    }
			if(j==width-1)//printing side wall
			{
				cout<<"#";
			}
		}
		cout<<endl;//for making the map square shaped
	}
	for(int i=0;i<=width+1;i++)//printing the bottom wall
	{
		cout<<"#";
	}
	cout<<endl;
    }
    //2nd medium level map
else if(level=='m'||level=='M')
	{
		width=60;
		length=30;
    for(int i=0;i<=width+1;i++)//printing the top wall
	{
		cout<<"#";
	}
	cout<<endl;
	for(int i=0;i<length;i++)//this loop continuosly updates and prints the inner body of the map
	{
		for(int j=0;j<width;j++)
		{
			if(j==0)//printing side wall
			{
				cout<<"#";
			}
			if(i==y && j==x)//printing the snake's head
			{
				cout<<"O";
			}
			else if(i==gx && j==gy)//printing the ghost
		    {
		    	cout<<"G";
			}
			else if(i==fruity && j==fruitx)//printing the fruit
			{
				cout<<"F";
			}
			else//printing the tail of snake
			{
				bool print = false;
				for (int k = 0; k < nTail; k++)
				{
					if (tailX[k] == j && tailY[k] == i)
					{
						cout << "o";
						print = true;
					}
				}
            	if(!print)//prints blank space after the snake has passed by an axis
		   	    	{
		   		    	cout<<" ";
					}	
		    }
			if(j==width-1)//printing side wall
			{
				cout<<"#";
			}
		}
		cout<<endl;//for making the map square shaped
	}
	for(int i=0;i<=width+1;i++)//printing the bottom wall
	{
		cout<<"#";
	}
	cout<<endl;	
    }
    //3rd hard level map
    else if(level=='H' || level=='h')
    {
		width=60;
		length=30;
    for(int i=0;i<=width+1;i++)//printing the top wall
	{
		cout<<"#";
	}
	cout<<endl;
	for(int i=0;i<length;i++)//this loop continuosly updates and prints the inner body of the map
	{
		for(int j=0;j<width;j++)
		{
			if(j==0)//printing side wall
			{
				cout<<"#";
			}
			if(i==y && j==x)//printing the snake's head
			{
				cout<<"O";
			}
			else if(i==gx && j==gy)//printing the ghost
		    {
		    	cout<<"G";
			}
			else if(i==fruity && j==fruitx)//printing the fruit
			{
				cout<<"F";
			}
			else//printing the tail of snake
			{
				bool print = false;
				for (int k = 0; k < nTail; k++)
				{
					if (tailX[k] == j && tailY[k] == i)
					{
						cout << "o";
						print = true;
					}
				}
            	if(!print)//prints blank space after the snake has passed by an axis
		   	    	{
		   		    	cout<<" ";
					}	
		    }
			if(j==width-1)//printing side wall
			{
				cout<<"#";
			}
		}
		cout<<endl;//for making the map square shaped
	}
	for(int i=0;i<=width+1;i++)//printing the bottom wall
	{
		cout<<"#";
	}
	cout<<endl;	
    }
	cout<<"Score: "<<score;//printing score
}
void logic()//the logic of how everything works
{
	int prevX = tailX[0];//arrays that store the x and y coordinates of the tail of snake
	int prevY = tailY[0];
	int prev2X, prev2Y;//variables to hold the previous axis of the snake tail segments
	tailX[0] = x;//initializing the first index of array with the axis of snake's head
	tailY[0] = y;
	for (int i = 1; i < nTail; i++)//this loop continuosly stores the previous axis of snake's head and the segments follow
	{
		prev2X = tailX[i];
		prev2Y = tailY[i];
		tailX[i] = prevX;
		tailY[i] = prevY;
		prevX = prev2X;
		prevY = prev2Y;
	}
	switch(dir)//this switch statement defines the controls through arrow keys that move the snake's head
	{
		case RIGHT:
			x++;
       		break;
       	case LEFT:
       		x--;
			break;
		case UP:
			y--;
			break;
		case DOWN:
			y++;
	}	 
	//these two if else statements are used to make the snakes pass through the walls 
	if (x >= width) 
	    {
		x = 0;
	    }
	else if (x < 0) 
	    {
		x = width - 1;
	    }
	if (y >= length)
	    {
		y = 0; 
		}
	else if (y < 0)
	    {
		y = length - 1; 
		}
	//the same condition for the ghost to pass through walls
    if (gx >= width) 
	    {
		gx = 0;
	    }
	else if (gx < 0) 
	    {
	    gx = width - 1;
	    }
	if (gy >= length)
	    {
	    gy = 0;
		}
	else if (gy < 0)
	    {
	    gy= length - 1;
		}  		 
	int temptail=nTail;
	for (int i = 0; i < temptail; i++)
		{
		if (tailX[i] == x && tailY[i] == y)//this ends the game when the snake head hits its own tail or turns directly to the direction of its tail
		    {
			gameover = true;
			}
		if(gx==tailY[i] && gy==tailX[i])//this reduces the points and tail length when ghost crosses the snake tail
		{
		  nTail--;
		  score-=10;
		}  	
	    } 
    //this condition increases the score when a fruit is eaten and prints a new fruit at a random axis
	if (x == fruitx && y == fruity)
		{
			score += 10;
			fruitx = rand() % width;
			fruity = rand() % length;
			nTail++;
		}	
	//these 4 if else statements below determine the automatic movements of the ghost(this is the module where we make the ghost dumber or wiser)	
	if(level=='e'||level=='E')//easy level ghost
	{
	if(x>gx)
   	{
   		gx++;
	}
	else if(x<gx)
	{
		gx--;
	}
   	if(y>gy)
   	{
   		gy--;
	}
	else if(y<gy)
	{
		gy++;
	}
	else if(gx==y && gy==x)//when the ghost strikes the snake head the game is over
	{
		gameover=true;
 	}	
    }
    else if(level=='m'||level=='M')//medium level ghost
    {
  	if(x>gx)
   	{
   		gx++;
	}
	else if(x<gx)
	{
		gx--;
	}
   	if(y>gy)
   	{
   		gy--;
	}
	else if(y<gy)
	{
		gy--;
	}
	else if(gx==y && gy==x)//when the ghost strikes the snake head the game is over
	{
		gameover=true;
 	}
	}
	else if(level=='h'||level=='H')//hard level ghost
	{
	if(x>gx)
   	{
   		gx++;
	}
	else if(x<gx)
	{
		gx--;
	}
   	if(y>gy)
   	{
   		gy++;
	}
	else if(y<gy)
	{
		gy--;
	}
	else if(gx==y && gy==x)//when the ghost strikes the snake head the game is over
	{
		gameover=true;
 	}
	}			
}
void input()//this function deals with the user's input
{
	if(_kbhit())//key board hit function is used to detect whenever the user uses a key from the keyboard
	{
        switch(_getch())//get character takes the key that user entered and exhibits the function it is supposed to perform
        {
        	case 77:
        		dir=RIGHT;
        		break;
        	case 75:
			    dir=LEFT;
				break;
			case 72:
			    dir=UP;
				break;
			case 80:
			    dir=DOWN;
			    break;
			case 'x':
			    gameover=true;			
		}
    }
}
int main()
{
	replay:	
	cout<<"GAMEPLAY MANUAL :\n\n(1) If the ghost hits the snake's head, the game is over!\n(2) If the ghost crosses the snake's body, you will lose 10 points and will lose it's tail length'!\n(3) If the snake hits it's own body, the game is over!\n(4) If the snake moves in the direction of it's tail, the game is over!\n(5) The ghost intelligence level is according to the level you choose.\nPress 'X' during the game if you want to exit.\n         BEST OF LUCK!.\n\n";
	cout<<"CHOOSE GAME DIFFICULTY LEVEL\n\n'E' for easy level\n'M' for medium level\n'H' for hard level : ";
	cin>>level;
	setup();
	while(gameover==false)//when game is not over
	{	
	draw();
	input();
	logic();
	Sleep(50);
    }
    if(gameover==true)//when game is over
    {
    	system("cls");
    	cout<<"GAME OVER!\n";
    	cout<<"Your score is "<<score<<endl;
    	cout<<"Enter R if you want to re-play or X if you want to exit : ";
    	cin>>in;
    }
    	if(in=='r'||in=='R')//These conditions execute according to the user's input
    	{
    		goto replay;
		}
		else
		{
		    return 0;
		}
	
}

