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

/* i个骰子的情况下，点数和为j出现的概率
 * k为一个骰子所能出现的数字为1,2,3,4,5,6
 * 数组的下标代表点数和，下标对应的元素为
 * 该数字出现的次数。
 */

vector<int> probability(int dice_num)
{
  const int sum_counts = dice_num*6+1;
  vector<int> sum_array(sum_counts,0);
  for (int i = 1; i <= 6; ++i) {
    sum_array[i] = 1;
  }
  for (int i = 2;i <= dice_num;++i) {
    for (int j = i*6;j >= i ; --j) {
      //j必须大于n个骰子所能组成的最小值
      sum_array[j] = 0;
      for (int k = 6;k >= 1;--k) {
        if (j-k >= i-1) {
        /* 此时n-1个骰子的值,不能小于剩下骰子所能
         * 组成的最小值*/
          sum_array[j] += sum_array[j-k];
        }
      }
    }
  }
  return sum_array;
}
int main()
{
  int dice_num = 3;
  int sum = dice_num * 6;
  auto sum_array = probability(dice_num);
  for (int i = dice_num;i <= sum;++i) {
    cout<<sum_array[i]<<" ";
  }
}
