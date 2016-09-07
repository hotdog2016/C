#include<sys/socket.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<netdb.h>
#include<arpa/inet.h>
#include<string.h>

#define         SERVER_PORT    2048     
#define         HOSTLINE       100

int main(int argc,char * argv[])
{
    int socket_id,client_socket_id;
    int err;
    struct sockaddr_in my_addr;
    struct sockaddr client_addr;
    char * hostname;
    int add_len;
    socket_id = socket(AF_INET, SOCK_STREAM,0);
    memset(&my_addr,0,sizeof(struct sockaddr_in));

    my_addr.sin_family = AF_INET;
//    my_addr.sin_port = htons(SERVER_PORT);
    my_addr.sin_addr.s_addr = inet_addr("192.168.1.102");

    err = bind(socket_id,(struct sockaddr *)&my_addr,sizeof(struct sockaddr));
    if(err != 0)
        perror("bind");
    err = listen(socket_id,3);
    if(err != 0)
        perror("listen");
    client_socket_id=accept(socket_id,&client_addr,&add_len);
    if(client_socket_id < 0)
        perror("accept");
    server(client_socket_id);
}

int server(int socket_id)
{
    int check;
    char test[20] = "hello";
    check = send(socket_id,test,sizeof(test),0);
    printf("send ok!\nwrite %d\n",check);
} 
