#include <iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
class Solution {
public:
    //把数组排成最小的数
    static bool cmp(int a,int b)
    {
        string A = to_string(a) + to_string(b);
        string B = to_string(b) + to_string(a);
        return A < B;
    }

    string PrintMinNumber(vector<int> numbers) {
        string result = "";//用来返回的字符串
        sort(numbers.begin(),numbers.end(),cmp);       
        for(int i = 0;i < numbers.size();i++)
        {
            //将数组中的所有元素拼接起来一起输出
            result += to_string(numbers[i]);

        }
        return result;
    }
};
