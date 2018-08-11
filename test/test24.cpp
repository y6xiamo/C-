#include <iostream>
#include<vector>
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
    vector<vector<int> > list_buffer;
    vector<int> tmp;
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {

        if(root == NULL)
        {
            return list_buffer;

        }
        tmp.push_back(root->val);
        if(root->val == expectNumber && root->left == NULL && root->right == NULL)
        {
            list_buffer.push_back(tmp);

        } 
        if(expectNumber - root->val > 0)
        {
            FindPath(root->left,expectNumber - root->val); 
            FindPath(root->right,expectNumber - root->val); 

        }
        if(tmp.size()!= 0)
        {
            tmp.pop_back();

        }
        return list_buffer;


    }

};
