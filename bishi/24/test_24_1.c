// 逆转链表   将头节点换成尾节点
#include <stdio.h>
#include "../inc/list.h"
int reversion_list(struct list **head)
{

	struct list *pre_node = NULL;
	struct list *node = NULL;
	struct list *next_node = NULL;
	if ( NULL == *head )
		return 1;

	pre_node = *head;	

	if (NULL == pre_node->next)
		return 0;

	node = pre_node->next;

	if (NULL == node->next) {
		node->next = pre_node;
		pre_node->next = NULL;
		*head = node;
		return 0;
	}

	next_node = node->next;	
	while (next_node) {
		if (*head == pre_node) {
			pre_node->next = NULL;
			node->next = pre_node;

			if (NULL == next_node->next) {
				next_node->next = node;
				*head = next_node;
				break;
			}

			pre_node = node;
			node = next_node;
			next_node = next_node->next;

			continue;
		}
			node->next = pre_node;

			if (NULL == next_node->next) {
				*head = next_node;
				next_node->next = node;
				break;
			}

			pre_node = node;
			node = next_node;
			next_node = next_node->next;
	}
	return 0;
}
int main()
{
	int num[3] = {1,2,3};
	struct list *list = NULL;
	list = creat_list(num,3);
	if (NULL == list) {
		printf("creat list error!\n");
		return 1;
	}
	show_list(&list);
	reversion_list(&list);
	show_list(&list);
	return 0;
}
