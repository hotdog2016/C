#include <iostream>
#include <iterator>
#include <array>

using namespace std;


int find_lack_number_core(int num_array[],int *start,int *end)
{
  int *mid = start + (end-start)/2;


  if(*mid == mid - num_array) {
    return *mid;
  }

  if (*mid > mid - num_array) {
    /* 当前的数字大于他的下标，由于是递增数组后面所有的元素都
     * 会大于他的下标，只搜索前半部分
     */
    return find_lack_number_core(num_array,start,mid);
  } else {
    /* 当前的数字小于他的下标，那么前面所有的数字都小于他的下标
    *可以只搜索后半部分
    */
    return find_lack_number_core(num_array,mid+1,end);
  }
}

int find_lack_number(int num_array[],int array_len)
{
  int *start = num_array;
  int *end = num_array+array_len-1;
  return find_lack_number_core(num_array,start,end);
}

int main()
{
  int num_array[] = {-1,0,1,2,4,5,6,7};
  int array_len = sizeof(num_array)/sizeof(int);
  int lack_num = -1;
  lack_num = find_lack_number(num_array,array_len);
  if (0 > lack_num) {
    cout<<"array invalid"<<endl;
    return 0;
  }
  cout<<"lack "<<lack_num<<endl;

}
