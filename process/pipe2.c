#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    int pip[2];
    int fd_in,fd_out;
    int m=0,n=0;
    int check;
    int check1;
    int pid;
    char * string = "123456";
    char  string1[20];

    if(pipe(pip)!=0)
    {
        printf("pipe is error\n");
    }
    pid=fork();
    perror("fork error");
    if(pid==0)
    {
        printf("child pip[1] = %d\nchild pip[0] = %d\n",pip[1],pip[0]);
        close(pip[0]);
        check=write(pip[1],string,sizeof(string));
        perror("write pip[1]");
    }else{
        printf("parents pip[1] = %d\nparents pip[0] = %d\n",pip[1],pip[0]);
        close(pip[1]);
        wait(NULL);
        check1=read(pip[0],string1,sizeof(string));
        perror("read pip[0]");
        printf("%s\n",string1);
    }
}
