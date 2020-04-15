#include <stdio.h>
#include <stdlib.h>
#include "../inc/list.h"

// 链表中倒数第k个点

struct list *list_but_k(struct list *head, int k)
{
	if ( NULL == head )
		return NULL;

	struct list *p1 = head;
	struct list *p2 = head;

	for (int i = 0; i < k-1; ++i) {
		if ( NULL == p2->next ) 
			return NULL;
		p2 = p2->next;
	}

	while (p2) {
		p2 = p2->next;
		p1 = p1->next;
	}

	return p1;
}

int main()
{
	struct list *list = NULL;
	struct list *node = NULL;
	int num[9] = {1,2,3,4,5,6,7,8,9};
	int k = 6;

	list = creat_list(num,9);

	if (NULL == list) {
		printf("creat list error\n");
		return 1;
	}

	show_list(&list);
	node = list_but_k(list , k);
	if (NULL == node)
		
	printf("The last but %d is %d\n",k,node->num);

	return 0;

}




