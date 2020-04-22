/* 逆序对，先用归并排序算法排序，然后将指针p1指向最后一个数字
 * 也是当前数组里最大的数字，和另一个数组合并之前先与他的最大
 * 值比较，如果大于他的最大值，那就大于这整个数组的所有数字，
 * 此时逆序对就加上数字的个数。
 * */
#include <iostream>
#include <memory>
#include <string>
#include <iterator>

using std::cout;
using std::cin;
using std::string;
using std::endl;
using std::begin;
using std::end;

void merge_array(int array[] , int array1[] ,int array1_len,
    int array2[],int array2_len , int array_tmp[])
{
  int i = 0,j = 0,k = 0;
  while (i < array1_len && j < array2_len) {
    array_tmp[k++] = array1[i] < array2[j] ? array1[i++] : array2[j++];
  }
  while (i < array1_len) {
    array_tmp[k++] = array1[i++];
  }
  while (j <array2_len) {
    array_tmp[k++] = array2[j++];
  }
}
/* 统计逆序对的过程：
 * 若array1为[7]  array2为[5],如果*p1>*p2 则找到一个逆序对。
 *            ^            ^
 *            p1           p2
 *
 * 若array1为[5,7]  array2为[4,6],如果*p1>*p2 则找到两个个逆序对。
 *              ^              ^
 *              p1             p2
 * 接着将p1向前移动，再和p2比较，如果*p2>*p1,则将p2向前移动一位。
 * */
inline void count_reverse_pairs(
    int *array1_end,
    int array1_len,
    int *array2_end,
    int array2_len,
    int &reverse_pairs_cnts)
{
  int *p1 = array1_end;
  int *p2 = array2_end;
  for (int i = array1_len; i >0 ; --i) {
    for (int j = array2_len; j >0 ; --j) {
      if (*p1 > *p2) {
        /* j表示当前p2指针处往前共有几个数字*/
        reverse_pairs_cnts += j;
        cout<<"reverse_pairs_cnts="<<reverse_pairs_cnts<<endl;
        break;
      }
      //当数组长度为1的时候，当前的end指针就是start指针，不能在--了。
      if (1==j) {
        break;
      }
      p2--;
    }
    //当数组长度为1的时候，当前的end指针就是start指针，不能在--了。
    if (1==i) {
      break;
    }
    p1--;
  }
}

/* 通过归并排序来寻找逆序对，有一数组[7,5,4,6],
 * 先将数组拆分成[7,5][4,6]
 * 再将数组拆分成[7][5][4][6]。
 * 比较[7][5],然后合并排序成[5,7],再比较[4][6]，然后合并排序成[4,6]。
 * 比较[5,7][4,6],比较完成后合并这两个数组为[4,5,6,7]。完成寻找逆序对。
 * */

void find_reverse_pairs_core(
    int array[] , 
    int *start,
    int *end,
    int array_tmp[],
    int &reverse_pairs_cnts)
{
  //将数组分成左右两部分左边为array1,右边为array2
  int *mid = start + (end-start)/2;
  int *array1_start = start;
  int *array1_end = mid;
  int *array2_start = mid+1;
  int *array2_end = end;
  int array1_len = array1_end - array1_start + 1; 
  int array2_len = array2_end - array2_start + 1; 

  if (start == end) {
    return;
  }

  //左半部分归并排序
  find_reverse_pairs_core(
      array ,
      array1_start ,
      array1_end ,
      array_tmp,
      reverse_pairs_cnts);
  //右半部分归并排序
  find_reverse_pairs_core(
      array ,
      array2_start ,
      array2_end ,
      array_tmp,
      reverse_pairs_cnts);
  //统计逆序对
  count_reverse_pairs(
      array1_end,
      array1_len,
      array2_end,
      array2_len,
      reverse_pairs_cnts);
  
  merge_array(
      array ,
      array1_start ,
      array1_len ,
      array2_start ,
      array2_len ,
      array_tmp);
  for (int i = 0; i < array1_len + array2_len; i++) {
    *start++ = array_tmp[i];
    cout<<array_tmp[i]<<endl;
  }
}
int find_reverse_pairs(int array[],int len , int array_tmp[])
{
  int *start = array;
  int *end   = array + len-1;
  int reverse_pairs_cnts = 0;
  find_reverse_pairs_core(array , start , end , array_tmp,reverse_pairs_cnts);
  for (int i = 0; i < len; i++) {
    cout<<array_tmp[i]<<" ";
  }
  return reverse_pairs_cnts;
}
int main()
{
  int array[]= {7,5,6,4};
  int x=0;
  const int array_len = end(array) - begin(array);
  int array_tmp[array_len];
  x = find_reverse_pairs(array , array_len ,array_tmp);
  cout<<"reverse_pairs_cnts = "<<x<<endl;
}

