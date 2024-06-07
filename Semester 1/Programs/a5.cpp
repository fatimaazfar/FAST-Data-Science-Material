#include <iostream> 
#include <fstream> 
using namespace std; 
int input,input2,res=0,count=0,lines=0;
struct userInfo
{
	string userName;
	string passWord;
};
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
    ifstream in_stream;
    string str;
    in_stream.open ("Database.txt", ios::in | ios::binary);
    
    while (!in_stream.eof())  //Loop to find the lines where words are
    {getline(in_stream, str); //inputs information of file into string
     if ((str.find(search, 0)) != string::npos) //If the word is found
        {
        str.replace(lines, search.size(), replace);
        lines++; 
        }
    }
}
login()
{
	userInfo loginInfo;
	string userName;
	string passWord;
	u:
	cout<<"\nEnter Username : ";
	cin >> userName;
	cout<<"Enter Password : ";
	cin >> passWord;
	for(int i = 0; (i < 10 && passWord[i] != '\0'); i++)
            passWord[i] = passWord[i] + 2;
	ifstream fin("Database.txt");
        while(fin >> loginInfo.userName >> loginInfo.passWord)
        {
                if(loginInfo.userName == userName && loginInfo.passWord == passWord)
        
                {
                        res = 1;
                }
        }
    if(res!=1)
    {
    	cout<<"\nWrong Username or Password, enter again.\n";
    	goto u;
	}    
        fin.close();
	cout<<"\nYOU HAVE SUCCESSFULLY LOGGED IN!\n\n";
	while(1)
	{
	reenter:
	cout<<"Enter :\n\n1 to change password\n2 to change username\n3 to log out : ";
	cin>>input2;
	string newpass,newuser;
	switch(input2)
	{
		case 1:
			{
			p:
			cout<<"Enter old Password : ";
			cin>>passWord;
			for(int i = 0; (i < 10 && passWord[i] != '\0'); i++)
            passWord[i] = passWord[i] + 2;
            res=search(passWord);
   			if(res!=1)
		    {
    			cout<<"\nWrong Password, enter again.\n";
    			goto p;
			}    
			cout<<"Enter new password : ";
			cin>>newpass;
			for(int i = 0; (i < 10 && newpass[i] != '\0'); i++)
                newpass[i] = newpass[i] + 2;
			replace(passWord,newpass);
			cout<<"\nYOUR PASSWORD WAS UPDATED!\n\n";
			break;}
		case 2:
			u2:
			cout<<"\nEnter old username : ";
			cin>>userName;
			res=search(userName);
   			if(res!=1)
		    {
    			cout<<"\nWrong Username, enter again.\n";
    			goto u2;
			}    
			p2:
			cout<<"Enter password : ";
			cin>>passWord;
			res=search(passWord);
   			if(res!=1)
		    {
    			cout<<"\nWrong Password, enter again.\n";
    			goto p2;
			}    
			cout<<"Enter new username : ";
			cin>>newuser;
			replace(passWord,newpass);
			cout<<"\nYOUR USERNAME WAS UPDATED!\n";
			break;
	    case 3:
		    cout<<"\nYOU HAVE LOGGED OUT OF YOUR ACCOUNT SUCCESSFULLY!\n\n";
		    goto out;
		    break;
	    default:
			cout<<"\nInvalid input!\n";
			goto reenter;
    }
    }
out: {};
}
signup()
{
	userInfo signInfo;
	userInfo loginInfo;
	ofstream registerYourself("Database.txt",ios::app);
	registerYourself << endl;
	un2:
	cout<<"\nEnter a Username (less than 20 characters): ";
	cin >> signInfo.userName;
	res=search(signInfo.userName);
    if(res==1)
	{
		cout<<"\nThis username already exists, enter another username.\n";
		goto un2;
	}    
	registerYourself << signInfo.userName << "\t\t\t";
	p2:
	cout<<"\nEnter a Password (between 4 to 10 characters) : ";
	cin >> signInfo.passWord;
	int count=0;
	for(int i = 0; signInfo.passWord[i] != '\0'; i++)
	{
		count++;
	}
	if(count<=3 || count>10)
	{
		cout<<"\nPassword length is invalid, please enter again.";
		goto p2;
	}
	for(int i = 0; (i < 10 && signInfo.passWord[i] != '\0'); i++)
            signInfo.passWord[i] = signInfo.passWord[i] + 2;
	registerYourself << signInfo.passWord;
	registerYourself.close();
	count++;
	cout<<"\nYOU WERE SUCCESSFULLY SIGNED UP!\n\n";
}
int main() 
{ 
int input;
while(1)
{
cout<<"Enter:\n\n'1' for log in\n'2' for sign up\n'3' to exit : ";
cin>>input;
switch(input)
{
case 1:
	login();
	break;
case 2:
	signup();
	break;
case 3:
	goto x;
default:
	cout<<"\nInvalid input! Enter Valid input again.\n\n";
}
}
x:
	return 0; 
} 
