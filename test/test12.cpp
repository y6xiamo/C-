#include <iostream>
using namespace std;
//求一个整数中1的个数
class Solution
{
public:
    //最让面试官满意的升级版
    //整数中有几个1就循环几次
    int NumberOf1ExP(int n)
    {
        //节省时间，提高了效率
        int count = 0;
        while(n)
        {
            count++;
            //一个数减去1，相当与把它从右开始数的第一个1变成了0，
            //把它后面的0全变成了1，它前面的保持不变
            //比如1100，减一变成了 1011
            //再将这个原本的整数与它减一后的数按位与，就把它最低位的1消掉了
            // 1100 & 1011 = 1000 
            // 所以这个整数有几个1就有几次这样的操作
            n = n & (n-1);
        }
        return count;

    }
    //为了避免负数出现死循环，将1左移依次和这个整数按位与
    int NumberOf1Ex(int n)
    {
        int flag = 1;
        int count = 0;
        for(int i = 0;i < 32;i++)
        {
            if(n & flag)
            {
                count++;
            }
            flag = flag << 1;
        }
        return count;
    }
    //将这个数 & 1，然后每次右移一位，
    //直到这个数变为0
    int  NumberOf1(int n)
    {
        int count = 0;
        for(int i = 0;i < 32;i++)
        {
            if(n & 1)
            {
                count++;

            }
            n = n >> 1;

        }
        return count;

    }

};

int main()
{
    Solution num;
    int ret = num.NumberOf1(-1);
    cout<<"ret = "<<ret<<endl;

    ret = num.NumberOf1(10);
    cout<<"ret = "<<ret<<endl;

    ret = num.NumberOf1(0);
    cout<<"ret = "<<ret<<endl;

    ret = num.NumberOf1Ex(-1);
    cout<<"ret = "<<ret<<endl;

    ret = num.NumberOf1Ex(10);
    cout<<"ret = "<<ret<<endl;

    ret = num.NumberOf1Ex(0);
    cout<<"ret = "<<ret<<endl;

    ret = num.NumberOf1ExP(-1);
    cout<<"ret = "<<ret<<endl;

    ret = num.NumberOf1ExP(10);
    cout<<"ret = "<<ret<<endl;

    ret = num.NumberOf1ExP(0);
    cout<<"ret = "<<ret<<endl;


}
