#include<stdio.h>
#include<pthread.h>
#include<ctype.h>
#include<fcntl.h>

int word_len;
long start,end;
double cost_time;
void *count(void *m);
void *total(void *m);

pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

int main(int argc,char *argv[])
{
    start = clock();
    if(argc<3){
        printf("error \n");
      return 0; 
    }
    
    pthread_t tid1,tid2,tid3;

    pthread_create(&tid1,NULL,count,argv[1]);
    pthread_create(&tid2,NULL,count,argv[2]);
    pthread_join(tid1,NULL);
    pthread_join(tid2,NULL);
    end = clock();
    cost_time = (double)(end - start)/CLOCKS_PER_SEC;
    printf("cose time is : %lf\n",cost_time);
}

void *count(void *m)
{
    char * string=m;
    int i = 0;
    int chars = 0;
    pthread_mutex_lock(&lock);
    printf("This is the thread1 : %s\n",string);

    while(isalnum(string[i])){
        printf("%c\n",string[i]);
        i++;
    }
    word_len = i;
    pthread_mutex_unlock(&lock);
    total(NULL);
    pthread_exit(NULL);
}

void *total(void *m)
{
    printf("word_len = %d\n",word_len);
    if(word_len > 7)
        printf("The word is too long\n");
    else if(word_len < 4)
        printf("word is too short\n");
    else 
        printf("lenth is normal\n");
}
