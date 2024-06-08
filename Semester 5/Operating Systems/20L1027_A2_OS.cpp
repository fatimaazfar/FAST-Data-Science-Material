// linux shell
// 20L-1027
// Fatima Azfar
#include <iostream>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <ctype.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <string.h>
using namespace std;

char* cmd = new char[100];//command
char* args[512];//arguments
int read_backup = dup(0); // input backup
int write_backup = dup(1); // output backup
int count; // pipe number
char* history[100];
int history_count = 0;

void get_input()//take input from user
{
        cout << "FatimaShell>> ";
        fgets(cmd, 100,stdin);
        if(strlen(cmd)>0 && cmd[strlen(cmd)-1]=='\n')
            cmd[strlen(cmd)-1] = '\0';
}

void exec_arguments()//execute arguments using fork() and execvp() calls
{
        pid_t pid = fork();
        if(pid == 0)
        {
            int e = execvp(args[0],args);
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

void exec_pipe_args()//execute arguments involving pipes
{
    dup2(write_backup, 1); //directing output to terminal
    pid_t pid;
    pid = fork();
    if (pid < 0) 
    { // error
        cout << "Fork Failed" << endl;
    }
    else if ( pid == 0) 
    { //child process
        execvp(args[0], args);
    }
    else 
    { //parent process
        wait(NULL);
    }    
}

void redirect_pipe()
{
	int fd1[2]; // pipe no. 1
	int fd2[2]; // pipe no. 2
	if(count % 2 == 0)
        {
		pipe(fd1);
		dup2(fd1[1], 1);
		close(fd1[1]);
	}
	else if(count % 2 != 0)
        {
		pipe(fd2);
		dup2(fd2[1], 1);
		close(fd2[1]);
	}
        exec_arguments();
	if(count % 2 == 0)
        {
		dup2(fd1[0], 0);
		close(fd1[0]);
	}
	else if(count % 2 != 0)
        {
		dup2(fd2[0], 0);
		close(fd2[0]);
	}
	count++;
}

void redirect_input(char *fileName)
{
    int in = open(fileName, O_RDONLY);
    dup2(in, 0);
    close(in);
}

void redirect_output(char *fileName)
{
    int out = open(fileName, O_WRONLY | O_CREAT | O_TRUNC, 0777);
    dup2(out, 1);
    close(out);
}

void hist()
{
    int temp = 0;
    if (history_count < 10)
    {
        for (int i = 0;i < history_count;i++)
            cout << i << " " << history[i] << endl;
    }
    else if (history_count >= 10)
    {
        temp = history_count - 10;
        for (int i = 0;i < 10;i++)
        {
            cout << temp << " " << history[i] << endl;
            temp++;
        }
    }
    return;
}

void shell()//function to prepare the first display
{
        while(1)//loop until an exit is entered
        {
            start:
                get_input();
                if (strcmp(cmd,"history") != 0 && cmd[0] != '!')
                {
                    if (history_count < 10)
                    {
                        history[history_count] = new char[100];
                        strcpy(history[history_count],cmd);
                    }
                    else
                    {
                        for (int i = 0; i < 10;i++)
                        {
                            history[i] = history[i + 1];
                        }
                        strcpy(history[9],cmd);
                    }
                    history_count++;
                }
                count = 0; // number of pipes
                char* command = strtok(cmd," ");
                if (strcmp(command, "exit") == 0)
                    break;
                else if (strcmp(command, "history") == 0)
                {
                    hist();
                    goto start;
                }
                else if (strcmp(command,"!!") == 0)
                {
                    if(history_count != 0){
                    delete cmd;
                    cmd = nullptr;
                    cmd = new char[100];
                    if (history_count < 10)
                        strcpy(cmd,history[history_count-1]);
                    else
                        strcpy(cmd,history[9]);
                    command = strtok(cmd," ");
                    }
                    else
                        cout << "No commands in history." << endl;
                }
                else if (cmd[0] == '!')
                {
                    int n = 0;
                    n = int(cmd[1]) - 48;
                    if (n < history_count){
                    delete cmd;
                    cmd = nullptr;
                    cmd = new char[100];
                    if (history_count < 10)
                        strcpy(cmd,history[n]);
                    else
                    {
                        int temp = history_count - n;
                        strcpy(cmd,history[temp]);
                    }
                    command = strtok(cmd," ");
                    }
                    else
                        cout << "No such command exists." << endl;
                }
                char last_operand;
                int i = 0;
                while(command)
                {
                        if (*command == '<')
                        {
                                last_operand = '<';
                                redirect_input(strtok(NULL," "));
                        }
                        else if (*command == '|')
                        {
                                last_operand = '|';
                                args[i] = 0;
                                redirect_pipe();
                                i = 0;
                        }
                        else
                        {
                                args[i] = command;
                                i++;
                        }
                        command = strtok(NULL," ");
                }
        args[i] = NULL;
        if(last_operand == '|')
        	exec_pipe_args();
	    else if(last_operand == '>' || last_operand == '<' || last_operand == '\0')
        	exec_arguments();
        // restore standard input and output
	    dup2(read_backup, 0);
	    dup2(write_backup, 1);
    }
}

int main()
{
        shell();
        return 0;
}