// linux shell
#include<iostream>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/types.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
using namespace std;

char cmd[100];//command
char* argv[16];//arguments

void shell()//function to prepare the first display
{
        system("clear");
        cout << "--------------------LINUX SHELL--------------------" << endl;
        string user = getenv("USER");
        cout << "WELCOME " << user << endl;
}

void get_input()//take input from user
{
        cout << "\n>>> ";
        fgets(cmd, 100,stdin);
        if(strlen(cmd)>0 && cmd[strlen(cmd)-1]=='\n')
                cmd[strlen(cmd)-1] = '\0';
}

void exec_arguments()//execute arguments using fork() and execvp() calls
{
        pid_t pid = fork();
        if(pid == 0)
        {
                int e = execvp(argv[0],argv);
                if(e<0)
                        cout << "Execution of arguments failed.";
                exit(0);
        }
        else if(pid > 0)
        {
                wait(NULL);
                return;
        }
        else
                cout << "Forking failed.";
}

void tokenize()//parse the input string
{
        char* ptr;
        int i = 0;
        ptr = strtok(cmd, " ");
        while(ptr!=NULL)
        {
                argv[i] = ptr;
                i++;
                ptr = strtok(NULL, " ");
        }
                if(argv[i-1] == "&")
                {
                        argv[i-1] = NULL;
                        argv[i] = "&";
                }
                else
                        argv[i] = NULL;
}

void get_cd()//gets the current directory
{
        char cwd[1024];
        getcwd(cwd,sizeof(cwd));
        cout << "Dir: " << cwd;
}

int main()
{
        shell();
        while(1)//loop until an exit is entered
        {
                get_input();
                if(!strcmp("",cmd))
                        continue;
                if(!strcmp("exit",cmd))
                        break;
                if(!strcmp("cd",cmd))
                        get_cd();
                else
                {
                        tokenize();
                        exec_arguments();
                }
        }
        return 0;
}