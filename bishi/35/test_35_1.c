#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/tree.h"
#include "../inc/queue.h"
#include "../inc/stack.h"
#include "../inc/list.h"

void creat_copy_node( struct list ** head)
{
	struct list *current = *head;
	struct list *new_node = NULL;

	while (current) {
		new_node = malloc( sizeof( struct list ) );
		memcpy( new_node , current , sizeof( struct list ));
		new_node->next = current->next;
		current->next = new_node;
		current = new_node;
		current = current->next;
	}
}
void modify_copy_node_silbing( struct list **head )
{
	struct list *current = *head;
	struct list *new_node = NULL;
	while(current) {
		if (NULL == current->sibling) {
			current = current->next->next; 
			continue;
		}
		current->next->sibling = current->sibling->next;
		current = current->next->next;
	}
}
struct list *separate( struct list **list )
{
	//p1 指向原始的链表头节点，p2指向复制的链表的头节点
	//调整p1 p2将原始链表和复制的链表分离
	struct list *head = *list;
	struct list *copy_head = (*list)->next;
	struct list *p1 = head;
	struct list *p2 = copy_head;
	while( 1 ) {
		p1->next = p2->next;
		p1 = p2->next;
		if (NULL == p1)
			break;
		p2->next = p1->next;
		p2 = p2->next;
	}
	return copy_head;
}
struct list *copy_list( struct list *list )
{
	creat_copy_node( &list );
	modify_copy_node_silbing( &list );
	return separate( &list );
}
int main(int argc, char *argv[])
{
	struct list *list = NULL;
	struct list *list_copy = NULL;
	int num[5] = {1,2,3,4,5};
	list = creat_list( num , 5 );
	printf("list %p \n",list);
	show_list( &list );
	list_copy = copy_list(list);
	printf("copy %p \n",list_copy);
	show_list( &list_copy );
	return 0;
}


