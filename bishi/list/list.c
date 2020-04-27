#include <stdio.h>
#include <stdlib.h>
#include "../inc/list.h"

struct list* creat_list(int* num ,int length)
{
    struct list* head = NULL;
    struct list* current = NULL;
	struct list* new_node = NULL;

    head = malloc(sizeof(struct list));
    head->num = 0;
    head->next = NULL;

    for (int i = 0; i < length; ++i) {
	  if (0 == i) {
	      head->num = num[i];
	      current = head;
	      continue;
	  }

	new_node = malloc(sizeof(struct list));
	new_node->num = num[i];
	new_node->next = NULL;
	new_node->sibling = NULL;
	current->next = new_node;
	current = new_node;

    }

	current = head;

	while ( current ) {
		switch (current->num) {
			case 2:
				current->sibling = find_node( &head , 4 );
				break;
			case 3:
				current->sibling = find_node( &head , 5 );
				break;
			case 4:
				current->sibling = find_node( &head , 2 );
				break;
			case 5:
				current->sibling = find_node( &head , 1 );
				break;
			default:break;
		}
		current = current->next;
	}
    return head;
}

int show_list(struct list** head)
{
    struct list* current = NULL;
    if (NULL == *head)
	return 1;
    current = *head;
    while (NULL != current) {
		printf("now = %d \n", current->num);
		if ( NULL == current->sibling ) {
			current = current->next;
			continue;
		}
		current = current->next;
	}
    printf("\n");
    return 0;
}

struct list* find_node(struct list** head, int num)
{
    struct list* current = *head;
    while (NULL != current) {
	if (current->num == num)
	    return current;
	current = current->next;
    }
    return NULL;
}

int delete_node(struct list** head, struct list* node)
{
    struct list* current = node->next;
    if (node->next != NULL) {
	node->num = node->next->num;
	node->next = node->next->next;
	free(current);
    } else {
	current = *head;
	while (node != current->next) {
	    current = current->next;
	}
	current->next = NULL;
	free(node);
    }
    return 0;
}
