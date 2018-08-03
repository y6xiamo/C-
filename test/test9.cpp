#include <iostream>
using namespace std;
class Solution
{
    //下面用递归的解法，好多元素都重复了好几次
    //时间复杂度以n的指数倍递增
    //比如：我们要算第10次，必须知道第9次和第8次，知道第9次必须知道第8次和第7次
    
public:
    int Fibonacci(int n)
    {
        if(n < 0)
        {
            return -1;
        }
        if(n == 0||n == 1)
        {
            return n;
        }
        int result = 0;
        int pre = 1;
        int prepre = 0;
        for(int i = 2;i <= n;i++)
        {
            result = pre + prepre;
            prepre = pre;
            pre = result;
        }
        return result;
        
    }
//public:
//    int Fibonacci(int n)
//    {
//        //对程序时间有限制时，用下面这种判断，循环也一样
//        //不要写成if(n<=39 && n >= 0)
//        if(n > 39 && n < 0)
//        {
//            return -1;
//        }
//        if(n == 0)
//        {
//            return 0;
//
//        }
//        else if(n == 1|| n ==2)
//        {
//            return 1;
//
//        }
//        else
//        {
//            return Fibonacci(n-1)+Fibonacci(n-2);
//            //第n次总是等于 n-1次 + n-1
//
//        }
//
//      }
};

int main()
{
      Solution ret;
      int num = ret.Fibonacci(39);
      cout<<"num= "<<num<<endl;
    return 0;
}
