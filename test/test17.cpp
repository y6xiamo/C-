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
    //有两个树，求B是不是A的子树
    //借助递归
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
    {
        bool result = false;
        if(pRoot1 != NULL && pRoot2 != NULL)
        {
            if(pRoot1->val == pRoot2->val)
            {
                //先判断两个树的根节点相不相等
                //如果相等，借助isSubtree判断他俩的子节点相不相等
                result = isSubtree(pRoot1,pRoot2);


            }
            //如果不相等，用A的左子树和B的根节点比较
            if(!result)
            {
                result = HasSubtree(pRoot1->left,pRoot2);

            }
            //如果上述两种情况都不相等，判断A的右子树和B的根节点相不相等
            if(!result)
            {
                result = HasSubtree(pRoot1->right,pRoot2);

            }


        }

        //找完了，都不想等，则B不是A的子树

        return result;

    }
    bool isSubtree(TreeNode* pRoot1,TreeNode* pRoot2)
    {
        if(pRoot2 == NULL)
        {
            //B为空，说明B已经遍历完了，则B是A的子树
            return true;

        }
        if(pRoot1 == NULL)
        {
            //A先为空，则不是
            return false;

        }
        if(pRoot1->val != pRoot2->val)
        {
            //如果两个节点值不相等，则返回
            return false;

        }
        //相等，继续遍历子节点
        return isSubtree(pRoot1->left,pRoot2->left)&&isSubtree(pRoot1->right,pRoot2->right);


    }

};
