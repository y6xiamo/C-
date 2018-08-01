#include <stdio.h>
#include<stdlib.h>
typedef struct ListNode
{
    int m_nkey;
    struct ListNode* m_pnext;
}ListNode;
//创建节点
ListNode* CreateListNode(char value)
{
    ListNode* new_node = (ListNode*)malloc(sizeof(ListNode));
    new_node->m_nkey = value;
    new_node->m_pnext = NULL;
    return new_node;
}

void DestroyNode(ListNode* node)
{
    free(node);
}
//尾插
void PushBack(ListNode** pHead,char value)
{
    if(pHead == NULL)
    {
        return;//非法输入
    }
    if(*pHead == NULL)
    {
        *pHead = CreateListNode(value);
        return;
        //空链表
    }
    ListNode* cur = *pHead;
    while(cur->m_pnext != NULL)
    {
        cur = cur->m_pnext;
    }
    ListNode* new_node = CreateListNode(value);
    cur->m_pnext = new_node;
    return;   
}
void PrintReverse(ListNode* pHead)
{
    if(pHead != NULL)
    {
        if(pHead->m_pnext != NULL)
        {
            PrintReverse(pHead->m_pnext);
        }
        printf("%c",pHead->m_nkey);
    }  
    return;
}

void PrintListNode(ListNode* pHead)
{
    if(pHead == NULL)
    {
        return;
    }
    ListNode* cur = pHead;
    while(cur != NULL)
    {
        printf("%c",cur->m_nkey);
        cur = cur->m_pnext;
    }
    printf("\n");
}
int main()
{
    ListNode* pHead;
    PushBack(&pHead,'a');
    PushBack(&pHead,'b');
    PushBack(&pHead,'c');
    PushBack(&pHead,'d');
    PushBack(&pHead,'e');
    PrintListNode(pHead);

    PrintReverse(pHead);
    return 0;
}
