#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define __USE__DEBUG

#ifdef __USE__DEBUG 
#define DEBUG_P(m,n)                          \
    printf("In %s <%s> Line (%d):%s=%p\n",__FILE__,__func__,__LINE__,m,n)
#else 
#define DEBUG_P { } 
#endif

typedef struct NODE {

    int data;
    struct NODE *next;
}t_node,*p_node;

p_node head_node=NULL;
p_node reverse(p_node head)
{
    p_node first_node  = NULL;
    p_node current_first_node = NULL;

    first_node=head->next;
    while(first_node->next)
    {
        current_first_node = head->next;
        head->next = first_node->next;
        first_node->next = head->next->next;
        head->next->next=current_first_node;
    }
    return head; 
}

p_node creatOneNode(int m)
{
    p_node node;
    node = (p_node)malloc(sizeof(t_node));   
    node->data = m;
    node->next=NULL;
    return node; 
}
int  AddNode(p_node node)
{
    p_node current=NULL;
    p_node prev=NULL;
    if(head_node->next == NULL)
    {
        head_node->next = node;
        head_node->next->next = NULL;
        return 0;
    }
    current = head_node->next;
    while(current)
    {
        prev=current;
        current = current->next;
    }
    prev->next = node;
    prev->next->next = NULL;
    return 0;
}
int listlink(p_node head)
{
    p_node current=NULL;
    current = head->next;
    while(current)
    {
        printf("current = %p\n",current);
        printf("current->data = %d\n",current->data);
        current = current->next;
    }
    return 0;
}
int main()
{
    int m[4] = {1,2,3,4};
    int i;
    p_node test;
    head_node = (p_node)malloc(sizeof(t_node));   
    head_node->next = NULL;
    for(i=0;i<4;i++)
    {
        test=creatOneNode(m[i]);
        AddNode(test);
    }
    reverse(head_node); 
    listlink(head_node);
    return 0;
}
