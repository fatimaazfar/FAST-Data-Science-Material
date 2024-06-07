#include<iostream>
#include<fstream>
#include<string.h>
#include<stdlib.h>

using namespace std;
void login();
void registr();
void forget();

main()
{
	cout<<"*********************** NAVEED'S LOGIN PAGE **************************\n\n"<<endl;
	cout<<"1: login"<<endl;
	cout<<"2: register"<<endl;
	cout<<"3: forget details.., dont worry! we can fix it :)\n\n"<<endl;
	
	int choice;
	cout<<"please enter the choice (1 for login, 2 for register and 3 if u forget something) : ";
	cin>> choice;
	if( choice==1)
	{
		login();
	}
	else if ( choice ==2)
	{
		registr();
	}
	else if ( choice ==3)
	{
		forget();
	}
	else
	{
		cout<<"Thanks for using login page";
	}
}

void registr()
{
	string reg_user,reg_pass;
	system("cls");
	cout<<"enter the username : ";
	cin>> reg_user;
	cout<<"enter the password : ";
	cin>> reg_pass;
	for(int i=0;reg_pass[i]!='\0';i++)
	{
		reg_pass[i]-=5;
	}
	
	
	ofstream reg("database.txt",ios::app);
	reg<<reg_user<<"\t\t"<<reg_pass<<endl;
	system ("cls");
	
	cout<<"registeration successful!"<<endl;
	main();	
}
void login()
{
	int exist;
	string userName,passWord,u,p;
	system ("cls");
	
	cout<<"please enter the username : ";
	cin>> userName;
	cout<<"please enter the password : ";
	cin>> passWord;
	for(int i=0;passWord[i]!='\0';i++)
	{
		passWord[i]-=5;
	}
	
	ifstream input("database.txt");
	while(input>>u>>p)
	{
		if(u == userName && p == passWord)
		{
			exist = 1;
		}
	}
		
	input.close();
	if ( exist == 1)
	{
		cout<<"Hello "<<userName<<" !"<<endl;
		cout<<"Welcome to my login page"<<endl;
		cin.get();
		cin.get();
		main(); 	
	}
	else
	{
		cout<<" login error!"<<endl;
		cin.get();
		cin.get();
		main();
	}
}
void forget()
{
	int ch;
	system("cls");
	
	cout<<"1: search your id by username"<<endl;
	cout<<"2: search your id by password"<<endl;
	cout<<"3: Main menu\n"<<endl;
	cout<<" enter your choice(1,2 or 3) : ";
	cin>> ch;
	
	switch (ch)
	{
		case 1:
			{
			
			int ex =0;
			string s_user, su,sp;
			cout<<" enter your existing username : ";
			cin>> s_user;
			
			ifstream searchUser("database.txt");
			while ( searchUser>>su>>sp)
			{
				if (su==s_user)
				{
					ex = 1;
					break;
				}
			}
			searchUser.close();
			if(ex == 1)
			{
				cout<<" account found in database..!";
				for(int i=0;sp[i]!='\0';i++)
			{
				sp[i]+=5;
			}
				cout<<" your password is : "<<sp<<endl;
				cin.get();
				cin.get();
				main();
			}
			else
			{
				cout<<" account not found :/"<<endl;
				cin.get();
				cin.get();
				main();
			}
			break;
			}
		case 2:
			{
			
			int exi = 0;
			string s_pass, su2,sp2;
			cout<<" enter the existing password : ";
			cin>> s_pass;
			for(int i=0;s_pass[i]!='\0';i++)
			{
				s_pass[i]-=5;
			}
			 
			 
			ifstream searchp("database.txt");
			while( searchp>>su2>>sp2)
			{
				if( sp2 == s_pass)
				{
				exi = 1;
				break;
				}
			}
			searchp.close();
			if(exi == 1)
			{
				cout<<" the account found in database...!"<<endl;
				cout<<" your username is : "<<su2<<endl;
				for(int i=0;sp2[i]!='\0';i++)
			{
				sp2[i]+=5;
			}
				cout<<" your password is : "<<sp2<<endl;
				cin.get();
				cin.get();
				main();
			}
			else 
			{
				cout <<" error...:/"<<endl;
			}
			break;
			}
		case 3:
			{
			
			main();
			break;
			}
			
		default :
			{
			
			cout<<"you have given a  wrong choice ...:/"<<endl;
			cout<<"press any key to try again "<<endl;
			cin.get();
			cin.get();
			forget();
			}
	}
}
