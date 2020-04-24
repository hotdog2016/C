extern "C"{
#include "../inc/list.h"
#include "../inc/tree.h"
}

/* 查找数组中没有重复过的数字
 * 按照顺序异或数组中的每个值
 * 然后得到异或的结果
 * */
#include <iostream>
#include <memory>
#include <string>
#include <iterator>
#include <vector>
#include <bitset>

using namespace std;

int find_first_1_bit(int num)
{
  for (int i = 0; i < 8*sizeof(int); i++) {
    if (num & 1) {
      return 1<<i;
    }
  }
  return 0;
}

int find_number_without_deplication(vector<int> num_vector)
{
  int tmp = 0;
  for (auto i:num_vector) {
    tmp ^= i;
  }
  vector<int> num_vector1;
  vector<int> num_vector2;

  cout<<"before tmp "<<(bitset<8>)tmp<<endl;
  tmp = find_first_1_bit(tmp);
  cout<<"after tmp "<<(bitset<8>)tmp<<endl;

  for (auto i:num_vector) {
    if (tmp & i) {
      num_vector1.push_back(i);
    } else {
      num_vector2.push_back(i);
    }
  }

  tmp = 0;
  for (auto i:num_vector1) {
    tmp ^= i;
  }
  cout<<"no duplication number is "<<tmp<<endl;
  tmp = 0;
  for (auto i:num_vector2) {
    tmp ^= i;
  }
  cout<<"no duplication number is "<<tmp<<endl;
  return 0;
}
int main()
{
  vector<int> num_vector = {1,2,10,3,9,3,2,5,5,1};
  find_number_without_deplication(num_vector);
}

