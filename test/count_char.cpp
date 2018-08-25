#include <iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int GetNumberOfK(vector<int> data ,int k) {
        if(data.size() == 0)
        {
            return 0;
        }
        int count = 0;
        for(size_t i = 0;i < data.size();i++)
        {
            if(data[i] == k)
            {
                count++;
            }
        }
        return count;
    }
};
