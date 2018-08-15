#include <iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
class Solution {
public:
    vector<string> Permutation(string str) {
        vector<string> charArray;

        if(str.size() > 9 || str.size() <= 0)
        {
            return charArray;

        }

        PermutationHelp(charArray,str,0);
        sort(charArray.begin(),charArray.end());
        return charArray; 

    }

    void PermutationHelp(vector<string>& array,string str,int begin)
    {
        if(begin == str.size() - 1)
        {
            array.push_back(str);

        }
        int i;
        for(i = begin;i <= str.size() - 1;i++)
        {
            if(i != begin && str[i] == str[begin])
            {
                continue;

            }
            swap(str[begin],str[i]);
            PermutationHelp(array,str,begin+1);
            swap(str[begin],str[i]);

        }

    }

};
