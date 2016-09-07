#include<stdio.h>
#include<sys/shm.h>
#include<time.h>
#include<stdlib.h>
#include<string.h>

#define  SEM_FLAG      100
#define  SEM_SIZE      100

int main()
{
    int sig_id;
    char * ptr;
    sig_id = shmget(SEM_FLAG,SEM_SIZE,IPC_CREAT|0777);
    if(sig_id < 0){
        printf("shm is error!\n");
        exit(1);
    }
    ptr = shmat(sig_id,NULL,0);
    printf("%s\n",ptr);
    shmdt(ptr);
    return 0;
}
