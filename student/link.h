#ifndef _LINK_H
#define _LINK_H

#define MAX			   50 
#define STU_SIZE			(sizeof(struct Student))
#define           FREE(node)              do\
                                            {  \
                                                free(node); \
                                                node = NULL;\
                                            }while(0);
struct Student{
	char name[MAX];
	char id[MAX];
	char sex[MAX];
    int age;
};
struct Node {
	struct Student message;
 	struct Node *head ;
	struct Node *front; 
	struct Node *next ;
};

typedef struct Node * List;

int switchUI(List * );
int add_student(List * );
int search_student(List * );
int message(struct Node *);
int delete_student(List *);
int copy_student(struct Student *,struct Student *);
int openfile(int );
int importfile(List *);
int updatefile(List *);
int tty_mode(int now);
int change_termios();

struct Node * search_node(List * const list,char *temp);
List *alloc_list();
struct Node *alloc_node();
int init_list(List * const list);
int traversal_list(List *const list);
int add_node_to_list(List *const list,struct Node *node);
int del_node(List *const list,struct Node *node);

#endif
