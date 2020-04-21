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
char find_first_char_without_duplication(
    string str , 
    int* char_array)
{
  for (int i = 0; i < str.length(); i++) {
    ++char_array[str[i]];
  }
  for (int i = 0; i<256 ;++i) {
    if (char_array[i]==1) {
      char ch = 0;
      ch = i;
      cout<<ch<<endl;
      return ch;
    }
  }
  return '\0';
}

int main()
{
  string str("abcdac");
  int *char_array = new int[256];
  for (int i = 0; i < 250; ++i) {
    char_array[i]=0;
  }
  find_first_char_without_duplication(str,char_array);
}
