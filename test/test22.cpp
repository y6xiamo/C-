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
class Solution {
public:
    vector<int> PrintFromTopToBottom(TreeNode* root) {
        vector<int> array;
        queue<TreeNode*> queue;
        if(root == NULL)
        {
            return array;

        }
        queue.push(root);
        while(!queue.empty())
        {
            root = queue.front();
            queue.pop();
            array.push_back(root->val);

            if(root->left != NULL)
            {
                queue.push(root->left);

            }
            if(root->right != NULL)
            {
                queue.push(root->right);

            }

        }
        return array;


    }

};


