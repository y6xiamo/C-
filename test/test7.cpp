#include <iostream>
#include<stack>
using namespace std;
class Solution
{
public:
    void push(int node) {
        int top;
        while(1)
        {
           top = stack2.top();
           stack1.push(top);
           stack2.pop();

        }
        stack1.push(node);


    }

    int pop() {
        int top;
        while(1)
        {
            top = stack1.top();
            stack2.push(top);
            stack1.pop();

        }
        int pop;
        if(!stack2.empty())
        {
            pop = stack2.top();
            stack2.pop();
            return pop;
        }
        else
        {
            return 0;
        }
    }

private:
    stack<int> stack1;
    stack<int> stack2;

};
int main()
{
    return 0;
}
