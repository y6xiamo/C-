#include <iostream>
using namespace std;
//求一个整数中1的个数
class Solution
{
public:
    //为了避免负数出现死循环，将1左移依次和这个整数按位与
    int NumberOf1Ex(int n)
    {
        int flag = 1;
        int count = 0;
        for(int i = 0;i < 32;i++)
        {
            if(n & 1)
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



}
