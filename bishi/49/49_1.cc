/* 寻找第n个丑数，当前位置的丑数值是前一个位置的×2,3,5,这三个数字中的
 * 最小值。
 * */
#include <iostream>
#include <memory>
#include <string>
using std::cout;
using std::cin;
using std::string;
using std::endl;
int min(int multiply2,int multiply3,int multiply5)
{
  if ( multiply2 < multiply3 ) {
    return multiply2 < multiply5 ? multiply2 : multiply5;
  } else {
    return multiply3 < multiply5 ? multiply3 : multiply5;
  }
}
int find_ugly(const int n)
{
  int *ugly_array = new int[n];
  ugly_array[0]=1;
  int *pos2 = ugly_array;
  int *pos3 = ugly_array;
  int *pos5 = ugly_array;
  int now_pos = 1;

  while(now_pos < n) {
    ugly_array[now_pos]=min(
        *pos2*2,
        *pos3*3, 
        *pos5*5);

    if (*pos2 * 2 <= ugly_array[now_pos]) {
      ++pos2;
    }
    if (*pos3 * 3 <= ugly_array[now_pos]) {
      ++pos3;
    }
    if (*pos5 * 5 <= ugly_array[now_pos]) {
      ++pos5;
    }
    ++now_pos;
  }
  
  cout <<"the "<<n<<"ugly is"<<ugly_array[n-1]<<endl;

  delete [] ugly_array;
  return 0;
}

int main()
{
  int a;

  cin>>a;

  find_ugly(a);
}

