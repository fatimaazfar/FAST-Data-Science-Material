#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
int main()
{
	int input;
	int c;
	char str[20];
	while(1)
	{
	cout<<"Enter\n'1' to write in file\n'2' to read from file\n'3' to terminate program : ";
	cin>>input;
	cout<<"\n\n";
	FILE *fp;
	switch(input)
	{
		case 1:
			cout<<"Enter in character array (20 char limit) : ";
			cin>>str;
			fp=fopen("file.txt","w");
			if(fp)
			{
				for(int i=0;i<strlen(str);i++)
				{
					putc(str[i],fp);
				}
			}
			else
			{
				perror("File opening failed");
		    }
		    fclose(fp);
			cout<<"\n\n";
			break;
		case 2:
			fp=fopen("file.txt","r");
			if(fp)
			{
				while(feof(fp)==0)
				{
					c=getc(fp);
					putchar(c);
				}
			}
			else
			{
				perror("File opening failed");
			}
			fclose(fp);	
			cout<<"\n\n";
			break;
		case 3:
		    goto x;	
		    break;
		default:
		    goto x;    
	}
    }
	x:
	return 0;
}
