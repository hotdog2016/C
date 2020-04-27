/*
 * A0,A1,A2,...,An-1
 * B0 = A1*A2*A3...An-1;
 * B1 = A0*A2*A3...An-1;
 * Ci = A0*A1...Ai-1;
 * Di = Ai+1*Ai+2...An-1;
 * Bi = Ci*Di;
 * */
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

vector<int> multiply_array(vector<int> A)
{
  int len = A.size();
  vector<int> c(len,1);
  vector<int> d(len,1);
  c[0] = 1;
  for (int i = 1;i < len;++i) {
    c[i] = c[i-1]*A[i-1];
    d[len-1-i] = d[len-i]*A[len-i];
  }

  vector<int> b(len,0);
  for (int i = 0;i < len;++i) {
    b[i] = c[i] * d[i];
  }
  return b;
}

int main()
{
  vector<int> test = {1,2,3,4,5,6};
  vector<int> b(test.size(),0);
  b = multiply_array(test);
  cout<<" B :";
  for (auto member : b) {
    cout<<member<<" ";
  }
}

