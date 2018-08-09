#include <iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> printMatrix(vector<vector<int> > matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        vector<int> result;
        if(row == 0 || col == 0)
        {
            return result;

        }

        int left = 0;
        int right = col - 1;
        int up = 0;
        int down = row - 1;
        while(left < right && up < down)
        {
            int i = 0;
            for(i = left ;i <= right;i++)
            {
                result.push_back(matrix[up][i]);

            }
            if(up < down)
            {
                for(i = up + 1;i <= down;i++)
                {
                    result.push_back(matrix[i][right]);

                }
            }
            if(up < down && left < right)
            {
                for(i = right - 1;i >= left;i--)
                {
                    result.push_back(matrix[down][i]);

                }               

            }
            if(up < down && left < right)
            {
                for(i = down -1;i > left;i--)
                {
                    result.push_back(matrix[i][left]);

                }

            }
            left++;
            right--;
            up++;
            down--;
        }
        return result;


    }

};
