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

    //输入一个二叉树，和数字，
    //求出该二叉树节点和为该值的所有路径
    //路径：从根结点到叶子节点
    //路径长的放前面
public:
    //下面这两个vector要定义成全局的
    //不然下一次递归两个值又都为空
    vector<vector<int> > list_buffer;
    //用于返回所有的路径
    vector<int> tmp;
    //保存一条路径
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {

        //树为空，非法输入
        if(root == NULL)
        {
            return list_buffer;

        }
        tmp.push_back(root->val);
        //将根节点插入到路径中
        if(root->val == expectNumber && root->left == NULL && root->right == NULL)
        {
            //如果该叶子节点的值刚好为此时要求的数
            //则找到了一条路径
            //将此路径插入到所有路径中
            list_buffer.push_back(tmp);

        } 
        if(expectNumber - root->val > 0)
        {
            //此时路径和小于要求的数
            //继续在其左右子树中查找
            FindPath(root->left,expectNumber - root->val); 
            FindPath(root->right,expectNumber - root->val); 

        }
        if(tmp.size()!= 0)
        {
            //此时已经找到叶子节点，但路径和不等于给的数
            //将tmp里面所有的元素出数组
            tmp.pop_back();

        }
        return list_buffer;


    }

};
