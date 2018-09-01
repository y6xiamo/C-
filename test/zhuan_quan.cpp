#include <iostream>
class Solution {
public:
    //孩子转圈游戏，类似约瑟夫环
    int LastRemaining_Solution(int n, int m)
        {
            if(n < 1 || m < 1)
            {
                return -1;
                //非法输入
            }
            list<int> num;
            for(int i = 0;i < n;i++)
            {
                //将所有元素插入到链表中
                num.push_back(i);
            }

            list<int>::iterator cur = num.begin();
            while(num.size() > 1)
            {
                for(int i = 1;i < m;i++)
                {
                    //cur一直向后走，直到找到要删除的元素
                    cur++;
                    if(cur == num.end())
                    {
                        //如果走到尾，继续从头开始
                        cur = num.begin();
                    }
                }

                list<int>::iterator next = ++cur;
                if(next == num.end())
                {
                    //下一次要从删除元素的下一个开始走
                    next = num.begin();
                }
                --cur;
                num.erase(cur);
                cur = next;
            }
            return *cur;
            
            //第二种方法
            //运用数学公式
         //   int result = 0;
         //   for(int i =  2;i <= n;++i)
         //   {
         //       result = (result + m) % i;
         //   }
         //   return result;
        }
};
