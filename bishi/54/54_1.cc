extern "C"{
#include "../inc/list.h"
#include "../inc/tree.h"
}

#include <iostream>
#include <memory>
#include <string>
#include <iterator>
#include <vector>

using namespace std;


void mymiddle_order_traverse(struct tree  *T , vector<struct tree*>& num_seq)
{ 
  if(T==NULL)
	return;
  mymiddle_order_traverse(T->lchild,num_seq);
  num_seq.push_back(T);
  mymiddle_order_traverse(T->rchild,num_seq);
}

struct tree * find_Kth_largest_node(struct tree *root,int k)
{
  vector<struct tree *> num_seq;
  mymiddle_order_traverse(root,num_seq);

  return *(num_seq.end()-k);
}

int main()
{
  string str_cc("532##4##76##8##");
  const char *str = str_cc.c_str();
  int k = 1;

  struct tree *tree = nullptr;
  struct tree *node = nullptr;

  creat_tree(&tree,&str);

  node = find_Kth_largest_node(tree,k);

  cout<<"the "<<k<<"th"<<"largest node is "<<node->data<<endl;

  return 0;
}

