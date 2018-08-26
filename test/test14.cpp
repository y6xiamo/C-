#include <iostream>

 struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :val(x), next(NULL){
    }
};

//输入一个链表，求这个链表的倒数第k个节点
class Solution {
public:
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
        if(pListHead == NULL)
        {
            return NULL;//非法输入

        }
        unsigned int size = 0;//表示链表的长度
        ListNode* cur = pListHead;
        while(cur != NULL)
        {
            //从头到尾遍历整个链表，求出链表的长度
            size++;
            cur = cur->next;

        }
        if(k > size)
        {
            //非法输入
            return NULL;

        }
        //定义两个指针
        ListNode* fast = pListHead;
        ListNode* slow = pListHead;
        while(k--)
        {
            //先让快指针走K步
            fast = fast->next;

        }
        while(fast != NULL)
        {
            //然后两个指针一起走，fast不为空，
            //最后slow指向的即为倒数第k个节点
            slow = slow->next;
            fast = fast->next;

        }
        return slow;


    }

};
