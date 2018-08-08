#include <iostream>

 struct ListNode {
      int val;
      struct ListNode *next;
      ListNode(int x) :
      val(x), next(NULL) {
      }
 };

//合并两个已经排序的链表
class Solution {
public:
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {

        //新创建一个头节点，谁的头节点元素小，就插入到谁的头上
        //head用来定位合并后的链表的头
        ListNode* head = new ListNode(0);

        //用来遍历这两个链表
        ListNode* temp = head;
        while(pHead1 != NULL && pHead2 != NULL)
        {
            if(pHead1->val < pHead2->val)
            {
                temp->next = pHead1;
                temp = pHead1;
                pHead1 = pHead1->next;

            }
            else
            {
                temp->next = pHead2;

                temp = pHead2;
                pHead2 = pHead2->next;

            }

        }
        if(pHead1 != NULL)
        {
            temp->next = pHead1;

        }
        if(pHead2 != NULL)
        {
            temp->next = pHead2;

        }
        temp = head->next;
        delete head;
        return temp;


    }

};
