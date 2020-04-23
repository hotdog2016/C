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

int *find_numbers_first_apperance(int num,int *start,int *end)
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
    first_apperance = find_numbers_first_apperance(num,start,mid);
  } else if (*mid < num) {//在右半边
    first_apperance = find_numbers_first_apperance(num,mid+1,end);
  } else {
    if (mid != start) {
      //找该数字第一次出现的位置
      if (*(mid-1) == num) {
        first_apperance = find_numbers_first_apperance(num,start,mid-1);
      } else { //第一次出现的位置
        first_apperance = mid;
      }
    } else {
      //当前位置就是数子第一次出现的位置
      first_apperance = mid;
    }
  }
  return first_apperance;
}

int *find_last_apperance(int num,int *start,int *end)
{

  if (start == end) {
    if (*start == num) {
      return end;
    } else {
      return nullptr;
    }
  }
  int *last_apperance = nullptr;
  int *mid =  start+(end - start)/2;
  if (*mid > num)
  { //在左半边
    last_apperance = find_last_apperance(num,start,mid);
  } else if (*mid < num) {//在右半边
    last_apperance = find_last_apperance(num,mid+1,end);
  } else {
    if (mid != end) {
      //找该数字最后一次出现的位置
      if (*(mid+1) == num) {
        last_apperance = find_last_apperance(num,mid+1,end);
      } else { //最后一次出现的位置
        last_apperance = mid;
      }
    } else {
      //当前位置就是数子最后一次出现的位置
      last_apperance = mid;
    }
  }
  return last_apperance;
}

int find_numbers_apperant_counts(int num,int num_array[],const int array_len)
{
  int *first_pos  = nullptr;
  int *last_pos  = nullptr;
  int *start = num_array;
  int *end   = num_array + array_len;
  first_pos  = find_numbers_first_apperance(num,start,end);
  last_pos  = find_last_apperance(num,start,end);

  auto pos1 = first_pos - start;
  auto pos2 = last_pos - start;

  if (nullptr == first_pos) {
    cout<<"can't find the number"<<endl;
    return 0;
  }

  cout<<"first pos is " <<pos1<<endl;

  cout<<"last pos is " <<pos2<<endl;
  return last_pos-first_pos+1;
}
int main()
{
  const int array_len = 7;
  int num_array[array_len] = {1,2,3,3,4,4,5};
  int num = 4;
  int cnts = 0;
  cnts = find_numbers_apperant_counts(num,num_array,array_len);
  cout<<num<<" "<<"apperant"<<" "<<cnts<<endl;
}

