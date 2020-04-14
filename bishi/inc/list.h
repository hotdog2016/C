#ifndef LIST_H
#define LIST_H

struct list {
    int num;
    struct list* next;

	struct list* sibling;
};

struct list* creat_list(int* num , int length);
int show_list(struct list** head);

struct list* find_node(struct list** head, int num);
int delete_node(struct list** head, struct list* node);

#endif /* end of include guard: LIST_H */
