#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

char *env_init[] = {"USER=unknow","PATH=/tmp",NULL};
char *argv_init[] = {"test","123"};

int main()
{
    pid_t m,n;
    int mypid;
    m = fork();
    printf("fork return %d\n",m);
    n=waitpid(m,NULL,0);
    if(m == 0)
    {
        printf("ok!\n");
        if(execvp("/home/hotdog/c/c_work/process/test",argv_init)<0)
            printf("exec error!\n");
    }else{

        printf("n= %d\n",n);
        mypid = getpid();
        printf("P-pid is %d\n",mypid);
    }
    printf("process will exit\n");
    exit(0) ;
}

