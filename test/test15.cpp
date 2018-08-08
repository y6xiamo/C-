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
       //反转链表
        ListNode* ReverseList(ListNode* pHead) {
        ListNode* cur = pHead;
        ListNode* pre = NULL;
        while(cur != NULL)
        {
            ListNode* next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;

        }
        return pre;


    }

};
