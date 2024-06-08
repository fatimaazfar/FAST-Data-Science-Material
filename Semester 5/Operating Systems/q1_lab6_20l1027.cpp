#include<sys/types.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<cctype>
#include<sys/stat.h>
#include<fcntl.h>
#include<sys/wait.h>
#include<stdio.h>
#include<iostream>
using namespace std;

void palindrome(char arr2[], int n)
{
	char* arr[n];
	char *token;
	int i = 0;
	token = strtok(str, s); // first token
   	while( token != NULL ) {
      	arr[i] = token; // walk through the rest of the tokens
      	token = strtok(NULL, s);
	i += 1; }
	int num, rev=0, rem, temp;
	for(int i = 0;i < n;i++)
	{
		temp = atoi(arr[i]);
		while(temp>0)
		{
			rem = temp%10;
			rev = (rev*10)+rem;
			temp = temp/10;
		}
		if(rev==num)
			cout << num;
	}
	cout << endl;
	}
}

int main(int argc, char* argv[])
{
	//reading file name
	filename = argv[1];
	//piping for parent child communication
	int fd[2];
	int res = pipe(fd);
  	if(res < 0)
		return 1; //piping error
	// piping for reading from file
	int fd2;
	res = pipe(fd2);
  	if(res < 0)
		return 1; //piping error
	// forking
	pid_t pid = fork();
	// buffer
	char buffer[100];
	buffer_size = 100;
	if(pid == 0)
	{
		//child process
		fd2 = open("text.txt",O_RDONLY,S_IRUSR); // open the text file to be read
		int n = read(fd2,buffer,buffer_size); // reading from file
		close(fd2);
		close(fd[0]); // closing read end
		write(fd[1],buffer,n); // writing the message in pipe for parent to read
	}
	else if(pid > 0)
	{
		//parent process
		close(fd[1]); // closing write end
		int n = read(fd[0],buffer,buffer_size);
		palindrome(buffer,n);
	}
	else
		cout << "Forking Failed." << endl;
}