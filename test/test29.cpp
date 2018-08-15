#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
    //查找一个数组中最小的k个数
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        vector<int> output;
        if(k > input.size())
        {
            return output;

        }
        sort(input.begin(),input.end());
        for(int i = 0;i < k;i++)
        {
            output.push_back(input[i]);

        }
        return output;

    }

};
