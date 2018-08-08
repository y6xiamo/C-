#include <iostream>
using namespace std;
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
    //求树的镜像
    void Mirror(TreeNode *pRoot) {
        if(pRoot == NULL)
        {
            return;

        }
        //如果树不为空，交换其左右子树
        swap(pRoot->left,pRoot->right);
        if(pRoot->left)
        {
            Mirror(pRoot->left);

        }
        if(pRoot->right)
        {
            Mirror(pRoot->right);

        }

    }

};
