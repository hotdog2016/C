/*寻找两个节点的最公共祖先*/
extern "C"{
#include "../inc/list.h"
#include "../inc/tree.h"
}

#include <iostream>

#include <memory>
#include <string>

#include <iterator>
#include <vector>
#include <list>

using namespace std;

/*找到包含节点node的路径
 * 每当往下遍历一个节点，就将此节点放入链表中，节点下面
 * 如果没有要寻找的节点那就将这个节点从链表删除。最后就
 * 会形成一条可以到node的一条路径。
 * 其中，found是代表在有没有找到节点，如果found为false
 * 那么就将当前的节点删除。如果为true那就说明找到了这个
 * 节点，那就一路返回，不再往下遍历。*/
bool find_path(
    struct tree *root,
    char node,
    std::list<struct tree *> &path)
{
  bool found = false;

  if (nullptr == root) {
    return false;
  }
  if (root->data == node) {
    return true;
  }

  path.push_back(root->lchild);
  found = find_path(
      root->lchild,
      node,
      path);
  if (!found) {
    //如果没有找到那就将当前的root弹出链表，继续往下遍历
    path.pop_back();
  } else {
    //如果找到了，就网上返回，不再继续遍历后面的节点了。
    return true;
  }

  path.push_back(root->rchild);
  found = find_path(
      root->rchild,
      node,
      path);
  if (!found) {
    path.pop_back();
  } else {
    return true;
  }

  return false;
}
/* 找到两条路径的最后一个公共节点，此节点就是这两个节点的最低
*  公共祖先。
*/
struct tree *find_last_common_node(
    std::list<struct tree *> path1,
    std::list<struct tree *> path2)
{
  auto iter1 = path1.begin();
  auto iter2 = path2.begin();
  struct tree *last_public_node = nullptr;
  //找最后一个公共节点
  while (iter1 != path1.end() 
      && iter2 != path2.end()) {
    if ((*iter1)->data == (*iter2)->data) {
      last_public_node = *iter1;
    }
    ++iter1;
    ++iter2;
  }

  return last_public_node;
}

struct tree *find_public_parent(
    struct tree *root,
    char node1,
    char node2)
{
  /*新建两个链表用来存放到某个节点的路径*/
  std::list<struct tree *> path1;
  std::list<struct tree *> path2;
  path1.push_back(root);
  path2.push_back(root);
  find_path(root,node1,path1);
  find_path(root,node2,path2);
  return find_last_common_node(path1,path2);
}
int main()
{
  string str_cc("532##4##76##8##");

  const char *str = str_cc.c_str();

  struct tree *tree = nullptr;
  struct tree *parent_node = nullptr;

  creat_tree(&tree,&str);
  parent_node = find_public_parent(tree,'3','8');
  if (nullptr != parent_node) {
    cout<<"lowestparent is "<<parent_node->data<<endl;
    return 0;
  }
  cout<<"can't find"<<endl;
}


