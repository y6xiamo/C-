#include <iostream>
class Solution {
public:
    void reOrderArray(vector<int> &array) {
        int i = 0;
        int j = 0;
        int n = array.size();
        while(i<n-1 && j<n-1)
        {
            i++;
            //找除第一个以外的奇数
            while(array[i]%2 == 0 && i<n)
            {
                i++;
            }
            if(i == n)
            {
                return ;
            }
            //将当前找到的奇数保存起来
            int temp = array[i];

            //找偶数
            while(j<n && array[j]%2 == 1)
            {
                j++;
            }
            int k;
            //如果奇数在偶数的后面，就交换
            //否则，不交换
            if(i > j)
            {
                //交换时，把偶数到奇数之间的所有元素都要顺次向后移动
                for(k=i;k>j;k--)
                {
                    array[k] = array[k-1];
                }
                array[j] = temp;
            }
        }
    }
};
