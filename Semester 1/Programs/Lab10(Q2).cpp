#include<iostream>
#include<string.h>
#include<stdio.h>
#include<fstream>
using namespace std;
void Write()
{	std::fstream file;
	file.open ("Q2.txt",ios::app);
	char ch,string[100];
	cout<<"Enter line : ";
	cin.getline(string,sizeof(string));
	file<<string<<endl;
}
void Reverse()
{
	fstream file;
	file.open("Q2.txt",ios::in);
	char reverse[100];
	while(!file.eof())
	{   file.getline(reverse,100);
		for (int i=strlen(reverse)-1;i>=0;i--)
		    cout<<reverse[i];
		cout<<endl;
	}
}
int main()
{	
    Write();
	
  	fstream file;
	file.open("Q2.txt",ios::in);
	char string[100];
	while(!file.eof())
	{      file.getline(string,100);
		cout<<string<<endl;
	}
	
    Reverse();
    return 0;
}
