#include <iostream>
#include<stack>
using namespace std;
class Solution {
public:
    void push(int value) {
        data_stack.push(value);
        if(min_stack.empty())
        {
            min_stack.push(value);

        }
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
