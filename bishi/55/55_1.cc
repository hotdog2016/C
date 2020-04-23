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
  string str_cc("5321##4##76##8##");

  const char *str = str_cc.c_str();
  int deep = 0;

  struct tree *tree = nullptr;

  creat_tree(&tree,&str);
  deep = deep_of_tree(tree);
  cout<<"deep is "<<deep<<endl;
}

