#include<unistd.h>
#include<stdlib.h>

int main()
{
  pid_t pid, pid2, pid3;
  pid = fork();
  if(pid == 0)//first child
  {
    sleep(3);
    execlp("mkdir","mkdir","Folder1","Folder2",NULL);
  }
  else if(pid > 0)
  {
    pid2 = fork();
    if(pid2 == 0)
    {
      sleep(2);
    }
    else if(pid2 > 0)
    {
      pid3 = fork();
      if(pid3 == 0)//third child
      {
        execlp("mkdir","mkdir","Folder1/mySubFolder",NULL);
      }
      else if(pid > 0)//second child but as the parent of 2nd child
      {
        sleep(3);
        execlp("ls","ls","-S",NULL);
      }
    }
  }
  return 0;
}