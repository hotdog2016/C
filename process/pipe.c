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
    char * string = "123456";
    char  string1[20];

    fd_in=open("in",O_CREAT|O_RDWR,0777);
        perror("open in");
    fd_out=open("out",O_CREAT|O_RDWR,0777);
        perror("open out");

    printf("fd_in = %d\nfd_out = %d\n",fd_in,fd_out);

    if(pipe(pip)!=0)
    {
        printf("pipe is error\n");
    }

    printf("pip[1] = %d\npip[0] = %d\n",pip[1],pip[0]);

    m=dup2(pip[1],fd_in);
    close(pip[1]);

    n=dup2(pip[0],fd_out);
    close(pip[0]);

    printf("pip[1] = %d\npip[0] = %d\n",m,n);
    printf("pip[1] = %d\npip[0] = %d\n",pip[1],pip[0]);

    check=write(m,string,sizeof(string));
    perror("write pip[1]");
    if(check != sizeof(string))
    {
        printf("writ error\n");
        printf("%d\n",check);
    }
    check1=read(n,string1,sizeof(string));
    perror("read pip[0]");
    if(check1 != check)
        printf("error\n");
    printf("%s\n",string1);
}
