#include <iostream>
using namespace std;
class Solution
{
public:
    int Fibonacci(int n)
    {
        //对程序时间有限制时，用下面这种判断，循环也一样
        //不要写成if(n<=39 && n >= 0)
        if(n > 39 && n < 0)
        {
            return -1;
        }
        if(n == 0)
        {
            return 0;

        }
        else if(n == 1|| n ==2)
        {
            return 1;

        }
        else
        {
            return Fibonacci(n-1)+Fibonacci(n-2);
            //第n次总是等于 n-1次 + n-1

        }

      }
};

int main()
{
      Solution ret;
      int num = ret.Fibonacci(39);
      cout<<"num= "<<num<<endl;
    return 0;
}
