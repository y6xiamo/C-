#include <iostream>
#include<vector> 
using namespace std;

class Solution {
public:
    //和为正数的连续数列
    vector<vector<int> > FindContinuousSequence(int sum) {
        vector<vector<int> > result;//用来保存所有的序列
        vector<int> tmp;//用来保存找出来的一个序列
       
        if(sum == 0)
            return result;//和为0，返回空
       
        int i = 1;
        int add = sum;
        //i用来定位，j用来遍历后续的序列，查找和为sum的
        //i只需走到sum的一半即可,因为sum的一半加上下一个数字已经大于sum
        //j每向后走一步，和add == add-j,
        //当add减到0,说明找到一个序列和为sum，将其插入到result中
        //然后清空tmp，恢复add，并且跳出循环，从下一个定位的i开始
        //如果add小于0,说明当前序列不满足要求，清空tmp，恢复add，重新从定位数字i开始遍历计算
        //重复上述步骤,直到找到所有和为sum的序列
        
        for(;i <= sum/2;++i)
        {
            for(int j = i;j < sum ;++j)
            {
                tmp.push_back(j);
                add -= j;
                if(add == 0)
                {
                    result.push_back(tmp);
                    tmp.erase(tmp.begin(),tmp.end());
                    add = sum;
                    break;
                }
                if(add < 0)
                {
                    add = sum;
                    tmp.erase(tmp.begin(),tmp.end());
                    break;
                }
            }
        }
        return result;
    }
};
int main()
{
    Solution s1;

    vector<vector<int> > ret = s1.FindContinuousSequence(9);
    for(size_t i = 0;i < ret.size();++i)
    {
        for(size_t j = 0;j < ret[i].size();++j)
        {
            cout<<ret[i][j];
        }
        cout<<endl;
    }
    return 0;
}
