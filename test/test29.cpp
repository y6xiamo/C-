#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
    //查找一个数组中最小的k个数
    //下面这种解法时间复杂度为O(n*logn)
    //改变了原有数组
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        vector<int> output;
        //非法输入
        if(k > input.size())
        {
            return output;
        }
        //先将这个数组排序
        //然后输入前k个数
        sort(input.begin(),input.end());
        for(int i = 0;i < k;i++)
        {
            output.push_back(input[i]);

        }
        return output;

    }

};
