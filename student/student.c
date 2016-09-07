#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include "link.h"
#include <errno.h>
#include <termios.h>
#include <assert.h>

int fb;

int main(void)
{
	int ch;
    List * class=NULL;
	class = alloc_list();

	while(1)
	{
		switchUI(class);
        while(1)
        {
     		printf("Press [Q]uit | [R]eturn : ");
            ttymode(0);
            changetty();
            ch = getchar();
            ch = tolower(ch); 
            ttymode(1);
    		printf("\n");
    
    		if(ch=='q')
    			exit(0);
    		else if(ch=='r')
    			break;
    		else
                continue;
        }
	}
	return 0;
}

int switchUI(List * class)
{
	int ch;
	printf("                         \n");
	printf("*************************\n");
	printf("                         \n");
	printf("[1]添加用户 | [2]查找用户\n");
	printf("[3]删除用户 | [4]退出    \n");
	printf("                         \n");
	printf("*************************\n");
	printf("                         \n");
	printf("Please chose : ");

    ttymode(0);
    changetty();
    ch=getchar();
    ttymode(1);

    printf("\n");

	switch (ch){
                     /*Add a student*/
		case '1':   openfile(ch);
			        add_student(class);
			        break;

                    /*Search a student*/
		case '2':   openfile(ch);
                    importfile(class);
			        search_student(class);
			        break;

                    /*Delet a student*/
		case '3':   openfile(ch);
                    importfile(class);
                    delete_student(class);
			        break;

                    /*Quit*/
		case '4':   exit(0);

		default :   printf("Your choice is error\n");
                    break;

	}
		return 0;
}

int add_student(List * class)
{
    int check;
    struct Node * Student=NULL;
    char string[MAX] = {' '};

	Student = alloc_node();

	fputs("Name:",stdout);
	fgets(string,sizeof(string),stdin);
	strcpy(Student->message.name , string);		
	memset(string,' ',sizeof(string));

	fputs("Sex:",stdout);
	fgets(string,sizeof(string),stdin);
	strcpy(Student->message.sex  , string);		
	memset(string,' ',sizeof(string));

	fputs("Age:",stdout);
	scanf("%d",&Student->message.age);
	while((getchar() != '\n')&&getchar() != EOF);

	printf("Student ID:");
	fgets(string,sizeof(string),stdin);
	strcpy(Student->message.id , string);
	memset(string,' ',sizeof(string));

	add_node_to_list(class,Student);
    free(Student);

	check = write(fb,&Student->message,STU_SIZE);
    assert(check == STU_SIZE);

	close(fb);
	return 0;
}

int search_student(List * class)
{
	struct Node * node = NULL;
    char string[MAX];

	printf("Search ID:");
	fgets(string,sizeof(string),stdin);
	node=search_node(class,string);

	if(!node)
	{
		printf("ID invalid!\n");
		return -1;
	}

	showinfo(node);
    close(fb);
	return 0;
}

int showinfo(struct Node * node)
{

	fputs("Name             :",stdout);
	fputs( node->message.name ,stdout);

	fputs("Sex              :",stdout);
	fputs( node->message.sex ,stdout);

	printf("Age              :%d\n",node->message.age);

	fputs("Student ID       :",stdout);
	fputs( node->message.id,stdout);

	return 0;
}
    
int delete_student(List * class)
{
	int check = 0;
	struct Node *node = NULL;
	char id = ' ';
    char string[MAX] = {' '};

	printf("Student ID:");
	fgets(&id,sizeof(string),stdin);
	node = search_node(class,&id);

	if(!node){
		printf("ID invalid!\n");
		return -1;
	}

	check = del_node(class,node);
	if(!check){

        fb = open("MessageFile",O_RDWR|O_TRUNC);
        close(fb);
        updatefile(class);
        printf("Remove success!\n");
		return 0;

	}else 
		return -1;

	return 0;
}

int copy_student(struct Student * goal,struct Student * source)
{
	strcpy(goal->name,source->name);
	strcpy(goal->sex,source->sex);
	strcpy(goal->id,source->id);
	goal->age = source->age;
	return 0;	
}
int openfile(int flag)
{
	switch(flag)
	{
		case '1': fb = open("MessageFile",O_RDWR|O_CREAT|O_APPEND,0744);
				break;

		case '2': fb = open("MessageFile",O_RDWR);
                lseek(fb,0,SEEK_SET);
				break;

		case '3': fb = open("MessageFile",O_RDWR);
                lseek(fb,0,SEEK_SET);
				break;

		default : break;

	}
	if(fb <0){
		printf("Can't open!\n");
		exit(1);
	}
	return 0;
}

int importfile(List * class)
{
    struct Node * node=NULL;
    List *list = NULL;
    struct Student * student=NULL;
    int stu=0,readsize=0,count=0,m;
	char buffer[STU_SIZE * MAX];

    list = alloc_list();

	readsize = read(fb,buffer,MAX * STU_SIZE);
    assert(readsize > 0);
    stu = readsize/STU_SIZE;

    while(count < stu){

        node = alloc_node();
        student = (struct Student *)&buffer[count*STU_SIZE];
        copy_student(&node->message,student);
        add_node_to_list(list , node);
        count++; 
    }

    *class = *list;
	traversal_list(list);
    close(fb);
	return 0;
}

int updatefile(List * class)
{
    struct Node * node = NULL;
    struct Student * student = NULL;
	char buffer[STU_SIZE * MAX]; 
    int count=0 ,check;

    fb = open("MessageFile",O_WRONLY);

    if(fb < 0)
        printf("Can't open\n");

    node = *class;

    while(node != NULL){

        student = (struct Student *)&buffer[count*STU_SIZE];
        copy_student(student,&node->message); 
        node = node->next;
        count++;

    }

    check = write(fb,buffer,count*STU_SIZE);
    assert(check != STU_SIZE);
    close(fb);

    return count;
}

int changetty()
{
    struct termios temp;
    tcgetattr(0,&temp);
    temp.c_lflag &= ~ICANON;
    temp.c_cc[VMIN] = 1;
    tcsetattr(0,TCSANOW,&temp);
}

int ttymode(int now)
{
    static struct termios original_mode;
    if(now == 0)
        tcgetattr(0,&original_mode);
    else 
        return tcsetattr(0,TCSANOW,&original_mode);
}
