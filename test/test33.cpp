#include <iostream>
#include<vector>
using namespace std;
class Solution {
public:
    //找出第n个丑数
    int GetUglyNumber_Solution(int index) {
        if(index < 7)
        {
            //n小于7,对应的丑数为其下标
            return index;
        }
        //用来保存所有的丑数的数组
        vector<int> result(index);
        result[0] = 1;//第一个丑数是1
        int tmp2 = 0;
        int tmp3 = 0;
        int tmp5 = 0;
        for(int i = 1;i < index;++i)
        {
            result[i] = min(result[tmp2]* 2,min(result[tmp3]*3,result[tmp5]*5));
            if(result[i] == result[tmp2]*2)
            {
                tmp2++;

            }
            if(result[i] == result[tmp3]*3)
            {
                tmp3++;

            }
            if(result[i] == result[tmp5]*5)
            {
                tmp5++;

            }

        }
        return result[index-1];

    }

};
