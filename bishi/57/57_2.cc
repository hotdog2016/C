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

bool is_balance_tree(struct tree *root , int& deepth)
{
  if (nullptr == root) {
    return true;
  }
  int left_deep =0;
  int right_deep=0;
  if (is_balance_tree(root->lchild,left_deep) && 
      is_balance_tree(root->rchild,right_deep)) {
    int diff = left_deep - right_deep;
    if (diff <= 1 && diff >= -1) {
      deepth = 1 + (left_deep > right_deep ? left_deep:right_deep);
      return true;
    }
  }
  return false;
}
int deep_of_tree(struct tree *root)
{
  int left_deep = 0;
  int right_deep = 0;
  if (nullptr == root) {
    return 0;
  }

  left_deep = deep_of_tree(root->lchild);
  right_deep = deep_of_tree(root->rchild);

  return left_deep > right_deep ? left_deep+1 : right_deep+1;
}

int main()
{
  string str_cc("124##5#7##3#6##");

  const char *str = str_cc.c_str();
  int deep = 0;
  bool is_balance = false;

  struct tree *tree = nullptr;

  creat_tree(&tree,&str);
  deep = deep_of_tree(tree);

  is_balance  = is_balance_tree(tree,deep);

  if (is_balance) {
    cout<<"is balance tree and deepth is "<<deep<<endl;
  } else {

    cout<<"!!! isn't balance tree deep is "<<deep<<endl;
  }
  
}

