#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<ctype.h>
#include<time.h>

int total();
int word_len = 0;
long start,end;
double cost_time;
int main(int argc,char * argv[])
{
    start = clock();

    perror("argv");
    char * string=argv[1];
    int i = 0;
    int chars = 0;

    printf("word is : %s\n",string);

    while(isalnum(string[i])){
        printf("%c\n",string[i]);
        i++;
    }
    word_len = i;
    total();
    end = clock();
    cost_time = (double)(end - start)/CLOCKS_PER_SEC;
    printf("cose time is : %lf\n",cost_time);
    exit(0);
}

int total()
{
    printf("word_len = %d\n",word_len);
    if(word_len > 7)
        printf("The word is too long\n");
    else if(word_len < 4)
        printf("word is too short\n");
    else 
        printf("lenth is normal\n");
    return 0;
}
