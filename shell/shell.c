#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int child_processe( char *argv[]);
int main(int argc,char *argv[])
{
    int check_pid,i;
    char *arg[2];

    if(argc < 2){
        printf("arg is error\n");
        exit(0);
    }

    for(i = 0;i < 2;i++){
        arg[i] = argv[i+1];
        printf("arg[]=%s\n",arg[i]);
        
    }

    check_pid = fork();
    switch(check_pid){
        case -1 : perror("fork is error\n");exit(-1);
        case  0 : child_processe(argv);break;
        default : wait(NULL);break;
    }
}

int child_processe( char *argv[])
{
    printf("argv[0]=%s\n",argv[0]);
    printf("argv[1]=%s\n",argv[1]);
    printf("argv[2]=%s\n",argv[2]);


    if(execlp(argv[1],argv[2],(char * )0) < 0){
        perror("execlp\n");
        exit(-1);
    } 
    exit(0);
}
