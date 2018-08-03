#include <iostream>
using namespace std;
class Solution
{
public:
    //变态跳台阶，一次可以跳1级、2级、3级...n级
    //f(n) = f(n-1) + f(n-2) + f(n-3) + f(n -4)+ ...+f(n -n)
    //     = f(0) + f(1) + f(2) + (3) + ... +f(n-2) + f(n-1)
    //     = f(n-1) + f(n-1)
    //     =2 * f(n-1)
    int jumpFloorII(int n)
    {
        if(n < 0)
        {
            return -1;
        }
        if(n == 1)
        {
            return 1;
        }
        return 2*jumpFloorII(n-1);
    }

    int jumpFloor(int n)
    {
        if(n < 0)
        {
            return -1;
        }
        if(n == 1 || n == 2)
        {
            return n;
        }
        int result = 0;
        int pre = 2;
        int prepre = 1;
        for(int i = 3;i <= n;i++)
        {
            result = pre + prepre;
            prepre = pre;
            pre = result;
        }
        return result;

    }
    //青蛙跳台阶问题
//    int jumpFloor(int number)
//    {
//        if(number > 0)
//        { 
//
//            //有一个台阶，只能跳一次，一种跳法
//            //两级台阶，可以一次跳一个，也可以一次跳两个，两种跳法
//            if(number == 1 || number == 2)
//            {
//                return number;
//
//            }
//            //n = 1 --> 1
//            //n = 2 --> 2
//            //n = 3 --> 3
//            //n = 4 --> 5
//            //n = 5 --> 8
//            //n = 6 -->13
//            //f(n) = f(n-1)+f(n-2)
//            //第一级台阶的跳法决定了后面怎样跳
//            if(number > 2)
//            {
//                return jumpFloor(number-1)+jumpFloor(number-2);
//
//            }
//        }
//        return -1;
//    }

};
int main()
{
    Solution number;
    int ret = 0;
    ret = number.jumpFloor(4);
    cout<<"ret = "<<ret<<endl;

    ret = number.jumpFloorII(4);
    cout<<"ret = "<<ret<<endl;


    return 0;
}
