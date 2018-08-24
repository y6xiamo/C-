#include <iostream>
#include<string>
using namespace std;
class Solution {
public:
    //第一个只出现一次的字符
    int FirstNotRepeatingChar(string str) {
        if(str.size() == 0)
        {
            return -1;
        }
        //字符串为空
        int start = 0;
        int len = str.size();
        //字符串长度
        //定义两层循环
        //第一层循环定位每个元素，
        //第二层循环，遍历每一个元素都要和这个定位元素进行比较（包括自身）
        //相等，count++，count==1说明只出现了一次，返回此时的下标
        //count > 1说明此时已经有元素和当前定位元素相等，跳出循环
        for( ; start < len ; start++ )
        {
            int cur = 0;
            int count = 0;
            for( ;cur < len ; cur++ )
            {
                if(str[cur] == str[start])
                {
                    count++;
                    if(count > 1)
                    {
                        break;
                    }
                }
            }
            if(count == 1)
            {
                return start;
            }
        }
        return -1;
    }
};
