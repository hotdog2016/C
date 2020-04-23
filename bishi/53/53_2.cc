#include <iostream>
#include <iterator>
#include <array>

using namespace std;


int find_lack_number_core(int num_array[],int *start,int *end)
{
  int *mid = start + (end-start)/2;
  if (start == end) {
    if (*start != start - num_array) {
      //最后找到的这个位置是缺失的那个数字的位置
      return start - num_array;
    }
  }

  if (*mid == (mid - start)) {
    //在右侧
    return find_lack_number_core(num_array,mid+1,end);
  } else {
    //在左侧
    if (2 == *mid-*(mid - 1)) {
      //当前的坐标就是缺失的那个数字
      return mid-num_array;
    }
    return find_lack_number_core(num_array,start,mid);
  }
}

int find_lack_number(int num_array[],int array_len)
{
  int *start = num_array;
  int *end = num_array+array_len-1;
  if (*start != 0) {
    return 0;
  } else if (*end == end - num_array) {
    return -1;
  }
  return find_lack_number_core(num_array,start,end);
}

int main()
{
  int num_array[] = {0,1,2,3,4,5,7,8,9};
  int array_len = sizeof(num_array)/sizeof(int);
  int lack_num = -1;
  lack_num = find_lack_number(num_array,array_len);
  if (0 > lack_num) {
    cout<<"array invalid"<<endl;
    return 0;
  }
  cout<<"lack "<<lack_num<<endl;

}
