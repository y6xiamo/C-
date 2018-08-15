#include <iostream>
#include<vector>
using namespace std;
class Solution {
public:
    //查找一个数组中出现次数大于数组长度一半的那个数
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        if(numbers.size() == 0)
        {
            //空数组，出错，返回-1
            return -1;
        }
        size_t i = 0;
        //先保存数组中的第一个元素
        //将其出现次数设为1
        int result = numbers[0];
        int count = 1;
        for(i = 1;i < numbers.size();i++)
        {
            //遍历整个数组
            //如果当前元素的值和他上一个元素相等
            //则次数+1
            //否则-1
            //如果上一个元素次数已经减到0，
            //则保存当前元素，次数记为1
            //整个数组遍历完，保存的值即为数组中出现次数最多的元素
            if(numbers[i] == result)
            {
                count++;
            }
            else
            {
                count--;

            }
            if(count == 0)
            {
                result = numbers[i];
                count = 1;

            }

        }

        count = 0;
        //遍历整个数组
        //看这个元素出现次数是否超过数组长度的一半
        //超过则返回这个元素
        //否则没找到，返回0
        for(i = 0;i < numbers.size();i++)
        {
            if(result == numbers[i])
            {
                count++;
            }
        }
        if(count > numbers.size()>>1)
        {
            return result;

        }
        else
        {
            return 0;

        }
    }
};
