// 逆转链表   将头节点换成尾节点
#include <stdio.h>
#include "../inc/list.h"
#include <stdbool.h>
#include <stdlib.h>

struct list *creat_list_has_loop(int *num,int length)
{
    struct list* head = NULL;
    struct list* tmp = NULL;
	struct list* loop_start=NULL;
    head = malloc(sizeof(struct list));
    head->num = 0;
    head->next = NULL;

    for (int i = 0; i < length; ++i) {
	if (0 == i) {
	    head->num = num[i];
	    tmp = head;
	    continue;
	}

	tmp->next = malloc(sizeof(struct list));
	tmp->next->num = num[i];
	tmp->next->next = NULL;
	tmp = tmp->next;
	if (2 == i)
		loop_start = tmp;

    }
	if (NULL == loop_start)
		return NULL;
	tmp->next = loop_start;
    return head;
	
}

struct list *find_loop_in_list(struct list *head)
{
	bool has_loop = false;
	int loop_length=0;
	if ( NULL == head )
		return NULL;

	struct list *p1 = head;
	struct list *p2 = head;
	while ( NULL != p2 && NULL != p2->next) {
		p2 = p2->next->next;
		p1 = p1->next;
		if (false == has_loop) {
			if (p1==p2) {
				has_loop = true;
				break;
			}
		}
	}
	while (has_loop) { //存在环开始找环入口
	printf("456\n");
		p1 = p1->next;
		loop_length++;
		if (p1 == p2) {
			p1 = head;
			for (int i = 0; i < loop_length; ++i) {
				p2 = p2->next;
			}
			while (p1 != p2) {
				p1 = p1->next;
				p2 = p2->next;
			}
			return p1;
		}
	}
	return NULL;
}

int main()
{
	int num[6] = {1,2,3,4,5,6};
	struct list *loop_list = NULL;
	struct list *node = NULL;
	loop_list = creat_list_has_loop(num,6);
	if ( NULL == loop_list )
		return 1;
	node = find_loop_in_list(loop_list);
	if ( NULL == node )
		return 1;
	printf("start node is %d\n", node->num);

}


