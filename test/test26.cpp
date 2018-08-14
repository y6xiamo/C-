#include <iostream>

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
        TreeNode* cur = pRootOfTree;
        while(cur->left != NULL)
        {
            cur = cur->left;

        }

        return cur;

    }
    void ConvertList(TreeNode* root,TreeNode*& head)
    {
        if(root == NULL)
        {
            return;

        }
        ConvertList(root->left,head);
        root->left = head;
        if(head != NULL)
        {
            head->right = root;

        }
        head = root;
        ConvertList(root->right,head);

    }

};
