extern "C"{
#include "../inc/list.h"
}

#include <iostream>
#include <memory>
#include <string>
#include <iterator>


using std::cout;
using std::cin;
using std::string;
using std::endl;



struct list *find_first_common_node(struct list *list1,struct list *list2)
{
  int list1_cnts = 0;
  int list2_cnts = 0;
  struct list *current = list1;
  while (current != nullptr) {
    list1_cnts++;
    current = current->next;
  }
  current = list2;
  while (current != nullptr) {
    list2_cnts++;
    current = current->next;
  }
  if (list1_cnts > list2_cnts) {
    struct list *list1_head = list1;
    struct list *list2_head = list2;
    for (int i = 0; i < list1_cnts - list2_cnts; i++) {
      list1_head = list1_head->next;
    }
    for (int i = 0; i < list2_cnts; i++) {
      if (list1_head->num == list2_head->num) {
        return list1_head;
      }
      list1_head = list1_head->next;
      list2_head = list2_head->next;
    }
  } else {
    struct list *list1_head = list1;
    struct list *list2_head = list2;
    for (int i = 0; i < list2_cnts - list1_cnts; i++) {
      list2_head = list2_head->next;
    }
    for (int i = 0; i < list1_cnts; i++) {
      if (list1_head->num == list2_head->num) {
        return list1_head;
      }
      list1_head = list1_head->next;
      list2_head = list2_head->next;
    }
  }

  return 0;
}

void combine_list(struct list *list1,struct list *list2,struct list *list3)
{
  struct list *current = list1;

  while (current->next != nullptr) {
    current = current->next;
  }

  current->next = list3;
  current = list2;

  while (current->next != nullptr) {
    current = current->next;
  }

  current->next = list3;

}

int main()
{
  const int len1 = 3;
  const int len2 = 4;
  const int len3 = 3;

  int num1[len1] = {1,2,3};
  int num2[len2] = {4,5,6,7};
  int num3[len3] = {8,9,10};

  struct list *list1 = creat_list(num1,len1);
  struct list *list2 = creat_list(num2,len2);
  struct list *list3 = creat_list(num3,len3);
  struct list *return_list = NULL;
  combine_list(list1,list2,list3);

  show_list(&list1);
  show_list(&list2);

  return_list=find_first_common_node(list1,list2);
  cout<<"the fist commod node is " <<return_list->num<<endl;

  return 0;
}

