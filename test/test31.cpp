#include <iostream>
class Solution {
public:
    //第一种做法：时间复杂度为o(n * logn)
    int NumberOf1Between1AndN_Solution(int n)
    {
        int number = 0;
        for(int i = 1;i <= n;i++)
        {
            //总共的1的个数等于每个数字中1的个数相加
            number += numberOf1(i);
                                
        }
        return number;
    }

    //这个函数用来求每一个数字中1的个数
    int numberOf1(int n)
    {
        int number = 0;
        while(n)
        {
            if(n % 10 == 1)
            {
                number++;
            }
            n = n / 10;
        }
        return number;
    }
};
