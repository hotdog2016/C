extern "C"{
#include "../inc/list.h"
#include "../inc/tree.h"
}

#include <iostream>
#include <memory>
#include <string>
#include <iterator>
#include <vector>
#include <bitset>

using namespace std;

int find_number_appear_once(vector<int> int_vec)
{
  array<int,8> num_binary = {0};
  for (auto number : int_vec) {
    int bit_mask = 1;
    for (auto iter = num_binary.rbegin();iter != num_binary.rend();++iter) {
      if (bit_mask & number) {
        (*iter) += 1;
      }
      bit_mask = bit_mask << 1;
    }
  }
  int result = 0;
  for (auto member : num_binary) {
    result <<= 1;
    result += (member % 3);
  }
  return result;
}
int main()
{
  int number = 0;
  vector<int> int_vect = {2,4,2,2,3,4,3,5,3,4,};
  number = find_number_appear_once(int_vect);
  cout<<"appear once number is "<<number<<endl;
}

