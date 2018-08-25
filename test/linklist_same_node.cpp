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
    //找两个链表的公共节点
    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2 ) {
        ListNode* cur1 = pHead1;
        ListNode* cur2 = pHead2;

        //先求出两个链表的长度
        int len1 = 0;
        while(cur1 != NULL)
        {
            len1++;
            cur1 = cur1->next;
        }
        int len2 = 0;
        while(cur2 != NULL)
        {
            len2++;
            cur2 = cur2->next;
        }

        cur1 = pHead1;
        cur2 = pHead2;
        //比较两个链表谁长，让长的链表先走比另一个短的链表多余的步数
        int len;
        if(len1 > len2)
        {
            len = len1 - len2;
            while(len--)
            {
                cur1 = cur1->next;
            }
        }
        else if(len1 < len2)
        {
            len = len2 - len1;
            while(len--)
            {
                cur2 = cur2->next;
            }
        }
        else{}

        //然后让两个链表一起走，当他两相遇时，就是公共节点
        while(cur1 != NULL && cur2 != NULL)
        {
            if(cur1 == cur2)
            {
                return cur1;
            }
            cur1 = cur1->next;
            cur2 = cur2->next;
        }
        return NULL;
    }
};
