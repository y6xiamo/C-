#include <iostream>
#include<vector>
#include<queue>
using namespace std;
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
        val(x), left(NULL), right(NULL) {

        }
};
//二叉树的层序遍历
class Solution {
public:
    //借助队列来实现层序遍历
    //先将头节点入队列，出栈，取出其左右子节点，分别入队列
    //然后出队列，又取其左右子节点，出队列，一直到队列为空
    //遍历完成
    vector<int> PrintFromTopToBottom(TreeNode* root) {
      //用于返回的vector
        vector<int> array;
        //辅助队列
        queue<TreeNode*> queue;
        if(root == NULL)
        {
            //如果头节点为空，返回一个空vector
            return array;
        }

        //头节点入队列
        queue.push(root);
        while(!queue.empty())
        {
            //取出头节点
            root = queue.front();
            //将其出队列
            queue.pop();
            //将其元素插入到用于返回的vector中
            array.push_back(root->val);

            if(root->left != NULL)
            {
                //左子树入队列
                queue.push(root->left);

            }
            if(root->right != NULL)
            {
                //右子树入队列
                queue.push(root->right);

            }

        }
        return array;


    }

};


