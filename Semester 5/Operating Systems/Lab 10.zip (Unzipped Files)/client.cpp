#include <iostream>
using namespace std;
#include <sys/shm.h>
#include <string>

#include <stdio.h>
#include <cstring>

class Student
{
public:
  int rollNumber;
  char name[20];


};

int main()
{

 int key=shmget(12321, 1024, 0 ); //We have not passed IPC_CREAT, this means that it will always use existing shared region. 

 Student* ptr= (Student*) shmat(key, NULL, 0); //this call will attach the shared region to this process's address space, and return the  pointer to it. the original pointer returned is void* we can typecast it to any kind of pointer.

ptr[1].rollNumber=1; //student 1
strcpy(ptr[1].name,"ABC");

ptr[2].rollNumber=2; //student 2
strcpy(ptr[2].name,"XYZ");

 ptr[0].rollNumber=2; //number of students

 //detach
 shmdt(ptr);


}
