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
