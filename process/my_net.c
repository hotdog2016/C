#include<netinet/in.h>
#include<netdb.h>
#include<time.h>
#include<strings.h>
#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/types.h>

#define     PORTNUM     13000
#define     HOSTLEN     256

int main()
{
    struct sockaddr_in saddr;
    struct hostent *hp;

    char hostname[HOSTLEN];
    int sock_id,sock_fd;
    FILE * sock_fp;
    time_t thetime;
    char * ctime();

    sock_id = socket(PF_INET,SOCK_STREAM,0);
        if(sock_id == -1)
            printf("socket error\n");

    bzero((void *)&saddr,sizeof(saddr));

    gethostname(hostname,HOSTLEN);

    hp = gethostbyname(hostname);

    bcopy((void *)hp->h_addr,(void *)&saddr.sin_addr,hp->h_length);
    saddr.sin_port = htons(PORTNUM);
    saddr.sin_family = AF_INET;
    
    if(bind(sock_id,(struct sockaddr *)&saddr,sizeof(saddr))!=0)
        perror(" bind error!\n");
    if(listen(sock_id,1)!=0)
        printf("listen");
    while(1){
    
        sock_fd = accept(sock_id,NULL,NULL);
        printf("wow y");
        if(sock_fd == -1)
            printf("hah");
        sock_fp = fdopen(sock_fd,"w");
        if(sock_fp == NULL)
            printf("fp error\n");
        thetime = time(NULL);
        fprintf(sock_fp,"The time here is ..");
        fprintf(sock_fp,"%s",ctime(&thetime));
        fclose(sock_fp);

    }
}
