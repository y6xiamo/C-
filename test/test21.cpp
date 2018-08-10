#include <iostream>
#include<vector>
#include<stack>
using namespace std;
class Solution {
public:
    //判断一个序列是不是栈的弹出顺序
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        //入栈序列或者出栈序列有一个为空，则出错
        //入栈序列和出栈序列不相等，出错
        if(pushV.size() != popV.size() || pushV.size() == 0 || popV.size() == 0)
        {
            return false;

        }
        //借助栈
        stack<int> stack;
        //指向出栈序列，用来遍历
        int popIndex = 0;

        //用来遍历入栈序列
        size_t i = 0;
        for( ;i < pushV.size();i++ )
        {
            //将入栈序列依次入栈
            stack.push(pushV[i]);

            //比较栈顶元素和出栈序列相不相等
            //不相等，继续入栈
            //相等，出栈
            while(!stack.empty() && stack.top() == popV[popIndex])
            {
                stack.pop();
                
                //更新下标
                popIndex++;
            }
        }

        //如果栈为空，说明出栈序列是入栈序列地弹出顺序
        //否则不是
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
