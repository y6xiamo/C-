#include <iostream>
#include<vector>
#include<stack>
using namespace std;
class Solution {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        if(pushV.size() != popV.size() || pushV.size() == 0 || popV.size() == 0)
        {
            return false;

        }
        stack<int> stack;
        int popIndex = 0;
        size_t i = 0;
        for( ;i < pushV.size();i++ )
        {
            stack.push(pushV[i]);

            while(!stack.empty() && stack.top() == popV[popIndex])
            {
                stack.pop();
                popIndex++;

            }

        }

        if(stack.empty())
        {
            return true;

        }
        else
        {
            return false;

        }


    }

}; 
