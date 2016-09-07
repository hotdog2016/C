#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>
#include<sys/wait.h>
#include<time.h>

int main(int argc,char * argv[])
{
    int pid1,pid2;
    clock_t start,finish;
    double m;
    start = clock();
    pid1 = fork();
    if(pid1 < 0){
        printf("fork error !\n");
        exit(1);
    }
    if(pid1 == 0){
        printf("argv[1] is :%s\nargv[0] is :%s\n",argv[1],argv[2]);
        if(execl("count","count",argv[1],(char *)0) < 0){
        printf("exec error!\n");
        exit(1);
        }
        exit(0);
    }else {
        wait(NULL);
        pid2 = fork();
        if(pid2 < 0){
        printf("pid2 is error!\n");
        exit(1);
    }
        if(pid2 == 0){
            if(execl("count","count",argv[2],(char *)0) < 0){
                printf("exec error!\n");
                exit(1);
            }   
        }else 
            wait(NULL);
    }
    finish = clock();
    m = (double)(finish - start)/CLOCKS_PER_SEC;
    printf("%lf seconds\n",m);
    exit(0);
}
