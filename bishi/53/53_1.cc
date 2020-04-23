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

int *find_numbers_first_apperance(int num,int num_array[],int *start,int *end)
{
  if (start == end) {
    if (*start == num) {
      return start;
    } else {
      return nullptr;
    }
  }
  int *first_apperance = nullptr;
  int *mid =  start+(end - start)/2;
  if (*mid > num)
  { //在左半边
    find_numbers_first_apperance(num,num_array,start,mid);
  } else if (*mid < num) {//在右半边
    find_numbers_first_apperance(num,num_array,mid+1,end);
  } else {
    if (mid != start) {
      //找该数字第一次出现的位置
      if (*(mid-1) == num) {
        find_numbers_first_apperance(num,num_array,start,mid-1);
      } else { //第一次出现的位置
        return mid;
      }
    } else {
      //当前位置就是数子第一次出现的位置
      return mid;
    }
  }
  return nullptr;
}
int main()
{
  int *first_pos = nullptr;
  int num_array[] = {1,2,3,3,3,3,3,3,4,5,8};
  int num = 3;
  int *start = std::begin(num_array);
  int *end = std::end(num_array);
  first_pos = find_numbers_first_apperance(num,num_array,start,end);
  if (nullptr == first_pos) {
    cout<<"can't find the number"<<endl;
    return 0;
  }
  auto pos = first_pos - start;
  cout<<"first pos is " <<pos<<endl;
}

