#include <stdio.h>
#include <stdlib.h>
#include "../inc/list.h"
#define LEN 5


int num[LEN] = { 1, 2, 3, 4, 5 };

struct list* creat_list(int* num)
{
    struct list* head = NULL;
    struct list* tmp = NULL;
    head = malloc(sizeof(struct list));
    head->num = 0;
    head->next = NULL;

    for (int i = 0; i < LEN; ++i) {
	if (0 == i) {
	    head->num = num[i];
	    tmp = head;
	    continue;
	}
	tmp->next = malloc(sizeof(struct list));
	tmp->next->num = num[i];
	tmp->next->next = NULL;
	tmp = tmp->next;
    }
    return head;
}

int show_list(struct list** head)
{
    struct list* node = NULL;
    if (NULL == *head)
	return 1;
    node = *head;
    while (NULL != node) {
	printf("%d ", node->num);
	node = node->next;
    }
    printf("\n");
    return 0;
}

struct list* find_node(struct list** head, int num)
{
    struct list* node = *head;
    while (NULL != node) {
	if (node->num == num)
	    return node;
	node = node->next;
    }
    return NULL;
}

int delete_node(struct list** head, struct list* node)
{
    struct list* tmp_node = node->next;
    if (node->next != NULL) {
	node->num = node->next->num;
	node->next = node->next->next;
	free(tmp_node);
    } else {
	struct list* pre_node = *head;
	while (node != pre_node->next) {
	    pre_node = pre_node->next;
	}
	pre_node->next = NULL;
	free(node);
    }
    return 0;
}


int main()
{
    struct list* list;
    struct list* del_node;
    list = creat_list(num);
    show_list(&list);
    del_node = find_node(&list, 4);
    delete_node(&list, del_node);
    show_list(&list);
}
