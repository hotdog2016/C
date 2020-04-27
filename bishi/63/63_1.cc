//股票的最大收益
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

int count_max_lucare(vector<int> price_array)
{
  int min = *price_array.begin();
  int max_lucare = 0;
  for (auto iter = price_array.begin() + 1;
      iter != price_array.end();
      ++iter) {
    int diff = *iter - min;
    if (diff > max_lucare) {
      max_lucare = diff;
    }
    min = *iter < min ? *iter : min;
  }
  return max_lucare;
}

int main()
{
  int max_lucare = 0;
  vector<int> price_array = {3,5,2,7,10,19,1};
  max_lucare = count_max_lucare(price_array);
  cout<<"max lucare = "<<max_lucare<<endl;
  
}


