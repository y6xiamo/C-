#include <iostream>
class Solution {
    //矩形覆盖
    //递归的思想。类似于斐波那契序列
    //n个的方案为f(n)
    //第一个竖着放还剩n-1个，方案数为f(n-1)
    //第一个横着放，那他下面的也必须横着放，还剩n-2个，方案数为f(n-2);
    //n个的方案数为f(n) = f(n-1) + f(n -2)
public:
    int rectCover(int number) {
        if(number < 0)
        {
            return 0;

        }
        else if(number == 1 || number == 2)
        {
            return number;

        }
        else
        {
            return rectCover(number -1) + rectCover(number - 2);


        }



    }

};
