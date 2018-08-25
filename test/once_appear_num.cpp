#include <iostream>
class Solution {
public:
    void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) {
       // vector<int> ret;
       // sort(data.begin(),data.end());
       // int i = 0;
       // while(i < data.size())
       // {
       //     if(data[i] != data[i+1])
       //     {
       //         ret.push_back(data[i]);
       //         i++;
       //     }
       //     else
       //     {
       //         i += 2;
       //     }
       // }
       // *num1 = ret[0];
       // *num2 = ret[1];
        
        vector<int> data1;
        vector<int> data2;
        int tmp = 0;
        int i = 0;
        for(i = 0;i < data.size();i++)
        {
            tmp ^= data[i];

        }
        int flag = 1;
        while(tmp)
        {
            if((tmp & 1) != 1)
            {
                tmp = tmp >> 1;
                flag *= 2;

            }
            else
            {
                break;

            }

        }
        for(i = 0; i < data.size();i++)
        {
            if((data[i] & flag) == flag)
            {
                data1.push_back(data[i]);


            }
            else
            {
                data2.push_back(data[i]);

            }

        }
        for(i = 0;i < data1.size();i++)
        {
            *num1 ^= data1[i];

        }
        for(i = 0;i <data2.size();i++)
        {
            *num2 ^= data2[i];

        }
    }
};
