#include <iostream>

//将一个二叉搜索树转换成一个排序的双向链表
 struct TreeNode {
  int val;
  struct TreeNode *left;
  struct TreeNode *right;
  TreeNode(int x) :
      val(x), left(NULL), right(NULL) {
      }
 };
class Solution {
public:
    TreeNode* Convert(TreeNode* pRootOfTree)
    {
        if(pRootOfTree == NULL)
        {
            return NULL;

        }
        TreeNode* head = NULL;
        ConvertList(pRootOfTree,head);
        //遍历左子树，找到左子树中的叶子节点，它就是排序链表的头结点
        TreeNode* cur = pRootOfTree;
        while(cur->left != NULL)
        {
            cur = cur->left;

        }

        return cur;

    }
    //这个函数用来完成递归
    void ConvertList(TreeNode* root,TreeNode*& head)
    {
        if(root == NULL)
        {
            //空树
            return;
        }
        //找左子树
        ConvertList(root->left,head);
        //构建双向链表
        //要是有序的双向链表
        //左子树的右叶子节点的下一个应该接根节点
        //而根节点要接右子树的第一个左节点
        root->left = head;
        if(head != NULL)
        {
            head->right = root;

        }
        head = root;
        //找右子树
        ConvertList(root->right,head);

    }

};
