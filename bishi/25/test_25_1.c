#include <stdio.h>
#include <string.h>
#include "../inc/list.h"

struct list *smaller(struct list *head1,struct list *head2)
{
	struct list *node = NULL;
	if (NULL == head1) {
		return head2;
	}

	if ( NULL == head2 )
		return head1;

	if (head1->num < head2->num) {
		node = head1;
		node->next = smaller(head1->next,head2);
	}
	if (head2->num < head1->num) {
		node = head2;
		node->next = smaller(head1,head2->next);
	}
	return node;
}

struct list *combine_list1_list2( struct list *head1,struct list *head2)
{
	if (NULL == head1 || NULL == head2) {
		return NULL;
	}
	return smaller(head1,head2);
}

int main(int argc, char *argv[])
{
	int num1[3] = {1,3,5};
	int num2[3] = {2,4,6};

	struct list *list1 = NULL;
	struct list *list2 = NULL;
	struct list *combine_list = NULL;

	list1 = creat_list(num1 , 3);
	list2 = creat_list(num2 , 3);


	if ( NULL == list1 || NULL == list2)
		return 1;
	show_list(&list1);
	show_list(&list2);

	combine_list =  combine_list1_list2(list1 , list2);

	show_list(&combine_list);

	return 0;
}


