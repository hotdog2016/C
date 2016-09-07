#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include "apue.h"

static void chartime(char *);
int main()
{
   pid_t pid;
   pid=fork();
   if(pid==0)
   {
        chartime("output from child\n"); 
   }else{
        waitpid(pid,NULL,0);
        chartime("output from parent\n"); 
   }
   exit(0);
}
static void chartime(char * str)
{
    char *ptr;
    int c;
    setbuf(stdout,NULL);
    for(ptr = str;(c=*ptr++)!=0;)
        putc(c,stdout);
}
