#include<stdio.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<sys/wait.h>
#include<unistd.h>
#include<string.h>

int main()
{
        int fd;
        char* myfifo = "/home/fatima/myfifo.txt";
        mkfifo(myfifo, 0666);
        while(1){
        char arr1[80], arr2[80];
        fd = open(myfifo, O_WRONLY);
        fgets(arr2, 80, stdin);
        write(fd, arr2, strlen(arr2)+1);
        close(fd);
        fd = open(myfifo, O_RDONLY);
        read(fd, arr1, sizeof(arr1));
        printf("User2: %s\n", arr1);
        close(fd);
        }
        return 0;
}