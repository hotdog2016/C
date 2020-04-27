/* 不用加减乘除做加法。
 * 用异或可以做无进位的加法
 * 用与操作然后左移可以做进位操作。
 */


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


int bit_add(int num1,int num2)
{
  int carry_bit = (num1 & num2) << 1;
  int no_carry_add_val = num1 ^ num2;
  int result = no_carry_add_val;
  //先检测是否有进位
  if (0 != carry_bit) {
    result = bit_add(carry_bit , no_carry_add_val);
  }
  return result;
}
 int main()
{
  int result = 0;
  result = bit_add(1,2);
  cout<<" result is "<<result<<endl;

}

