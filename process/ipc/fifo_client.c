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
    fd = open(TEST,O_RDONLY);
        perror("open");
    check = read(fd,string,sizeof(test));
    printf("read %d\n",check);
    printf("read ok:%s\n",string);
    exit(0);
}
