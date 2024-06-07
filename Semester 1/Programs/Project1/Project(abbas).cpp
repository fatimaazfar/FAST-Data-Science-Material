#include <iostream>
#include <conio.h>            //to import getch function
#include <stdlib.h>           //to import regix function
#include <unistd.h>

using namespace std;

int main(){
	
	char ground[20][50];         //ground of 20 * 50 declared
	
	for(int i =0;i<20;i++){      // ground intialized with o
		
		for(int j =0 ;j<50;j++){
			
			ground[i][j] = 'o';
			
		}
	}
	
	
	
	
	
	int r = 0;
	int c = 0;
	
	ground[r][c] = 1;                // this is pac man 
	
	for(int row = 0;row<20;row++){
		
		for(int column = 0;column<50;column++ ){          //prints the ground on screen ) is food of pac man
			
			cout<<ground[row][column];
		}
		
		cout<<endl;
	}
	
	while(1){
	
	
	char x;
	
	//cin>>x;

	x = getch();  //instead of cin this function is used , input does not appear on screen.
	
	if(x == 77){
		
		//system("cls");                  //right  this was slow
		//write(1,"\e[1;1H\e[2J",7);
		
		for(int i =0 ;i<100;i++){
			cout<<"\e[1;1H\e[2J";
		}
		
		
		
		//cout<<string(100,'\n');
		
		ground[r][c] = ' ';	
		c++;
		ground[r][c] = 1;
			
	}
		else if(x == 80){                //down
		
		system("cls");
		
		ground[r][c] = ' ';	
		r++;
		ground[r][c] = 1;
			
	}
	
	else if(x == 75){                //left
		
		system("cls");
		
		ground[r][c] = ' ';	
		c--;
		ground[r][c] = 1;
			
	}
	
	else if(x == 72){                //up
		
		system("cls");
		
		ground[r][c] = ' ';	
		r--;
		ground[r][c] = 1;
			
	}
	
	
	
	

	for(int row = 0;row<20;row++){
		
		for(int column = 0;column<50;column++ ){          //prints the ground on screen ) is food of pac man
			
			cout<<ground[row][column];
		}
		
		cout<<endl;
	}
	
}
}

