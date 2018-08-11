#include <stdio.h>

struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
        label(x), next(NULL), random(NULL) {
        }
};

//复杂链表的拷贝
class Solution {
public:
    RandomListNode* Clone(RandomListNode* pHead)
    {
        if(pHead == NULL)
        {
            //空链表
            return NULL;
        }

        //1.遍历原链表，给每个节点后插入新的节点
        RandomListNode* cur = pHead;

        for( ;cur != NULL;cur = cur->next->next )
        {
            RandomListNode* new_node = new RandomListNode(cur->label);
            new_node->next = cur->next;
            cur->next = new_node;

        }


        //2.维护新链表的random指针
        for(cur = pHead;cur != NULL;cur = cur->next->next)
        {
            RandomListNode* new_cur = cur->next;
            if(cur->random == NULL)
            {
                new_cur->random = NULL;
                continue;

            }
            new_cur->random = cur->random->next;

        }

        //3.将新链表从旧的链表中删除
        RandomListNode* new_head = NULL;
        RandomListNode* new_tail = NULL;
        RandomListNode* new_cur = NULL;
        for(cur = pHead;cur != NULL;cur = cur->next)
        {
            new_cur = cur->next;
            cur->next = new_cur->next;
            if(new_head == NULL)
            {
                new_head = new_tail = new_cur;

            }
            else
            {
                new_tail->next = new_cur;
                new_tail = new_tail->next;

            }

        }
        return new_head;
    }

};
