#include <iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array) {
        if(array.size() == 0)
        {
            //空数组，直接返回
            return -1;
        }
        int length = array.size();
        int curSum = 0;
        //当前序列的最大值
        int maxSum = -1;
        //表示所有子序列中和最大的
        for(int i = 0;i < length;i++)
        {
            //扔掉和小于0的子序列
            //从当前位置重新开始计算
            if(curSum <= 0)
            {
                curSum = array[i];
            }
            else
            {
                //求连续子序列的和，将其保存起来
                curSum += array[i];
            }
            if(curSum > maxSum)
            {
                //将最大的和赋给maxSum
                maxSum = curSum;
            }
        }
        return maxSum;
    }
};
