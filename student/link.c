#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "link.h"

/*遍历链表并返回表中有效节点的个数，以及节点内的信息
 * */
int traversal_list(List * const list)
{
	struct Node *current=NULL;
	int i=0;
	if(!list ||!(*list) )
		return -1;
	current = (*list)->head;
	while(current)
	{
	current=current->next;
		i++;
	}
	return i;
	
}
/*
 *添加一个节点到链表中，添加成功返回0,否则返回相应的错误值
 *
 * */
int add_node_to_list(List * const list,struct Node *node)
{
	struct Node *current;
	struct Node *prev;
	if(!list)
		return -1;

	if((*list)== NULL)
	{
		(*list) = node;
		node->head = (*list);
		node->front = NULL;
		node->next = NULL;
		return 0;
	}

	current = (*list);
	while(current)
	{
		prev=current;
		current=current->next;
	}

	prev->next = node;
	node->front = prev;
	node->next = NULL;
	node->head = (*list);

	return 0;
}

/*
 *从指定链表中删除节点，成功则返回0,否则返回相应错误值。
 * */

int del_node(List * const list,struct Node *node)
{
	struct Node *current=NULL;
	struct Node *prev=NULL;
	struct Node *head=NULL;

	if((!*list)||(!node))
        return -1;

	if((node->front == NULL)&&(node->next == NULL))
	{	
        // Just one node
        FREE(node);
		(*list) = NULL;
		return 0;
	}else if(!node->front){

		current = node->next; 
		(*list) = node->next;	
		(*list)->front = NULL;
		while(current)	{
        // Head node
			current -> head = (*list);	
			current  = current->next;
		}
        FREE(node);
		return 0;
	}else if(!node->next){
        // End node
		node->front->next = NULL;
        FREE(node);
		return 0;
	}else{
        // Nomal node
		node->front->next = node->next;
		node->next->front = node->front;
        FREE(node);
		return 0;
	}
}
/*
 * 从指定链表中搜寻一个节点,成功则返回相应节点的地址，否则返回NULL。
 * */
struct Node * search_node(List * const list,char *temp)
{
	
	struct Node *current=NULL;
	char num[20];

	if(!(*list))
		return NULL;

	current = (*list);

	while(current)
	{
		strcpy(num,temp);
		if(current!=NULL)
		{
			if(strcmp(current->message.id,num)==0)
                return current;
			else{
                current = current->next;
		    	memset(num,' ',sizeof(num));	
            }
		}else 
            return NULL;
	}
	return NULL;
}
/*
 * 分配一个空间给链表，成功返回空间首地址，否则返回NULL。
 * */
List *alloc_list()
{
	List * list;
	list = (List *)malloc(sizeof(List *));

	(*list) = NULL;

	if(list)
		return list;
	else
		return NULL;
}

 /* 分配一个空间给节点，成功返回地址，否则返回NULL。*/

struct Node *alloc_node()
{
	struct Node * node;
	node = (struct Node*)malloc(sizeof(struct Node ));
	if(node)
	{
		node->head;
		node->next=NULL;
		node->front=NULL;
		return node;

	}else 
        return NULL;
}

