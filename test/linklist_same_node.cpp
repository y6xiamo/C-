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
    //找
    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2 ) {
        ListNode* cur1 = pHead1;
        ListNode* cur2 = pHead2;

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
