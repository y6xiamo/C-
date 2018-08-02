#include <iostream>
#include<stdlib.h>
#include<vector>
using namespace std;

 //Definition for binary tree
typedef struct TreeNode {
         int val;
         TreeNode *left;
         TreeNode *right;
         TreeNode(int x) : val(x), left(NULL), right(NULL) {}
     }TreeNode;

class Solution {
public:
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
        int index_pre = 0;
        int left_index_vin = 0;
        int right_index_vin = vin.size();
        int length = pre.size();
        return _reConstructBinaryTree(pre,&index_pre,vin,&left_index_vin,&right_index_vin,length);

    }
    TreeNode* CreateNode(int val)
    {
        TreeNode* new_node = (TreeNode*)malloc(sizeof(TreeNode));
        new_node->val = val;
        new_node->left = NULL;
        new_node->right = NULL;
        return new_node;
    }
    void DestroyNode(TreeNode* node)
    {
        free(node);
    }
    TreeNode* _reConstructBinaryTree(vector<int> pre,int* index_pre,vector<int> vin,int* left_index_vin,int* right_index_vin,int length)
    {
        if(index_pre == NULL)
        {
            return NULL;

        }
        if(*index_pre >= length)
        {
            return NULL;

        }
        if(*left_index_vin >= *right_index_vin)
        {
            return NULL;

        }
        TreeNode* root = CreateNode(pre[*index_pre]);
        //查找根节点在中序数组中的位置
        int root_in_vin_index = 0;
        while(root_in_vin_index < length)
        {
            if(vin[root_in_vin_index] == root->val)
            {
                break;
            }
            root_in_vin_index++;
        }
        ++(*index_pre);
        root->left = _reConstructBinaryTree(pre,index_pre,vin,left_index_vin,&root_in_vin_index,length);
        ++root_in_vin_index;
        root->right = _reConstructBinaryTree(pre,index_pre,vin,&root_in_vin_index,right_index_vin,length);
        return root;
    }
};
int main()
{
    return 0;
}
