#include <stdio.h>
#include <stdlib.h>
int main(int argc,char * argv[])
{
    int i,mypid;
    char **ptr;
    extern char **environ;

    for(i=0;i<argc;i++) 
        printf("argv[%d] : %s\n",i,argv[i]);
//    for(ptr = environ;*ptr != 0;ptr++) 
//        printf("%s\n",*ptr);

    printf("This is sub-process\n");
    mypid = getpid();
    printf("sub-pid is %d\n",mypid);
    printf("child process exit\n");
    exit(0);
}
