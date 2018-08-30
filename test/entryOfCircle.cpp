#include <iostream>

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};

class Solution {
public:
    ListNode* EntryNodeOfLoop(ListNode* pHead)
    {
        if(pHead == NULL)
        {
            //非法输入
            return NULL;
        }
        if(pHead->next == NULL)
        {
            //只有一个结点
            return NULL;
        }
        ListNode* fast = pHead;
        ListNode* slow = pHead;
        ListNode* meet = NULL;
        while(fast != NULL && fast->next != NULL)
        {
            //定义一个快慢指针
            //快指针一次走两步
            //慢指针一次走一步
            fast  = fast->next->next;
            slow = slow->next;
            if(fast == slow)
            {
                //两个指针相遇了
                break;
            }
        }
        if(fast == slow)
        {
            meet = slow;
            slow = pHead;
        }
        else
        {
            return NULL;
        }
        while(slow != meet)
        {
            //让快指针从相遇位置开始往后走、
            //慢指针从头开始往后走，两个相遇的地方就是环的入口点
            slow = slow->next;
            meet = meet->next;
        }
        return slow;
    }
};
int main()
{
    return 0;
}
