#include <iostream> 
#include <fstream> 
#include<string>
using namespace std;
int lines=0;
int search(string search)
{
	int found=0;
	ifstream in_stream;
    string str;
    in_stream.open ("Database.txt", ios::in | ios::binary);
    
    while (!in_stream.eof())  //Loop to find the lines where words are
    {getline(in_stream, str); //inputs information of file into string
     lines++;                 //Line counter
     if ((str.find(search, 0)) != string::npos) //If the word is found
        {
        found=1; 
        }
    }
    return found;
}
replace(string search ,string replace) 
{ 
    int found=0;
	ifstream in_stream;
    string str;
    in_stream.open ("Database.txt", ios::in | ios::binary);
    
    while (!in_stream.eof())  //Loop to find the lines where words are
    {getline(in_stream, str); //inputs information of file into string
     lines++;                 //Line counter
     if ((str.find(search, 0)) != string::npos) //If the word is found
        {
        found=1; 
        }
    }
    in_stream.seekg (0, ios::beg);
    if(found=1)
    {
    while (!in_stream.eof())  //Loop to find the lines where words are
    {getline(in_stream, str); //inputs information of file into string
     if ((str.find(search, 0)) != string::npos) //If the word is found
        {
        str.replace(lines, search.size(), replace);
        lines++; 
        }
    }
    }
}
void replace2(string search,string replace) 
{	
ifstream inputFileStream("Database.txt", ifstream::in);
ofstream outputFileStream("Database.txt");	
string fileLine;
    while (getline(inputFileStream, fileLine))
    {
        size_t substringPos = fileLine.find(search);
        if (substringPos != string::npos)
        {
            fileLine.replace(substringPos, search.size(), replace);
        }       
        outputFileStream << fileLine << '\n';
        outputFileStream.close();
        inputFileStream.close();
    }
}
main()
{
	int  res;
	string passWord,newpass;
cout<<"Enter old Password : ";
cin>>passWord;
cout<<"Enter new password : ";
cin>>newpass;
replace2(passWord,newpass);
cout<<"\nYOUR PASSWORD WAS UPDATED!\n\n";
}
