#include <stdio.h>
#include <stdlib.h>
#include <curses.h>
#include <signal.h>
#include <sys/time.h>

void window();
void set_speed(int );
void alm_handle();
int flag; 
char c;

int main()
{
    char c = ' ';
    signal(SIGALRM,alm_handle);
    set_interval(100);
    while(1){
        c = getch();
        switch(c){
        case 'q':endwin();exit(0);
        case 'j':flag = 0;break;
        case 'k':flag = 1;break;
        default :break;
        }
        endwin();
        clear();
    }
}

void window()
{
    int i=0,j=0;

    initscr();
    refresh();

    for(i=11;i < 179 ;i++)
    {
        move(6,i);
        addch('_');
        refresh();
        move(39,i);
        addch('_');
        refresh();

    }
   
    for(j=7;j < 40 ;j++)
    {
        move(j,10);
        addch('|');
        refresh();
        move(j,179);
        addch('|');
        refresh();

    }
    
}

void set_speed(int ms)
{
    static int m= 0;
    ms *= 1000;

    if(m-20>0 )
    {
        m=0;
       flag = 1; 
    }
    else if(m+20 <0 )
    {
        m=0;
        flag = 0;
    }
    else flag=0;
    if(flag == 0)
    {
        move(24,56+m);
        addch(' ');
 //       refresh();
        m -= 2 ;
//        usleep(ms);
        move(24,56+m);
        addch('0');
        refresh();
    }

    if(flag == 1)
    {
        move(24,56+m);
        addch(' ');
//        refresh();
        //usleep(ms);
        m += 2 ;
        move(24,56+m);
        addch('0');
        refresh();
    }
}

void alm_handle()
{
    signal(SIGALRM,SIG_DFL);
    window();
    set_speed(500);
    signal(SIGALRM,alm_handle);
}

int set_interval(int interval_value)
{
    struct itimerval new_time;
    int micsec,sec;

    sec = interval_value / 1000;
    micsec = interval_value % 1000 * 1000;

    new_time.it_interval.tv_sec = sec;
    new_time.it_interval.tv_usec = micsec;

    new_time.it_value.tv_sec = sec;
    new_time.it_value.tv_usec = micsec;
    
    return setitimer(ITIMER_REAL,&new_time,NULL);
}
