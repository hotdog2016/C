#include<sys/socket.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<netdb.h>
#include<arpa/inet.h>
#include<string.h>

#define         SERVER_PORT    2048     
#define         HOSTLINE       256 

int main(int argc,char * argv[])
{
    int socket_id,client_socket_id;
    int err,n;
    struct addrinfo addrinfo_init;
    struct addrinfo *api,*addrinfolist;
    char buf[20];
    char  * hostname;
    const char * addr;
    int addrlen;
    struct sockaddr_in *my_addr;
    struct sockaddr client_addr;
    const char message[20] = "hello world!"; 
    n = sysconf(_SC_HOST_NAME_MAX); 
    printf("n = %d\n",n);
    hostname = malloc(n);
    gethostname(hostname,n);
    memset(&addrinfo_init,0,sizeof(addrinfo_init));
    printf("n = %d\n",n);
    addrinfo_init.ai_flags = AI_CANONNAME;
    addrinfo_init.ai_socktype = SOCK_STREAM;		
    addrinfo_init.ai_addr = NULL;
    addrinfo_init.ai_canonname = NULL;
    addrinfo_init.ai_next = NULL;
   
    if((err = getaddrinfo(hostname,"ruptime",&addrinfo_init,&addrinfolist)) != 0)
        perror("getaddrinfo");
    printf("ok\n");
    for(api=addrinfolist;NULL != api;api=api->ai_next){
        printf("hello\n");
        
        if(socket_id = socket(api->ai_family,api->ai_flags,0) < 0 )
           perror("socket id");

        if(bind(socket_id,(struct sockaddr *)&api->ai_addr,api->ai_addrlen) < 0)
           perror("bind");

        if(listen(socket_id,3) !=0)
            perror("listen");

        client_socket_id=accept(socket_id,&client_addr,&addrlen); 
        printf("%d\n",client_socket_id);

        if(send(client_socket_id,message,sizeof(message),0) <0)
           perror("send");
    }
}
