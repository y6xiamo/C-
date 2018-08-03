#include <iostream>
class Solution
{
public:
    //青蛙跳台阶问题
    int jumpFloor(int number)
    {
        if(number > 0)
        { 

            //有一个台阶，只能跳一次，一种跳法
            //两级台阶，可以一次跳一个，也可以一次跳两个，两种跳法
            if(number == 1 || number == 2)
            {
                return number;

            }
            //n = 1 --> 1
            //n = 2 --> 2
            //n = 3 --> 3
            //n = 4 --> 5
            //n = 5 --> 8
            //n = 6 -->13
            //f(n) = f(n-1)+f(n-2)
            //第一级台阶的跳法决定了后面怎样跳
            if(number > 2)
            {
                return jumpFloor(number-1)+jumpFloor(number-2);

            }
        }
        return -1;
    }

};
