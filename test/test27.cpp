#include <iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
class Solution {
    //打印出字符串中字符的所有排列组合
public:
    vector<string> Permutation(string str) {
        vector<string> charArray;

        if(str.size() > 9 || str.size() <= 0)
        {
            //字符长度为0或者大于9，不满足条件
            return charArray;
        }

        //调用下面这个函数完成字符的所有组合
        PermutationHelp(charArray,str,0);
        //将组合好的字符排列组合重新进行排序
        sort(charArray.begin(),charArray.end());
        return charArray; 

    }

    //完成字符的所有组合
    void PermutationHelp(vector<string>& array,string str,int begin)
    {
        //如果只有一个字符
        //就把它直接插入到数组中
        if(begin == str.size() - 1)
        {
            array.push_back(str);

        }
        int i;
        for(i = begin;i <= str.size() - 1;i++)
        {
            //如果有重复的元素就跳过
            if(i != begin && str[i] == str[begin])
            {
                continue;
            }
            //交换第一个字符和它后面的其他字符
            swap(str[begin],str[i]);
            PermutationHelp(array,str,begin+1);
            swap(str[begin],str[i]);

        }

    }

};
