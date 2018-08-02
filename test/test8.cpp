#include <iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
        if(rotateArray.size() == 0)
        {
            return 0;

        }
        int length = rotateArray.size();
        int left = 0;
        int right = length - 1;
        int mid = 0;

        while(rotateArray[left] >= rotateArray[right])
        {
            if(right - left  == 1)
            {
                mid = left;
                break;

            }
            int mid = left + (right - left)/2;
            if(rotateArray[left] == rotateArray[right] && rotateArray[left] == rotateArray[mid])
            {
                rotateArray[mid] = rotate_same(rotateArray,left,right);
                break;

            }           
            if(rotateArray[mid] >= rotateArray[left])
            {
                left = mid;

            }
            if(rotateArray[mid] <= rotateArray[left])
            {
                right = mid;

            }


        }
        return rotateArray[mid];
        // return rotateArray[left]; 
        //     
    }
    int rotate_same(vector<int> rotateArray,int left,int right)
    {
        int result = rotateArray[left];
        for(int i = left + 1;i <= right;i++)
        {
            if(rotateArray[i] < result)
            {
                result = rotateArray[i];


            }

        }
        return result;

    }

};    
