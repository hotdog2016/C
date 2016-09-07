#include<stdio.h>
#include<stdlib.h>
#include<curses.h>
int main()
{
    char ch;
    initscr();
    ch = getch();
    switch(ch){
        case 'q':printf("hello\n");break;
    }
    return 0;
}

