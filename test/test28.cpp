#include <iostream>
#include<vector>
using namespace std;
class Solution {
public:
    //查找一个数组中出现次数大于数组长度一半的那个数
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        if(numbers.size() == 0)
        {
            return -1;
        }
        size_t i = 0;
        int result = numbers[0];
        int count = 1;
        for(i = 1;i < numbers.size();i++)
        {
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
