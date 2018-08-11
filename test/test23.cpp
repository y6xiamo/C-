#include <iostream>
#include<vector>
using namespace std;
class Solution {
    //判断一个数组是不是某个二叉搜索树的后序遍历结果
public:
    bool VerifySquenceOfBST(vector<int> sequence) {
        //借用下面这个函数完成递归
        return  _VerifySquenceOfBST(sequence,0,sequence.size()-1);

    }
    bool  _VerifySquenceOfBST(vector<int>sequence,int begin,int end)
    {
        if(sequence.empty() || begin > end)
        {
            //数组为空，无效区间都为非法输入
            return false;
        }

        //后序遍历，数组最后一个元素为根节点
        //二叉搜索树的特点：
        //所有的左子树小于根节点，所有的右子树大于根节点
        int root = sequence[end];
        int i = 0;
        for(i = begin;i < end;i++)
        {
            //找到右子树节点
            if(sequence[i] > root)
            {
                break;

            }

        }
        //如果右子树中有一个节点大于小于根节点
        //则错误
        int j = i;
        for( ;j < end;j++ )
        {
            if(sequence[j] < root)
            {
                return false;

            }

        }
        bool left = true;
        if(i > begin)
        {
            //递归遍历左子树
            left = _VerifySquenceOfBST(sequence,begin,i-1);

        }

        bool right = true;
        if(i < end -1)
        {
            //递归遍历右子树
            right = _VerifySquenceOfBST(sequence,i,end-1);

        }

        return left && right;

    }

};
