#include<unistd.h>
#include<sys/wait.h>
#include<stdlib.h>

int main(int argc, char* argv[])
{
  pid_t pid = fork();
  if(pid == 0) //child process
  {
    execv("./hello",NULL);
  }
  else if(pid > 0) //parent process
  {
    wait(NULL);
  }
  else
  {
    return 0;
  }
  return 0;
}