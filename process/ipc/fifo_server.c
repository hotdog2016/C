#include<stdlib.h>
#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
char * TEST= "/home/hotdog/c/c_work/process/ipc/file/test";
int main()
{
    int fd;
    char test[20] = "hello";
    char string[20];
    int check;
    mkfifo(TEST,0777);
    fd = open(TEST,O_WRONLY);
        perror("open");
    check = write(fd,test,sizeof(test));
    printf("wirte ok!\nwrite %d\n",check);
    exit(0);
}
