#include<iostream>
using namespace std;
int main()
{
	char player1,player2,choice1,choice2;
	int limit,point1=0,point2=0;
	cout<<"Enter first alphabet of your name Player 1 : ";
	cin>>player1;
	cout<<"\nEnter first alphabet of your name Player 2 : ";
	cin>>player2;
	cout<<"\nEnter the game point limit : ";
	cin>>limit;
	cout<<endl<<player1<<" VS "<<player2;
	cout<<"\n\nThe game begins!\n\n";
	for(int i=0 ; i<limit ; i++)
	{
	cout<<player1<<" Enter your choice stone(s), paper(p) or scissors(k)?"<<endl;
	cin>>choice1;
	system("cls");
	cout<<player2<<" Enter your choice stone(s), paper(p) or scissors(k)?"<<endl;
	cin>>choice2;
	system("cls");
	if(choice1==choice2)
	{
	   
    }
	else if(choice1=='s' && choice2=='p')
	{
		point1++;
	}	
	else if(choice2=='s' && choice1=='p')
	{
		point2++;
	}
	else if(choice1=='s' && choice2=='k')
	{
        point1++;
	}	
	else if(choice2=='s' && choice1=='k')
	{
        point2++;
	}
		else if(choice1=='k' && choice2=='p')
	{
		point1++;
	}	
	else if(choice2=='k' && choice1=='p')
	{
		point2++;
	}	
    }
    cout<<player1<<" scored "<<point1<<" and "<<player2<<" scored "<<point2<<endl;
    if(point1==point2)
    {
    	cout<<"\nNO ONE WINS, IT'S A TIE!";
	}
	else if(point1>point2)
	{
		cout<<endl<<player1<<" WINS!";
	}
	else if(point2>point1)
	{
		cout<<endl<<player2<<" WINS!";
	}
}
