#include <iostream>
#include<vector>
using namespace std;
class Solution {
public:
    //查找和为sum的两个数
    vector<int> FindNumbersWithSum(vector<int> array,int sum) {
        vector<int> result;
        //num1，num2用来标记这两个数字
        int num1 = 0;
        int num2 = 0;
        int mul = 1;//用来表示这两个数的乘积
        int min_mul = 1;//用来表示最小的乘积
        int flag = 1;//标志位，用来表示第一次的乘积
        for(size_t i = 0;i < array.size();++i)
        {
            for(size_t j = i;j < array.size();++j)
            {
                //找到了这两个数
                if(array[j] == sum - array[i])
                {
                    mul = array[i] * array[j];
                    if(flag == 1)
                    {
                        //如果是第一个满足条件的，就把他们的乘积赋给最小乘积
                        min_mul = mul;
                    }
                    flag++;
                    if(mul <= min_mul)
                    {
                        //如果乘积小于最小乘积，就说明是要找的数
                        //不小于的话，直接退出
                        num1 = array[i];
                        num2 = array[j];
                    }
                    else
                    {
                        break;
                    }
                }
            }
        }
        //如果找到这两个数，返回这两个数
        //否则返回空数组
        if(num1 != 0 && num2 != 0)
        {
            result.push_back(num1);
            result.push_back(num2);
        }
        return result;
    }
};
