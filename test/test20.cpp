#include <iostream>
#include<stack>
using namespace std;
class Solution {
    //实现一个最小栈，取最小元素的时间复杂度为O(1)
public:
    //定义两个栈，一个用来存数据，一个用来存最小元素
    void push(int value) {
        //先将元素存入数据栈
        data_stack.push(value);

        //如果最小栈为空，直接将该元素插入
        if(min_stack.empty())
        {
            min_stack.push(value);

        }
        //如果最小栈的栈顶元素大于要插入的元素
        //则把该元素入栈
        if(min_stack.top() > value)
        {
            min_stack.push(value);

        }


    }
    void pop() {
        if(data_stack.top() == min_stack.top())
        {
            min_stack.pop();

        }
        data_stack.pop();

    }

    int top() {
        /*   if(min_stack.size() == 0)
         *   {
         *           return -1;
         *   }
         *                                       */
        //   min_stack.pop();
           int ret =  data_stack.top();
           return ret;
       }

        int min() {
            int min =  min_stack.top();
            return min;
        }
private:
    stack<int> min_stack;
    stack<int> data_stack;

};
