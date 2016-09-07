#include <stdio.h>
#include <stdlib.h>
#include <curses.h>
#include <signal.h>
#include <sys/time.h>

void sig_handle()
{    
    static int i=0;
    initscr();
    move(20,50+i);
    addch('o');
    refresh();
//    usleep(500000);
//    move(20,50+i);
//    addch(' ');
//    refresh();
    i++;
}

int main()
{
    char ch;
    signal(SIGALRM,sig_handle);
    set_interval(2000);
    while(1){
        ch=getch();
        switch(ch){
            case 'q':endwin();exit(0);break;
        }
    }
}
    
int set_interval(int interval_value)
{
    struct itimerval new_time;
    int micsec,sec;
    sec = interval_value / 1000;
    micsec = interval_value % 1000;
    new_time.it_interval.tv_sec = sec;
    new_time.it_interval.tv_usec = micsec;

    new_time.it_value.tv_sec = sec;
    new_time.it_value.tv_usec = micsec;
    
    return setitimer(ITIMER_REAL,&new_time,NULL);
}
//11111111111111
