#ifndef TREE_H
#define TREE_H

struct tree{
	char data;
	struct tree *lchild;
	struct tree *rchild;
};

typedef char  String[100];
int StrAssign(String T,char *chars);
void creat_tree(struct tree **T,const char **str);
void pre_order_traverse(struct tree * T);
void middle_order_traverse(struct tree *T);
void end_Order_traverse(struct tree *T);
void test_tree(struct tree *);

#endif
