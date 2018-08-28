#include <iostream>
#include<algorithm>
using namespace std;
class Solution {
public:
    //找一个数组中重复的第一个数字
    bool duplicate(int numbers[], int length, int* duplication) {
        if(numbers == NULL || duplication == NULL)
        {
            //非法输入
            return false;
        }

        //先将数组中所有的数进行排序
        //如果此时当前元素和他的下一个元素相等，
        //就说明找到了这个元素，直接返回
        sort(numbers,numbers + length);
        for(int i = 0;i < length;++i)
        {
            for(int j = i + 1;j < length;++j)
            {
                
                if(numbers[j] == numbers[i])
                {
                    *duplication = numbers[j];
                    return true;
                }
            }
        }
        return false;
    }
};
