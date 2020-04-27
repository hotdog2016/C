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

void swap(int *num1,int *num2)
{
	int tmp;
	tmp = *num1;
	*num1 = *num2;
	*num2 = tmp;
}

void quick_sort(vector<int> &numbers,int length,int start,int end)
{
	//快速排序，首先随机找到一个值，然后把他放到最左边
	//结束条件
	if(start==end)
		return;
	int random = rand()%(end-start)+start;
	int p1=start-1;
	swap(&numbers[random],&numbers[end]);
	for(int i=start;i<end;i++)
	{
		if(numbers[i] < numbers[end])
		{
			//在遍历过程中让p1始终处于比所选数字小的数字的位置
			++p1;
			if(p1 != i)
				swap(&numbers[p1],&numbers[i]);
		}
	}
	++p1;//遍历完之后，将p1向右移动一次，这时p1指向的数字肯定是大于或等于所选的数字的数
	swap(&numbers[p1],&numbers[end]);//交换p1处和end处的数字，p1处的值左边都是小于他的数，右边都是大于他的
	if(start < p1) //对p1左边的数组进行位置调整
		quick_sort(numbers,length,start,p1-1);
	if(p1 < end) //对p1右边的数组进行调整
		quick_sort(numbers,length,p1+1,end);
}

bool check_is_straight(vector<int> deck)
{
  int zero_num = 0;

  //排序
  quick_sort(deck,deck.size(),0,deck.size()-1);

  //检测牌中大小王(0)的个数,一副牌最多有大小王各一张
  for (auto member : deck) {
    if (0==member) {
      ++zero_num;
    }
    if (2 < zero_num) {
      return false;
    }
  }

  //开始检测牌组是不是顺子
  for (auto iter = deck.begin();iter != deck.end();++iter) {
    //跳过0
    if (0 == *iter) {
      continue;
    }

    auto iter_small = iter;
    auto iter_big = iter+1;
    auto diff = *iter_big - *iter_small;

    //如果有对子，那就肯定不是顺子
    if (0 == diff) {
      return false;
    }

    /*检测大小王是否足够代替空缺的牌*/
    if (diff > 1 ) {
      if (diff-1 <= zero_num) {
        --zero_num;
      } else {
          cout<<"b"<<endl;
          return false;
        }
    } 

    //如果此时big已经是最后一个数字，那就把这个数组检测完了
    if (deck.end() == iter_big + 1) {
      break;
    }
  }
  return true;
}

int main()
{
  bool is_straight = false;
  vector<int> deck = {0,3,1,4,7};
  is_straight = check_is_straight(deck);
  cout<<is_straight<<endl;
}
